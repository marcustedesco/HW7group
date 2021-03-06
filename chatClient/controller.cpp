//Marcus Tedesco and Amre Kebaish
//HW7 Group Project
//ECE 3574
//Due: Dec. 9, 2012
//controller.cpp

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
    connect(wid2,SIGNAL(connectPushed(QString)),this,SLOT(connectToClient(QString)));
    //connect(wid2,SIGNAL(disconnectPushed()),this,SLOT(disconnectFromServer()));
    //connect(wid2,SIGNAL(disconnectPushed()),wid2,SLOT(close()));

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
         qDebug() << "Successfully connected to the server";
         emit clientMade();
         wid2->setWindowTitle("Friend list for " + wid1->getName());
         connect(myClient, SIGNAL(updateUsers(QStringList)), wid2, SLOT(updateFriends(QStringList)));
     }
     else
     {
         qDebug() << "another user exists with same name";
         QMessageBox msgBox;
         msgBox.setWindowTitle("Error: Could not connect");
         msgBox.setText("Another user already exists with the same name. Choose another name.");
         msgBox.exec();

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
}

void controller::disconnectFromServer()
{
    //myClient->disconnectNow();
}
