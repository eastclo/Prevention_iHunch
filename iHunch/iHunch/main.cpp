#include "iHunch.h"
#include <QtWidgets/QApplication>

iHunch* w;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("Fusion");
    w = new iHunch();
    (*w).setStyleSheet("QMainWindow {background : rgba(240,248,255,0.99);}");
    (*w).show();
    
    return a.exec();
}
