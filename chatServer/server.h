#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QtNetwork>
#include <QList>
#include <QThread>
#include "SSLServer.h"

class server : public QObject
{
    Q_OBJECT
public:
    explicit server(QObject *parent = 0);
    
signals:
    
public slots:
    void displayStartUpInfo();
    void processMess();

private slots:
    void sendWelcome();

private:
    SSLServer *sslServer;
    QList<QString> clientList;
    QString myIP;
    QList<QSslSocket*> myClientSockets;

signals:
    void updateServer(QString);
};

#endif // SERVER_H
