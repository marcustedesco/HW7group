//Marcus Tedesco and Amre Kebaish
//HW7 Group Project
//ECE 3574
//Due: Dec. 9, 2012
//client.cpp

#include "client.h"

/*
  changes to make:
   X-if client1 sends message to client2 and a window is not open, open new window
    -move the quit/disconnect button to the window2 with clientlist because this is
        where the client should be able to disconnect from the server
    -disconnecting should update the clientlist combobox on all the clients
    -disconnecting should close all the conversation windows that client current has open
    -if the client1 disconnects while talking to client2, it should say client1 disconnected.
   X-maybe add group chat?

   X-delimiter needs to be changed! this gets seriously messed up when sent quickly
*/

client::client(QObject *parent) :
    QObject(parent)
{
    secureSocket = new QSslSocket(this);
}

bool client::initialize(QString ip, QString port, QString name)
{
    //needs to make this but then talk to server to determine if
    //this name is already taken

    hostName = ip;
    portNum = port.toInt();
    myName = name;

    bool returnVal = false;

    secureSocket->abort();
    secureSocket->setPeerVerifyMode(QSslSocket::QueryPeer);
    secureSocket->connectToHostEncrypted(hostName, portNum);
    if (!secureSocket->waitForEncrypted(1000)) {
         qDebug() << "Waited for 1 second for encryption handshake with server without success";
         //QMessageBox::critical(this, "ERROR", "ERROR: Could not connect to host");
         return false;
    }

    qDebug() << "Successfully waited for secure handshake with server...";

    qDebug() << "Creating first message from: " + name;

    QByteArray block;

    //changing the delimiter. can explain why later
    block.append("<1>.:." + name.toAscii());

    qDebug() << "Created QByteArray to send to server: " + QString(block);

    //connect(clientConnection, SIGNAL(disconnected()),clientConnection, SLOT(deleteLater()));

    secureSocket->write(block);

    if(secureSocket->waitForReadyRead(1000))
    {
        QByteArray in = secureSocket->readAll();

        QString serverMess = QString(in);
        if(QString::compare(serverMess, "<1>", Qt::CaseSensitive) == 0)
        {
            returnVal = true;
            qDebug() << "Added to server";
            connect(secureSocket, SIGNAL(readyRead()), this, SLOT(receiveMess()));
        }
        else if(QString::compare(serverMess, "<2>", Qt::CaseSensitive) == 0)
        {
            returnVal = false;
            qDebug() << "Username already taken";
        }
        qDebug() << "*************Message from server:************** 1" << serverMess;
    }

    return returnVal;
}

void client::connectTo(QString clientName)
{
    //connects this client to the CLIENTNAME
    bool foundWind = false;

    for(int i = 0; i < myFriends.size(); ++i)
    {
        if(QString::compare(myFriends.at(i)->getName(), clientName, Qt::CaseSensitive) == 0)
        {
            myFriends.at(i)->show();
            foundWind = true;
            break;
        }
    }

    if(!foundWind)
    {
        clientWid3* myWid3 = new clientWid3();

        myWid3->setMyName(myName);
        myWid3->setFriendName(clientName);
        qDebug() << "Client Name: " + clientName;

        connect(myWid3,SIGNAL(send(QString,QString)),this,SLOT(sendMessage(QString,QString)));

        myWid3->show();

        myFriends.push_back(myWid3);

    }
}

void client::disconnectNow()
{
    clientWid3* temp;

    //while(!(myFriends.isEmpty()))
    for(int i = 0; i < myFriends.size(); i++)
    {
       temp = myFriends.at(i);
       //temp = myFriends.back();
       //this is necessary
       //myFriends.pop_back();
       temp->close();
       //temp->destroy();
    }

    /*QByteArray block;

    block.append("<3>.:." + myName.toAscii());

    secureSocket->write(block);*/

    //secureSocket->disconnectFromHost();
}

void client::sendMessage(QString message, QString toName)
{
    qDebug() << "Successfully waited for secure handshake with server...";

    qDebug() << "Creating first message from: " + myName + " .:. " + toName + " .:. " + message;

    QByteArray block;

    if(toName == "Group Chat")
        block.append("<4>.:." + myName.toAscii() + ".:." + message.toAscii());
    else
        block.append("<2>.:." + myName.toAscii() + ".:." + toName.toAscii() + ".:." + message.toAscii());

    qDebug() << "Created QByteArray to send to server: " + QString(block);

    //connect(clientConnection, SIGNAL(disconnected()),clientConnection, SLOT(deleteLater()));

    secureSocket->write(block);
}

void client::updateChatWid(QString myWindName, QString mySender, QString myMessage)
{
    clientWid3* senderWid;
    bool foundWindow = false;

    for(int i = 0; i < myFriends.size(); ++i)
    {
        if(QString::compare(myFriends.at(i)->getName(), myWindName, Qt::CaseSensitive) == 0)
        {
            senderWid = myFriends.at(i);
            foundWindow = true;
            break;
        }
    }
    if(foundWindow)
    {
        QString colorName = "<html><b><font color=blue>";
        colorName.append(mySender);
        colorName.append("</font></b></html>");
        colorName.append(">" + myMessage);
        senderWid->update(colorName);
    }
}

void client::receiveMess()
{
    qDebug() << "Receiving message method";

    QByteArray in = secureSocket->readAll();

    QString message = QString(in);

    qDebug() << "*************Message from server:************** 2" << message;

    QStringList splitMessage = message.split(".:.");

    if(splitMessage.at(0) == "<3>")
    {
        splitMessage.removeAt(0);
        for(int i = 0; i < splitMessage.size(); i++)
            qDebug() << "user in client: " + splitMessage.at(i);
        emit updateUsers(splitMessage);
    }

    QString sender;

    if(splitMessage.at(0) == "<4>")
    {
        sender = splitMessage.at(1);

        qDebug() << "sender: " +  sender;

        bool openWind = false;

        for(int i = 0; i < myFriends.size(); ++i)
        {
            if(QString::compare(myFriends.at(i)->getName(), sender, Qt::CaseSensitive) == 0)
            {
                openWind = true;
                if(!(myFriends.at(i)->isVisible()))
                    myFriends.at(i)->show();
                qDebug() << "Window already open";

                break;
            }

        }
        if(!openWind)
        {
            qDebug() << "Window Not open";
            connectTo(sender);
        }

        updateChatWid(sender, sender, splitMessage.at(2));
    }

    if(splitMessage.at(0) == "<5>")
    {
        qDebug() << "receiving a group chat message from server";

        sender = splitMessage.at(1);

        bool openWind = false;

        for(int i = 0; i < myFriends.size(); ++i)
        {
            if(QString::compare(myFriends.at(i)->getName(), "Group Chat", Qt::CaseSensitive) == 0)
            {
                openWind = true;
                if(!(myFriends.at(i)->isVisible()))
                    myFriends.at(i)->show();
                qDebug() << "Window already open";

                break;
            }

        }
        if(!openWind)
        {
            qDebug() << "Window Not open";
            connectTo("Group Chat");
        }
        if(sender != myName)
            updateChatWid("Group Chat", sender, splitMessage.at(2));
    }
}

