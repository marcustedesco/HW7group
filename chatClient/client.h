#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QList>
#include <QDebug>
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

public:
    QString myName;

private:
    QList<clientWid3*>* myFriends;
    
};

#endif // CLIENT_H
