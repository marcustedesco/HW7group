#include "client.h"

client::client(QObject *parent) :
    QObject(parent)
{
}

bool client::initialize(QString ip, QString port, QString name)
{
    return true;
}

void client::connectTo(QString clientName)
{
    //connects this client to the CLIENTNAME
    clientWid3* myWid3 = new clientWid3();

    myWid3->setName(clientName);

    qDebug() << "connectTo";

    connect(myWid3,SIGNAL(send(QString,QString)),this,SLOT(sendMessage(QString,QString)));

    myWid3->show();

    //myFriends->push_back(myWid3);
}

void client::sendMessage(QString message, QString toName)
{
    //sends MESSAGE from myClient to TONAME

    qDebug() << "send: " << message << " to: " << toName;
}

