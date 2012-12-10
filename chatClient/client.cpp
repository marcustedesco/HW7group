//Marcus Tedesco and Amre Kebaish
//HW7 Group Project
//ECE 3574
//Due: Dec. 9, 2012
//client.cpp

#include "client.h"

/*
  changes to make:
    -if client1 sends message to client2 and a window is not open, open new window
    -move the quit/disconnect button to the window2 with clientlist because this is
        where the client should be able to disconnect from the server
    -disconnecting should update the clientlist combobox on all the clients
    -disconnecting should close all the conversation windows that client current has open
    -if the client1 disconnects while talking to client2, it should say client1 disconnected.
    -maybe add group chat?

    -delimiter needs to be changed! this gets seriously messed up when sent quickly
*/

client::client(QObject *parent) :
    QObject(parent)
{
    secureSocket = new QSslSocket(this);

   // connect(secureSocket, SIGNAL(readyRead()), this, SLOT(receiveMess()));
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

    block.append("1***" + name.toAscii());

    qDebug() << "Created QByteArray to send to server: " + QString(block);

    //connect(clientConnection, SIGNAL(disconnected()),clientConnection, SLOT(deleteLater()));

    secureSocket->write(block);

    if(secureSocket->waitForReadyRead(1000))
    {
        QByteArray in = secureSocket->readAll();

        QString serverMess = QString(in);
        if(QString::compare(serverMess, "Snameadded", Qt::CaseSensitive) == 0)
        {
            returnVal = true;
            qDebug() << "added to server";
            connect(secureSocket, SIGNAL(readyRead()), this, SLOT(receiveMess()));
        }
        else if(QString::compare(serverMess, "Enameinvalid", Qt::CaseSensitive) == 0)
        {
            returnVal = false;
            qDebug() << "username already taken";
        }
        qDebug() << "*************Message from server:************** 1" << serverMess;
    }

    //maybe keep connection open
    //secureSocket->disconnectFromHost();

    return returnVal;
}

void client::connectTo(QString clientName)
{
    //connects this client to the CLIENTNAME
    clientWid3* myWid3 = new clientWid3();

    myWid3->setName(clientName);
    qDebug() << "Client Name: " + clientName;
    myWid3->setMyName(myName);

    connect(myWid3,SIGNAL(send(QString,QString)),this,SLOT(sendMessage(QString,QString)));

    myWid3->show();

    myFriends.push_back(myWid3);
}

void client::sendMessage(QString message, QString toName)
{
    //sends MESSAGE from myClient to TONAME

    qDebug() << "send: " << message << " to: " << toName;

    qDebug() << "Successfully waited for secure handshake with server...";

    qDebug() << "Creating first message from: " + myName + " *** " + toName + " *** " + message;

    QByteArray block;

    block.append("2***" + myName.toAscii() + "***" + toName.toAscii() + "***" + message.toAscii());

    qDebug() << "Created QByteArray to send to server: " + QString(block);

    //connect(clientConnection, SIGNAL(disconnected()),clientConnection, SLOT(deleteLater()));

    secureSocket->write(block);
    //maybe keep connection open
    //secureSocket->disconnectFromHost();
}

void client::receiveMess()
{
    qDebug() << "Receiving message method";

    QByteArray in = secureSocket->readAll();

    QString message = QString(in);

    qDebug() << "*************Message from server:************** 2" << message;

    if(message.contains(":"))
    {
        QStringList tempList = message.split(":");
        qDebug() << tempList.at(0);
        if(QString::compare(tempList.at(0), "UsersOnServer", Qt::CaseSensitive) == 0)
        {
            qDebug() << "correct";
            emit updateUsers(tempList.at(1));
            qDebug() << "Users signal emitted";
        }
    }

    QStringList tempList2 = message.split("***");
    QString sender;
    if(QString::compare(tempList2.at(0), "2", Qt::CaseSensitive) == 0)
    {
        sender = tempList2.at(1);
        qDebug() << "sender: " +  sender;
        bool openWind = false;
        clientWid3* senderWid;
        for(int i = 0; i < myFriends.size(); ++i)
        {
            qDebug() << "friends name:"+  myFriends.at(i)->getName();
            if(QString::compare(myFriends.at(i)->getName(), sender, Qt::CaseSensitive) == 0)
            {
                openWind = true;
                senderWid = myFriends.at(i);
                qDebug() << "Window already open";

                break;
            }

        }
        if(openWind)
        {
            QString colorName = "<html><b><font color=blue>";
            colorName.append(tempList2.at(1));
            colorName.append("</font></b></html>");
            colorName.append(">" + tempList2.at(3));
            senderWid->update(colorName);
        }
        else
        {
            qDebug() << "Window Not open";
            clientWid3* myWid3 = new clientWid3();

            myWid3->setName(sender);
            myWid3->setMyName(myName);

            connect(myWid3,SIGNAL(send(QString,QString)),this,SLOT(sendMessage(QString,QString)));

            myWid3->show();

            myFriends.push_back(myWid3);
            myWid3->update(tempList2.at(1)+ "> "+ tempList2.at(3));
        }
    }



    //if(message == "Welcome to the server!")
    //    return;

    //clientWid3 thisWindow = myFriends.pop_back();
    //thisWindow->update(message);

    //update the correct client window
    //myfriends....myWid3->update(message);
}

