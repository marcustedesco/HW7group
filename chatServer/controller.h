#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "server.h"
#include "serverWid.h"

class controller : public QObject
{
    Q_OBJECT
public:
    explicit controller(QObject *parent = 0);
    
signals:
    
public slots:
    void init();

private:
    server* myServer;
    serverWid* myServerWid;

};

#endif // CONTROLLER_H
