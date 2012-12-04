//Marcus Tedesco and Amre Kebaish
//HW7 Group Project
//ECE 3574
//Due: Dec. 9, 2012

#include <QtGui/QApplication>
#include "serverWid.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    serverWid w;
    w.show();
    
    return a.exec();
}
