#include "server.h"
#include <QWaitCondition>
server::server(QObject *parent) :
    QObject(parent)
{
    sslServer = new SSLServer(this);

    if (!sslServer->listen()) {
    }

    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();

    // use the first non-localhost IPv4 address
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
            ipAddressesList.at(i).toIPv4Address()) {
            myIP = ipAddressesList.at(i).toString();
            break;
        }
    }
    // if we did not find one, use IPv4 localhost
    if (myIP.isEmpty())
        myIP = QHostAddress(QHostAddress::LocalHost).toString();

    connect(sslServer, SIGNAL(newConnection()), this, SLOT(sendWelcome()));

    updateServer("Server has started up.");
}

void server::displayStartUpInfo()
{
    emit updateServer("My IP address is: " + myIP);
    emit updateServer("Running on port: " + QString::number(sslServer->serverPort()));
}

void server::sendWelcome()
{
    QSslSocket* clientConnection = sslServer->nextPendingConnection();

    if (!clientConnection->waitForEncrypted(1000)){
        qDebug() << "Waited for 1 second for encryption handshake with client without success";
        updateServer("Waited for 1 second for encryption handshake with client without success");
        return;
    }

    qDebug() << "Successfully waited for secure handshake with the client...";

    //connect(clientConnection, SIGNAL(disconnected()),clientConnection, SLOT(deleteLater()));

    myClientSockets.push_back(clientConnection);

    if(clientConnection->waitForReadyRead(1000))
    {
        QByteArray in = clientConnection->readAll();

        QString clientMess = QString(in);

        processMess(clientMess);
    }
}

void server::processMess(QString message)
{
/*  OLD LEGEND
    //Message type legend
    // <[number]>.:.[name].:.[possible second name].:.[message]
    // number = 1, joining server for first time, rest is name
    // number = 2, split by ".:.", retrive name, receiving name, and rest is message
    // number = 3, disconnecting from server, rest is name
*/

    mutex.lock();
    bool usersChanged = true;
    QStringList temp = message.split(".:.");
    QString numStr = temp.at(0);

    qDebug() << "Message number string" << numStr;
    qDebug() << "Size of socket list:" << myClientSockets.size();

    QString name = temp.at(1);

    qDebug() << "Messaged received from client: " + message;

    //<1>
    //<1>.:.NAME(of possible client)
    //Checks if client can be added to server
    //      returns <2> if name is taken
    //      returns <1> if name is added
    if(numStr == "<1>")
    {
        //if client name is already taken then return <2> meaning not added to server
        if(clientList.contains(name))
        {
            usersChanged = false;
            QByteArray block;
            block.append("<2>");

            QSslSocket *clientConnection = myClientSockets.at(myClientSockets.size() - 1);
            myClientSockets.pop_back();
            clientConnection->write(block);

            updateServer("Another client named " + name + " tried to connect to the server.");
        }
        //else add the client name to the server, return <1> meaning succesful
        else
        {
            clientList.append(name);
            QByteArray block;
            block.append("<1>");
            usersChanged = true;

            QSslSocket *clientConnection = myClientSockets.at(myClientSockets.size() - 1);
            qDebug() << "Message created to send back to client: " << QString(block);
            clientConnection->write(block);


            ClientThread *thisClientThread = new ClientThread();
            thisClientThread->setClientConnection(clientConnection);
            myClientThreads.push_back(thisClientThread);
            connect(thisClientThread, SIGNAL(messageReceived(QString)), this, SLOT(processMess(QString)));
            thisClientThread->start();

            updateServer(name + " was added to the server.");
        }
    }

    //<2>
    //<2>.:.sender.:.receiver.:.message
    //Direct messages between clients
    //      returns <4>.:.sender.:.message
    else if(numStr == "<2>")
    {
        //Direct message correctly
        QString receiver = temp.at(2);
        QSslSocket* receiverConnection = myClientSockets.at(clientList.indexOf(receiver));
        //myClientThreads.at(clientList.indexOf(receiver))->wait(2000);
        qDebug() << "receiver Index: " << clientList.indexOf(receiver);

        QByteArray block;

        QString newMessage = "<4>.:." + temp.at(1) + ".:." + temp.at(3);

        block.append(newMessage);

        receiverConnection->write(block);

        if(receiverConnection->waitForBytesWritten(10000))
        {
            qDebug() << "sent message to client";
        }

        usersChanged = false;

        updateServer(temp.at(1) + ">" + receiver + ": " + temp.at(3));
    }

    //<3>
    //<3>.:.client name
    //Disconnects the client from the server
    else if(numStr == "<3>")
    {
        //Disconnect client
        updateServer(name + " disconnected.");
        /*int position = clientList.indexOf(name);
        clientList.removeAt(position);
        myClientSockets.removeAt(position);
        ClientThread *thisClientThread = myClientThreads.at(position);
        thisClientThread->terminate();
        myClientThreads.removeAt(position);*/

        usersChanged = true;
    }

    //<4>
    //<4>.:.sender.:.message
    //Sends a message to all the clients on the server
    //      returns <5>.:.sender.:.message
    else if(numStr == "<4>")
    {
        QSslSocket* receiverConnection;

        for(int i = 0; i < myClientSockets.size(); i++)
        {
            receiverConnection = myClientSockets.at(i);

            QByteArray block;

            QString newMessage = "<5>.:." + name + ".:." + temp.at(2);

            block.append(newMessage);

            receiverConnection->write(block);

            if(receiverConnection->waitForBytesWritten(10000))
            {
                qDebug() << "sent message to client";
            }
        }

        usersChanged = false;

        updateServer(temp.at(1) + ">Group chat: " + temp.at(2));
    }

    else
    {
        qDebug() << "Should never reach here";
    }

    if(usersChanged)
    {
        if(myClientSockets.at(myClientSockets.size()-1)->waitForBytesWritten(3000))
        {
            QByteArray block;
            block.append("<3>.:.");
            for(int i = 0; i < clientList.size(); ++i)
            {
                qDebug() << "client " << i << " in list: " << clientList.at(i);
                block.append(clientList.at(i));
                if(i < clientList.size() - 1)
                {
                    block.append(".:.");
                }
            }
            for(int i = 0; i < myClientSockets.size(); ++i)
            {
                QSslSocket *receiverConnection = myClientSockets.at(i);
                receiverConnection->write(block);
            }
        }
    }

    mutex.unlock();
}
