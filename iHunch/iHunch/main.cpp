#include "iHunch.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("Fusion");

    iHunch w;
    //¹è°æ»ö¹Ù²Þ
    w.setStyleSheet("QMainWindow {background : rgba(240,248,255,0.99);}");
    w.show();
    
    return a.exec();
}
