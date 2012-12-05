#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>

class client : public QObject
{
    Q_OBJECT
public:
    explicit client(QObject *parent = 0);
    
signals:
    
public slots:
    bool initialize(QString ip, QString port, QString name);
    void connectTo(QString clientName);

public:
    QString myName;
    
};

#endif // CLIENT_H
