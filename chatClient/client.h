//Marcus Tedesco and Amre Kebaish
//HW7 Group Project
//ECE 3574
//Due: Dec. 9, 2012
//client.h
#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QList>
#include <QDebug>
#include <QMessageBox>
#include <QtNetwork>
#include "clientWid3.h"

class client : public QObject
{
    Q_OBJECT
public:
    explicit client(QObject *parent = 0);
    
public slots:
    bool initialize(QString ip, QString port, QString name);
    void connectTo(QString clientName);

private slots:
    void sendMessage(QString message, QString toName);
    void receiveMess();
public:
    QString myName;

private:
    QList<clientWid3*> myFriends;
    QSslSocket *secureSocket;
    quint16 blockSize;
    QString hostName;
    int portNum;
};

#endif // CLIENT_H
