#include "alphapose.h"
#include "iHunch.h"

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

queue<Points> poseData; //좌표값 데이터
double stdPoseRate;    //기준이 되는 초기자세 비율

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
        if (cur.lEye.x == -1 || cur.lShoulder.x == -1) continue;
        
        curStatus = judge(cur); //자세 판단
        curTime = clock(); //현재 시간
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
                if (lastAlarmed < alarmInterval && lastAlarmed < alarmStart) continue; 

                if (continuedSec > alarmStart) {
                    (*w).alramMessage();
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
    double curRate = cur.length(cur.lShoulder, cur.rShoulder) / cur.length(cur.lEye, cur.rEye);
    //TODO fixDegree와 연동되게 변경
    if (stdPoseRate * 1.2 > curRate && curRate > stdPoseRate * 0.8)
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
    Points cur;
    int n, x, y;
    bool isSuccess = false;
    bool isError = false;
    int cnt = 0;
    double eyesDist = 0, shouldersDist = 0;

    ReadFile(
        hNamePipe,
        Message,
        sizeof(Message) - sizeof(TCHAR) * 1,
        &recvSize,
        NULL
    );
    _stscanf(Message, _T("%d %d %d"), &n, &x, &y);

    imported = true; //import 완료

    while (1) {
        while (!measureStartBtn); //초기 자세 측정 버튼이 눌리면 다음단계로

        for (int i = 3; i > 0; i--) {
            Sleep(1000);
            //TODO 텍스트 띄우는 함수
        }

        //3장 평균치 구하기
        while(cnt < 3) {
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
            if (n == -1 && x == -1 && y == -1) {
                eyesDist = cur.length(cur.lEye, cur.rEye);
                shouldersDist = cur.length(cur.lShoulder, cur.rShoulder);
                stdPoseRate += shouldersDist / eyesDist;
                cnt++;
                cur = Points();
            }
            else if (x == -1 || y == -1) {
                isError = true;
                break;
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
            //TODO: 에러시 에러메시지 출력 후 재시작
            measureStartBtn = false;
            stdPoseRate = 0;
            isError = false;
            cnt = 0;
            continue;
        }

        stdPoseRate /= 3;
        break;
    }

    TerminateProcess(ProcessInfo.hProcess, 0);
    CloseHandle(ProcessInfo.hProcess);
    CloseHandle(ProcessInfo.hThread);
    //TODO: 측정창 닫는 함수 호출

    return 1;
}