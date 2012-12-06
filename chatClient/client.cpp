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

    secureSocket->abort();
    secureSocket->setPeerVerifyMode(QSslSocket::QueryPeer);
    secureSocket->connectToHostEncrypted(ip, port.toInt());
    if (!secureSocket->waitForEncrypted(1000)) {
         qDebug() << "Waited for 1 second for encryption handshake without success";
         //QMessageBox::critical(this, "ERROR", "ERROR: Could not connect to host");
         return false;
    }

    qDebug() << "Successfully waited for secure handshake...";

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);
    qDebug() << "Creating first message";
    out << (quint16)0;
    out << name;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));

    qDebug() << "Successfully waited for secure handshake...";
    //connect(clientConnection, SIGNAL(disconnected()),clientConnection, SLOT(deleteLater()));
    secureSocket->write(block);
    secureSocket->disconnectFromHost();

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
    //no hostLineEdit or portLineEdit

    if (!secureSocket->waitForEncrypted(1000)) {
         //QMessageBox::critical(this, "ERROR", "ERROR: Could not connect to host");
         return;
    }
}

void client::receiveMess()
{
    qDebug() << "receiving message method";

    QDataStream in(secureSocket);
    in.setVersion(QDataStream::Qt_4_0);

    if (blockSize == 0) {
        if (secureSocket->bytesAvailable() < (int)sizeof(quint16))
            return;
        in >> blockSize;
    }

    if (secureSocket->bytesAvailable() < blockSize)
        return;

    QString message;
    in >> message;

    qDebug() << "message from server: " << message;

    //update the correct client window
    //myfriends....myWid3->update(message);
}

