#include "client.h"

client::client(QObject *parent) :
    QObject(parent)
{
    secureSocket = new QSslSocket(this);

    connect(secureSocket, SIGNAL(readyRead()), this, SLOT(receiveMess()));
}

bool client::initialize(QString ip, QString port, QString name)
{
    //needs to make this but then talk to server to determine if
    //this name is already taken

    //i dont think we need this part since we are going the ip from the user.
    //this is to find a default ip to connect to
    /*QString ipAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // use the first non-localhost IPv4 address
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
            ipAddressesList.at(i).toIPv4Address()) {
            ipAddress = ipAddressesList.at(i).toString();
            break;
        }
    }
    // if we did not find one, use IPv4 localhost
    if (ipAddress.isEmpty())
    {
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
    }*/

    hostName = ip;
    portNum = port.toInt();
    myName = name;

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

    block.append(name.toAscii());

    qDebug() << "Created QByteArray to send to server: " + QString(block);

    //connect(clientConnection, SIGNAL(disconnected()),clientConnection, SLOT(deleteLater()));

    secureSocket->write(block);
    //maybe keep connection open
    //secureSocket->disconnectFromHost();

    //****I think this belongs on the server side***/
    //this belongs on this side. if it was on server side then client would
    //not know what the error was. server can also display error in the server
    //text box if we want
  /*  QMessageBox::critical(this, tr("Server Connection Error"),
                          tr("Unable to start the server: %1.")
                          .arg(sslServer->errorString()));*/

    return true;
}

void client::connectTo(QString clientName)
{
    //connects this client to the CLIENTNAME
    clientWid3* myWid3 = new clientWid3();

    myWid3->setName(clientName);

    connect(myWid3,SIGNAL(send(QString,QString)),this,SLOT(sendMessage(QString,QString)));

    myWid3->show();

    myFriends.push_back(myWid3);
}

void client::sendMessage(QString message, QString toName)
{
    //sends MESSAGE from myClient to TONAME

    qDebug() << "send: " << message << " to: " << toName;

    secureSocket->abort();
    secureSocket->setPeerVerifyMode(QSslSocket::QueryPeer);
    secureSocket->connectToHostEncrypted(hostName, portNum);
    if (!secureSocket->waitForEncrypted(1000)) {
         qDebug() << "Waited for 1 second for encryption handshake with server without success";
         //QMessageBox::critical(this, "ERROR", "ERROR: Could not connect to host");
         return;
    }

    qDebug() << "Successfully waited for secure handshake with server...";

    qDebug() << "Creating first message from: " + myName + " *** " + toName + " *** " + message;

    QByteArray block;

    block.append(myName.toAscii() + " *** " + toName.toAscii() + " *** " + message.toAscii());

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

    qDebug() << "*************Message from server:************** " << message;

    //if(message == "Welcome to the server!")
    //    return;

    //clientWid3 thisWindow = myFriends.pop_back();
    //thisWindow->update(message);

    //update the correct client window
    //myfriends....myWid3->update(message);
}

