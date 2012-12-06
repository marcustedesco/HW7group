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

    emit updateServer("My IP address is: " + myIP);

    connect(sslServer, SIGNAL(newConnection()), this, SLOT(processMess()));
}

void server::testDisplay()
{
    emit updateServer("My IP address is: " + myIP);
}

void server::processMess()
{/*
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
