#include "alphapose.h"

#ifdef UNICODE
#define GetCurrentDirectory  GetCurrentDirectoryW
#else
#define GetCurrentDirectory  GetCurrentDirectoryA
#endif // !UNICODE
#define PIPE_NAME   "\\\\.\\pipe\\test_pipe"

using namespace std;

bool endSignal; //종료 sign
PROCESS_INFORMATION ProcessInfo; //프로세스 정보
std::mutex mtx; //뮤텍스 변수

void editChildProccessPath(char* path);
int ConnectClient(HANDLE hNamePipe);
void checkEndSignal(bool sign);

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
    DWORD recvSize;

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

        //TODO: 8개를 읽고 
        if (n == 0)
            printf("코(%d, %d)\n", x, y);
        if (n == 1)
            printf("왼눈(%d, %d)\n", x, y);
        if (n == 2)
            printf("오눈(%d, %d)\n", x, y);
        if (n == 3)
            printf("왼귀(%d, %d)\n", x, y);
        if (n == 4)
            printf("오귀(%d, %d)\n", x, y);
        if (n == 5)
            printf("왼어(%d, %d)\n", x, y);
        if (n == 6)
            printf("오어(%d, %d)\n", x, y);
        if (n == 17)
            printf("목(%d, %d)\n", x, y);
    }
    return 1;
}

void checkEndSignal(bool sign)
{
    mtx.lock();
    if (sign)
        endSignal = true;
    mtx.unlock();
}