#ifndef CLIENTTHREAD_H
#define CLIENTTHREAD_H

#include <QThread>
#include <QtNetwork>
#include <QList>

class ClientThread : public QThread
{
    Q_OBJECT
public:
    explicit ClientThread(QObject *parent = 0);
    void setClientConnection(QSslSocket *connection);
    
signals:
    void messageReceived(QString message);
public slots:

protected:
    void run();
private:
    QSslSocket * clientConnection;
    QList<QString> users;

    
};

#endif // CLIENTTHREAD_H
