//Marcus Tedesco and Amre Kebaish
//HW7 Group Project
//ECE 3574
//Due: Dec. 9, 2012

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QList>
#include <QPair>
#include "clientWid1.h"
#include "clientWid2.h"
#include "clientWid3.h"
#include "client.h"

class controller : public QObject
{
    Q_OBJECT
public:
    explicit controller(QObject *parent = 0);
    
public slots:
    void init();

private slots:
    void attemptConnect();
    void connectToClient(QString name);
    //void sendMessage(QString message, QString toName);

signals:
    void clientMade();

private:
    clientWid1* wid1;
    clientWid2* wid2;
    client* myClient;
    //QList< QPair<clientWid3*,QString> >* myFriends;
    
};

#endif // CONTROLLER_H
