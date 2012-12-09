//Marcus Tedesco and Amre Kebaish
//HW7 Group Project
//ECE 3574
//Due: Dec. 9, 2012
//main.cpp

#include <QtGui/QApplication>
#include "controller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    controller* myControl = new controller();
    myControl->init();

    //serverWid w;
    //w.show();
    
    return a.exec();
}
