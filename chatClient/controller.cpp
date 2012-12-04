//Marcus Tedesco and Amre Kebaish
//HW7 Group Project
//ECE 3574
//Due: Dec. 9, 2012

#include "controller.h"

controller::controller(QObject *parent) :
    QObject(parent)
{
    wid1 = new clientWid1();
    wid2 = new clientWid2();
}

void controller::init()
{
    //if connect is pushed check if the client was able to connect to the server
    connect(wid1,SIGNAL(buttonPushed()),this,SLOT(attemptConnect()));
    connect(this,SIGNAL(clientMade()),wid2,SLOT(show()));
    connect(this,SIGNAL(clientMade()),wid1,SLOT(close()));

    wid1->show();
}

void controller::attemptConnect()
{
     QString myIP = wid1->getIP();
     QString myPort = wid1->getPort();
     QString myName = wid1->getName();

     client* newClient = new client();
     bool success = newClient->initialize(myIP, myPort, myName);

     if(success)
         emit clientMade();
     //if not successful client should display error dialog box?
     //or the error dialog should be made in here if the initialize
     //returns an error string
}
