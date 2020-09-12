#include "iHunch.h"
#include <QtWidgets/QApplication>

iHunch* w;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("Fusion");
    w = new iHunch();
    (*w).show();
    
    return a.exec();
}
