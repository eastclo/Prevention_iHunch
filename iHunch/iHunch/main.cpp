#include "iHunch.h"
#include <QtWidgets/QApplication>

iHunch* w;
extern PROCESS_INFORMATION ProcessInfo;
void f() {
    TerminateProcess(ProcessInfo.hProcess, 0);
    CloseHandle(ProcessInfo.hProcess);
    CloseHandle(ProcessInfo.hThread);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("Fusion");
    w = new iHunch();
    w->setStyleSheet("QMainWindow {background : rgba(240,248,255,0.99);}");
    (*w).show();
    
    atexit(f);
    return a.exec();
}
