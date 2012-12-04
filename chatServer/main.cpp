//Marcus and Amre

#include <QtGui/QApplication>
#include "serverWid.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    serverWid w;
    w.show();
    
    return a.exec();
}
