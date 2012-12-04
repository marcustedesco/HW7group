#include <QtGui/QApplication>
#include "clientWid1.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    clientWid1 w;
    w.show();
    
    return a.exec();
}
