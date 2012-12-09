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
    myClient = new client();
}

void controller::init()
{ 
    //if connect is pushed check if the client was able to connect to the server
    connect(wid1,SIGNAL(buttonPushed()),this,SLOT(attemptConnect()));

    //if the client connected to the server successfully then close window 1 and open 2
    connect(this,SIGNAL(clientMade()),wid2,SLOT(show()));
    connect(this,SIGNAL(clientMade()),wid1,SLOT(close()));

    connect(wid2,SIGNAL(buttonPushed(QString)),this,SLOT(connectToClient(QString)));

    wid1->show();
}

void controller::attemptConnect()
{
     QString myIP = wid1->getIP();
     QString myPort = wid1->getPort();
     QString myName = wid1->getName();

     myClient = new client();
     bool success = myClient->initialize(myIP, myPort, myName);

     if(success){
         emit clientMade();
         wid2->setWindowTitle("Friend list for " + wid1->getName());
     }
     else
     {

     }
     //ACTUALLY DO THIS IN CLIENT WITH  #include <QMessageBox>
     //if not successful client should display error dialog box?
     //or the error dialog should be made in here if the initialize
     //returns an error string
}

void controller::connectToClient(QString name)
{
    //tell client to tell server it wants to connect to client NAME
    myClient->connectTo(name);

    //should also take client NAME out of the combobox so that it can not be clicked again
}
