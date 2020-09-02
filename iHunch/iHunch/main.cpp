#include "iHunch.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("Fusion");

    iHunch w;
    w.show();
    
    return a.exec();
}
