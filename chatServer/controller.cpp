//Marcus Tedesco and Amre Kebaish
//HW7 Group Project
//ECE 3574
//Due: Dec. 9, 2012
//controller.cpp

#include "controller.h"

controller::controller(QObject *parent) :
    QObject(parent)
{
    myServer = new server();
    myServerWid = new serverWid();
}

void controller::init()
{
    connect(myServer,SIGNAL(updateServer(QString)),myServerWid,SLOT(update(QString)));

    myServer->displayStartUpInfo();
    myServerWid->show();
}
