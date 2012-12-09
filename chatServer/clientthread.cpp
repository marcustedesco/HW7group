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
        if(clientConnection->waitForReadyRead(10000))
        {
            QByteArray in = clientConnection->readAll();

            QString clientMess = QString(in);

        }
    }

}
