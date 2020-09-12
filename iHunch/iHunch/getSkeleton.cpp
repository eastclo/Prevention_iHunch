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

queue<Points> poseData; //좌표값 데이터
double stdPoseRate = 5;    //기준이 되는 초기자세 비율

RecordTime recordedTime;    //자세와 시간기록
double healthySec, unhealthySec; //좋은, 나쁜자세 총 시간
double alarmInterval = 3; //알람 울릴 시간 간격

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
        checkEndSignal(false);
        if (endSignal) break;

        Points cur;
        operatorQueue(&cur, 1); //현재 자세 좌표값 가져오기
        if (cur.length(cur.lEye, cur.rEye) == 0) continue;
        
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

                //알람 호출한지 5초 이내이고, 알람 울릴 때가 아니라면 스킵
                if (lastAlarmed < 5 && lastAlarmed < alarmInterval) continue; 

                if (continuedSec > alarmInterval) {
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
    if (stdPoseRate * 1.1 > curRate && curRate > stdPoseRate * 0.9)
        return GOOD;
    return BAD;
}