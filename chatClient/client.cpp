#include "client.h"

client::client(QObject *parent) :
    QObject(parent)
{
}

bool client::initialize(QString ip, QString port, QString name)
{
    //needs to make this but then talk to server to determine if
    //this name is already taken

    QString ipAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // use the first non-localhost IPv4 address
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
            ipAddressesList.at(i).toIPv4Address()) {
            ipAddress = ipAddressesList.at(i).toString();
            break;
        }
    }
    // if we did not find one, use IPv4 localhost
    if (ipAddress.isEmpty())
    {
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
    }

    secureSocket = new QSslSocket(this);


    //****I think this belongs on the server side***/
  /*  QMessageBox::critical(this, tr("Server Connection Error"),
                          tr("Unable to start the server: %1.")
                          .arg(sslServer->errorString()));*/

    return true;
}

void client::connectTo(QString clientName)
{
    //connects this client to the CLIENTNAME
    clientWid3* myWid3 = new clientWid3();

    myWid3->setName(clientName);

    connect(myWid3,SIGNAL(send(QString,QString)),this,SLOT(sendMessage(QString,QString)));

    myWid3->show();

    myFriends.push_back(myWid3);
}

void client::sendMessage(QString message, QString toName)
{
    //sends MESSAGE from myClient to TONAME

    qDebug() << "send: " << message << " to: " << toName;

    secureSocket->abort();
    secureSocket->setPeerVerifyMode(QSslSocket::QueryPeer);
    secureSocket->connectToHostEncrypted(hostName, portNum);
    //no hostLineEdit or portLineEdit

    if (!secureSocket->waitForEncrypted(1000)) {
         //QMessageBox::critical(this, "ERROR", "ERROR: Could not connect to host");
         return;
    }
}

void client::receiveMess()
{

}

