#include <iostream>
#include <windows.h>
#include <tchar.h>
#include <cstring>
#include <thread>
#include <mutex>

int startFix(void);
void editChildProccessPath(char* path);
int ConnectClient(HANDLE hNamePipe);
void checkEndSignal(bool sign);