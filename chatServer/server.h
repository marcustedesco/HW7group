#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QtNetwork>
#include "SSLServer.h"

class server : public QObject
{
    Q_OBJECT
public:
    explicit server(QObject *parent = 0);
    
signals:
    
public slots:
    void processMess();
    void testDisplay();

private:
    SSLServer *sslServer;
    QList<QString> clientList;
    QString myIP;

signals:
    void updateServer(QString);
};

#endif // SERVER_H
