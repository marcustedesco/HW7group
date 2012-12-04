#include "client.h"

client::client(QObject *parent) :
    QObject(parent)
{
}

bool client::initialize(QString ip, QString port, QString name)
{
    return true;
}
