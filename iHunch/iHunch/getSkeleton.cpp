#include "alphapose.h"
#include "iHunch.h"
#include "setupPose.h"

#ifdef UNICODE
#define GetCurrentDirectory  GetCurrentDirectoryW
#else
#define GetCurrentDirectory  GetCurrentDirectoryA
#endif // !UNICODE
#define PIPE_NAME   "\\\\.\\pipe\\test_pipe"

using namespace std;

extern iHunch* w;

PROCESS_INFORMATION ProcessInfo; //프로세스 정보
std::mutex mtx1, mtx2; //뮤텍스 변수
bool endSignal; //종료 sign
bool imported; //import 체크
bool measureStartBtn; //초기 자세 측정 버튼
bool isError = false;

queue<Points> poseData; //좌표값 데이터
double stdPoseRate;    //기준이 되는 초기자세 비율
Points stdPosePoints;

RecordTime recordedTime;    //자세와 시간기록
double healthySec, unhealthySec; //좋은, 나쁜자세 총 시간
int alarmInterval; //재알람 간격
int alarmStart; //안 좋은 자세 n초 지속시 알람
int fixDegree; //교정강도

int startFix(void)
{
    //프로세스 관련
    STARTUPINFO StartupInfo = { 0 };
    StartupInfo.cb = sizeof(STARTUPINFO);

    //파이프 관련
    HANDLE hNamePipe;
    TCHAR pipe_name[] = _T(PIPE_NAME);

    //파이프 생성
    hNamePipe = CreateNamedPipe(
        pipe_name,
        PIPE_ACCESS_DUPLEX,
        PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT,
        PIPE_UNLIMITED_INSTANCES,
        0,
        0,
        20000,
        NULL
    );

    if (hNamePipe == INVALID_HANDLE_VALUE)
    {
        printf("CreateNamePipe error! \n");
        return -1;
    }

    //alphapose 실행할 프로세스 경로 가져오기
    TCHAR path[128]; //유니코드 문자열
    char cpath[128];
    GetCurrentDirectory(128, path); //cwd경로
    WideCharToMultiByte(CP_ACP, 0, path, 128, cpath, 128, NULL, NULL); //TCHAR to char
    editChildProccessPath(cpath); //실행파일 경로로 만듦
    MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, cpath, 128, path, 128); //char to TCHAR

    //자식 프로세스 생성
    CreateProcess(
        path, //경로
        NULL,
        NULL, NULL,
        FALSE, //부모프로세스 중 상속 가능한 핸들 상속
        0,
        NULL, NULL,
        &StartupInfo,
        &ProcessInfo //프로세스 정보
    );

    //파이프 연결
    while (1)
    {
        //생성한 Named Pipe의 핸들을 누군가 얻어갈 때까지 대기  
        if (!(ConnectNamedPipe(hNamePipe, NULL))) {
            CloseHandle(hNamePipe);
            return -1;
        }
        else {
            if (ConnectClient(hNamePipe) == -1)
                break;
        }
    }

    DisconnectNamedPipe(hNamePipe);
    CloseHandle(hNamePipe);
    return 0;
}

//path를 alphapose 실행할 프로세스의 실행파일 경로로 만듦
void editChildProccessPath(char* path)
{
    int len = strlen(path) - 1;
    char* pp = path + len;
    while (*pp-- != '\\');
    strcpy(pp + 1, "\\x64\\Debug\\caller.exe");
}

int ConnectClient(HANDLE hNamePipe)
{
    TCHAR Message[100];
    char tmp[100];
    DWORD recvSize;

    Points cur;
    while (1) {
        checkEndSignal(false);
        if (endSignal) break;
        
        int n, x, y;
        //recvSize -> NULL 포함한 바이트 수
        ReadFile(
            hNamePipe,
            Message,
            sizeof(Message) - sizeof(TCHAR) * 1,
            &recvSize,
            NULL
        );

        _stscanf(Message, _T("%d %d %d"), &n, &x, &y);
        if (n == -2) continue;  //모듈 import 완료 메시지
        if (n == -1 && x == -1 && y == -1) {
            operatorQueue(&cur, 0);
            cur = Points();
        }
        else {
            switch (n) {
            case 0:
                cur.Nose.x = x;
                cur.Nose.y = y;
                break;
            case 1:
                cur.lEye.x = x;
                cur.lEye.y = y;
                break;
            case 2:
                cur.rEye.x = x;
                cur.rEye.y = y;
                break;
            case 3:
                cur.lEar.x = x;
                cur.lEar.y = y;
                break;
            case 4:
                cur.rEar.x = x;
                cur.rEar.y = y;
                break;
            case 5:
                cur.lShoulder.x = x;
                cur.lShoulder.y = y;
                break;
            case 6:
                cur.rShoulder.x = x;
                cur.rShoulder.y = y;
                break;
            case 17:
                cur.Neck.x = x;
                cur.Neck.y = y;
                break;
            }
        }
    }
    return 1;
}

void checkEndSignal(bool sign)
{
    mtx1.lock();
    if (sign)
        endSignal = true;
    mtx1.unlock();
}

void judgePose() {
    bool curStatus;
    clock_t curTime;

    while (1) {
        //TODO : 기타 예외처리
        checkEndSignal(false);
        if (endSignal) break;

        Points cur;
        operatorQueue(&cur, 1); //현재 자세 좌표값 가져오기
        curTime = clock(); //현재 시간
        /*좌표 일부가 없을 때 판단*/

        //모든 좌표 인식 가능
        if (cur.isPointExist(cur.Nose) && cur.isPointExist(cur.Neck) && cur.isPointExist(cur.lEye) && cur.isPointExist(cur.rEye) &&
            cur.isPointExist(cur.lEar) && cur.isPointExist(cur.rEar) && cur.isPointExist(cur.lShoulder) && cur.isPointExist(cur.rShoulder))
            curStatus = judge(cur); //자세 판단
        else { //하나라도 없을 경우 : 나쁜 자세 or 자리떠남(컴퓨터 화면과 관련 없음)
            if (!cur.isPointExist(cur.Nose))  //코 없으면 자리떠남(코가 캠에 안 보이면서 화면을 볼 수가 없음. 억지로 하지 않는 이상)
                curStatus = SKIP;
            else if (cur.isPointExist(cur.lShoulder) && cur.isPointExist(cur.rShoulder)) //코가 있고 양 어깨가 있으면, 화면에는 들어오고 고개를 돌린 상황
                curStatus = SKIP;                                                       //양옆으로 기울인 자세는 어깨부터 나갈 수 밖에 없다.
            else if (!cur.isPointExist(cur.lShoulder) && !cur.isPointExist(cur.rShoulder)) //코가 있고, 양 어깨가 없다면 등을 기대고 엉덩이를 앞으로 쭉 뺀 자세.
                curStatus = BAD;
            else  //한 쪽 어깨가 안 찍히고, 코가 있으면 무조건 
                curStatus = BAD;
        }
        
        if (curStatus == SKIP) {
            if (recordedTime.status == -1)
                continue;
            if (recordedTime.status == GOOD)
                healthySec += (curTime - recordedTime.prev) / CLOCKS_PER_SEC;
            else
                unhealthySec += (curTime - recordedTime.prev) / CLOCKS_PER_SEC;
            recordedTime.status = -1;
        }

        /*기록 및 알람*/
        if (recordedTime.status == -1) {
            //최초 기록일 때
            recordedTime.status = curStatus;
            recordedTime.prev = curTime;
            recordedTime.alarmed = curTime;
        }
        else if (recordedTime.status != curStatus) {
            //자세가 달라졌을 때
            
            if (recordedTime.status == GOOD)
                healthySec += (curTime - recordedTime.prev) / CLOCKS_PER_SEC;
            else
                unhealthySec += (curTime - recordedTime.prev) / CLOCKS_PER_SEC;
            
            recordedTime.status = curStatus;
            recordedTime.prev = curTime;
        }
        else { //자세가 계속 같을 경우
            if (recordedTime.status == BAD) {
                double continuedSec = (curTime - recordedTime.prev) / CLOCKS_PER_SEC;
                double lastAlarmed = (curTime - recordedTime.alarmed) / CLOCKS_PER_SEC;

                //재알람시간 되지 않았거나, 알람 울릴 때가 아니라면 스킵
                if (lastAlarmed < alarmInterval) continue; 

                if (continuedSec > alarmStart) {
                    w->alramMessage();
                    recordedTime.alarmed = curTime;
                }
            }
        }
    }
}

void operatorQueue(Points *ret, bool how)
{
    mtx2.lock();
    if (how == false) {//enqueue
        poseData.push(*ret);
    }
    else { //dequeue
        if (!poseData.empty()) {
            *ret = poseData.front();
            poseData.pop();
        }
    }
    mtx2.unlock();
}

bool judge(Points cur) {
    if (abs(cur.lEar.y - cur.rEar.y) > 30)
        return BAD;
    if (abs(cur.lShoulder.y - cur.rShoulder.y) > 30)
        return BAD;

    double curRate = cur.length(cur.lShoulder, cur.rShoulder) / cur.length(cur.lEye, cur.rEye);
    //TODO fixDegree와 연동되게 변경
    double alpha = 0.75 - 0.005 * fixDegree ;

    if (stdPoseRate + alpha > curRate && curRate > stdPoseRate - 2*alpha)
        return GOOD;
    return BAD;
}

int setSTDPose()
{
    //프로세스 관련
    STARTUPINFO StartupInfo = { 0 };
    StartupInfo.cb = sizeof(STARTUPINFO);

    //파이프 관련
    HANDLE hNamePipe;
    TCHAR pipe_name[] = _T(PIPE_NAME);

    //파이프 생성
    hNamePipe = CreateNamedPipe(
        pipe_name,
        PIPE_ACCESS_DUPLEX,
        PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT,
        PIPE_UNLIMITED_INSTANCES,
        0,
        0,
        20000,
        NULL
    );

    if (hNamePipe == INVALID_HANDLE_VALUE)
    {
        printf("CreateNamePipe error! \n");
        return -1;
    }

    //alphapose 실행할 프로세스 경로 가져오기
    TCHAR path[128]; //유니코드 문자열
    char cpath[128];
    GetCurrentDirectory(128, path); //cwd경로
    WideCharToMultiByte(CP_ACP, 0, path, 128, cpath, 128, NULL, NULL); //TCHAR to char
    int len = strlen(cpath) - 1;
    char* pp = cpath + len;
    while (*pp-- != '\\');
    strcpy(pp + 1, "\\x64\\Debug\\caller2.exe");
    MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, cpath, 128, path, 128); //char to TCHAR

    //자식 프로세스 생성
    CreateProcess(
        path, //경로
        NULL,
        NULL, NULL,
        FALSE, //부모프로세스 중 상속 가능한 핸들 상속
        0,
        NULL, NULL,
        &StartupInfo,
        &ProcessInfo //프로세스 정보
    );

    //파이프 연결
    while (1)
    {
        //생성한 Named Pipe의 핸들을 누군가 얻어갈 때까지 대기  
        if (!(ConnectNamedPipe(hNamePipe, NULL))) {
            CloseHandle(hNamePipe);
            return -1;
        }
        else {

            if (ConnectClient2(hNamePipe) == -1)
                break;
        }
    }

    DisconnectNamedPipe(hNamePipe);
    CloseHandle(hNamePipe);
    return 0;
}

int ConnectClient2(HANDLE hNamePipe)
{
    TCHAR Message[100];
    char tmp[100];
    DWORD recvSize;
    DWORD sendSize;
    Points cur;
    int n, x, y;
    bool isSuccess = false;
    int cnt = 0;
    double eyesDist = 0, shouldersDist = 0;
    isError = false;

    ReadFile(
        hNamePipe,
        Message,
        sizeof(Message) - sizeof(TCHAR) * 1,
        &recvSize,
        NULL
    );
    _stscanf(Message, _T("%d %d %d"), &n, &x, &y);

    imported = true; //import 완료


    while (!measureStartBtn); //초기 자세 측정 버튼이 눌리면 다음단계로

    //시작 버튼 신호 송신
    WriteFile(
        hNamePipe,
        Message,
        (_tcslen(Message) + 1) * sizeof(TCHAR),
        &sendSize,
        NULL
    );
    thread t(sendText);
    t.detach();

    //3장 평균치 구하기
    while (cnt < 18) {
        int n, x, y;
        //recvSize -> NULL 포함한 바이트 수
        ReadFile(
            hNamePipe,
            Message,
            sizeof(Message) - sizeof(TCHAR) * 1,
            &recvSize,
            NULL
        );
        _stscanf(Message, _T("%d %d %d"), &n, &x, &y);

        if (n == -1 && x == -1 && y == -1) {
            if (cur.lShoulder.x == -1 || cur.lShoulder.y == -1 || cur.rShoulder.x == -1 ||
                cur.rShoulder.y == -1 || cur.lEye.x == -1 || cur.lEye.y == -1 ||
                cur.rEye.x == -1 || cur.rEye.y == -1)
                isError = true;
            else {
                eyesDist = cur.length(cur.lEye, cur.rEye);
                shouldersDist = cur.length(cur.lShoulder, cur.rShoulder);
                if (cnt > 14) {
                    stdPosePoints = stdPosePoints + cur;
                    stdPoseRate += shouldersDist / eyesDist;
                }
            }
            cnt++;
            cur = Points();
        }
        else {
            switch (n) {
            case 1:
                cur.lEye.x = x;
                cur.lEye.y = y;
                break;
            case 2:
                cur.rEye.x = x;
                cur.rEye.y = y;
                break;
            case 5:
                cur.lShoulder.x = x;
                cur.lShoulder.y = y;
                break;
            case 6:
                cur.rShoulder.x = x;
                cur.rShoulder.y = y;
                break;
            }
        }
    }

    if (isError) {
        //버튼 활성화
        imported = false;
        measureStartBtn = false;
        stdPoseRate = 0;
        cnt = 0;
        TerminateProcess(ProcessInfo.hProcess, 0);
        CloseHandle(ProcessInfo.hProcess);
        CloseHandle(ProcessInfo.hThread);
        return 1;
    }

    stdPoseRate /= 3;
    stdPosePoints = stdPosePoints / 3;
    TerminateProcess(ProcessInfo.hProcess, 0);
    CloseHandle(ProcessInfo.hProcess);
    CloseHandle(ProcessInfo.hThread);

    //측정창 닫는 함수 호출
    w->closeSignal();

    return 1;
}

void sendText() {
    for (int i = 10; i > 0; i--) {
        w->setuppose->textChanged(to_string(i));
        Sleep(1000);
    }
    if(isError) {
        w->setuppose->textChanged(to_string(-1));
    }
}