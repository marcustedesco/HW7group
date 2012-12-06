#include "server.h"

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

        //^^^^^^^^^^^^^^^^^^^^^^^^^^^^
        // Tell gui to take care of it
        //____________________________
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
    //connect(sslServer, SIGNAL(newConnection()), this, SLOT(processMess()));
}

void server::displayStartUpInfo()
{
    emit updateServer("My IP address is: " + myIP);
    emit updateServer("Running on port: " + QString::number(sslServer->serverPort()));
}

void server::sendWelcome()
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);
    qDebug() << "Sending welcome message...";
    out << (quint16)0;
    out << "Welcome to the server!";
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));

    QSslSocket *clientConnection = sslServer->nextPendingConnection();
    if (!clientConnection->waitForEncrypted(1000)){
        qDebug() << "Waited for 1 second for encryption handshake without success";
        return;
    }
    qDebug() << "Successfully waited for secure handshake...";
    connect(clientConnection, SIGNAL(disconnected()),
            clientConnection, SLOT(deleteLater()));
    clientConnection->write(block);
    clientConnection->disconnectFromHost();
}

void server::processMess()
{
    /*
    //recieve the message
    QDataStream in(secureSocket);
    in.setVersion(QDataStream::Qt_4_0);

    if (blockSize == 0) {
       if (secureSocket->bytesAvailable() < (int)sizeof(quint16))
           return;
       in >> blockSize;
    }

    if (secureSocket->bytesAvailable() < blockSize)
       return;

    QString receivedMess;
    in >> receivedMess;
*/
   //Break down the received message and do something


}
