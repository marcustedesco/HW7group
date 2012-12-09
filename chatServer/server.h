#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QtNetwork>
#include <QList>
#include <QThread>
#include "SSLServer.h"
#include "clientthread.h"

class server : public QObject
{
    Q_OBJECT
public:
    explicit server(QObject *parent = 0);
    
signals:
    
public slots:
    void displayStartUpInfo();
    void processMess(QString message);

private slots:
    void sendWelcome();


private:
    SSLServer *sslServer;
    QList<QString> clientList;
    QString myIP;
    QList<QSslSocket*> myClientSockets;
    QList<ClientThread*> myClientThreads;

signals:
    void updateServer(QString);
};

#endif // SERVER_H
