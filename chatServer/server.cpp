#include "server.h"
#include <QWaitCondition>
server::server(QObject *parent) :
    QObject(parent)
{
    sslServer = new SSLServer(this);

    if (!sslServer->listen()) {
       /* QMessageBox::critical(this, tr("Secure Fortune Server"),
                              tr("Unable to start the server: %1.")
                              .arg(sslServer->errorString()));
        close();
        return;*/

        // Tell gui to take care of it
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
    //connect(sslserver,SIGNAL()
    //connect(sslServer, SIGNAL(newConnection()), this, SLOT(processMess()));
}

void server::displayStartUpInfo()
{
    emit updateServer("My IP address is: " + myIP);
    emit updateServer("Running on port: " + QString::number(sslServer->serverPort()));
}

void server::sendWelcome()
{
    qDebug() << "Creating welcome message...";

    QByteArray block;

    /*QDataStream out(&block, QIODevice::ReadWrite); //WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);

    QString message = "Welcome to the server!";
    out << (quint16)0;
    out << message;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));*/

    QString message = "Welcome to the server!";
    block.append(message.toAscii());

    qDebug() << "About to send welcome message: " + QString(block);

    QSslSocket* clientConnection = sslServer->nextPendingConnection();
    //tempSocket = clientConnection;

    if (!clientConnection->waitForEncrypted(1000)){
        qDebug() << "Waited for 1 second for encryption handshake with client without success";
        updateServer("Waited for 1 second for encryption handshake with client without success");
        return;
    }

    qDebug() << "Successfully waited for secure handshake with the client...";
    updateServer("Successfully waited for secure handshake with the client...");

    connect(clientConnection, SIGNAL(disconnected()),clientConnection, SLOT(deleteLater()));
    myClientSockets.push_back(clientConnection);

   //  clientConnection->write(block);

    //waits for message for ten seconds... this can be changed
    if(clientConnection->waitForReadyRead(10000))
    {
        QByteArray in = clientConnection->readAll();

        QString clientMess = QString(in);

        processMess(clientMess);
    }




    //maybe maybe not?
    //clientConnection->disconnectFromHost();

    //add client connection to its own thread****

}

void server::processMess(QString message)
{

    //Message type legend
    // [number]*** [name]*** [message]
    // number = 1, joining server for first time, rest is name
    // number = 2, split by "***", retrive name, receiving name, and rest is message
    // number = 3, disconnecting from server, resy is name


    bool successfullyConnected = true;
    QStringList temp = message.split("***");
    int num = temp.at(0).toInt();

    qDebug() << num;
    qDebug() << "size of socket list:" << myClientSockets.size();
    QString name = temp.at(1);
    if(num == 1)
    {
        QString name = temp.at(1);
        if(clientList.contains(name))
        {
            successfullyConnected = false;
            QByteArray block;
            block.append("Enameinvalid");

            QSslSocket *clientConnection = myClientSockets.at(myClientSockets.size() - 1);
            myClientSockets.pop_back();
            clientConnection->write(block);
            \

        }
        else
        {
            clientList.append(name);
            QByteArray block;
            block.append("Snameadded");
            successfullyConnected = true;


            QSslSocket *clientConnection = myClientSockets.at(myClientSockets.size() - 1);
            qDebug() << "Message created to send back to client: " << QString(block);
            clientConnection->write(block);

           /*
            ClientThread *thisClientThread = new ClientThread();
            thisClientThread->setClientConnection(clientConnection);
            myClientThreads.push_back(thisClientThread);
            connect(thisClientThread, SIGNAL(messageReceived(QString)), this, SLOT(processMess(QString)));
            thisClientThread->start();*/

        }
    }
    else if(num == 2)
    {
        //Direct message correctly
        QString receiver = temp.at(2);
        QSslSocket* receiverConnection = myClientSockets.at(clientList.indexOf(receiver));
        QByteArray block;
        block.append(message);
        receiverConnection->write(block);

    }
    else if(num == 3)
    {
        //Disconnect client
        updateServer(name + "disconnected");
        int position = clientList.indexOf(name);
        clientList.removeAt(position);
        myClientSockets.removeAt(position);
    }
    else
    {
        qDebug() << "Should never reach here";
    }
    qDebug() << "Messaged received from client: " + message;
    updateServer("Messaged received from client: " + message);

    if(successfullyConnected && myClientSockets.at(myClientSockets.size()-1)->waitForBytesWritten(3000))
    {
        //for some reason this is being sent along with the response of whether client connect successfully or not,
        // need to wait then send this.
        QByteArray block;
        block.append("UsersOnServer:");
        for(int i = 0; i < clientList.size(); ++i)
        {
            block.append(clientList.at(i));
            if(i < clientList.size() - 1)
            {
                block.append("***");
            }
        }
        for(int i = 0; i < myClientSockets.size(); ++i)
        {
            QSslSocket *receiverConnection = myClientSockets.at(i);
            receiverConnection->write(block);
        }
    }



    /*QSslSocket* thisConnection = myClientSockets.pop_back();

    QByteArray incoming = thisConnection->readAll();

    QString message = QString(incoming);

    qDebug() << "Message received from client: " + message;

    return;*/

    /*QByteArray in = tempSocket->readAll();

    QString message = QString(in);

    qDebug() << "Messaged received from client: " + message;
    updateServer(message);
*/


}
