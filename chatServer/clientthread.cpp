#include "clientthread.h"

ClientThread::ClientThread(QObject *parent) :
    QThread(parent)
{
}

void ClientThread::setClientConnection(QSslSocket *connection)
{
    clientConnection = connection;
}

void ClientThread::run()
{
    while(1)
    {

        if(clientConnection->waitForReadyRead(1000))
        {
            QByteArray in = clientConnection->readAll();

            QString clientMess = QString(in);
            qDebug() << "Received on thread: " << clientMess;
            emit messageReceived(clientMess);

        }
    }

}
