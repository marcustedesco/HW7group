#include "server.h"

server::server(QObject *parent) :
    QObject(parent)
{
    sslServer = new SSLServer(this);

    if (!sslServer->listen()) {
       /* QMessageBox::critical(this, tr("Secure Fortune Server"),
                              tr("Unable to start the server: %1.")
                              .arg(sslServer->errorString()));
        close();
        return;*/

        // Tell gui to take care of it
    }

    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // use the first non-localhost IPv4 address
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
            ipAddressesList.at(i).toIPv4Address()) {
            myIP = ipAddressesList.at(i).toString();
            break;
        }
    }
    // if we did not find one, use IPv4 localhost
    if (myIP.isEmpty())
        myIP = QHostAddress(QHostAddress::LocalHost).toString();

    connect(sslServer, SIGNAL(newConnection()), this, SLOT(sendWelcome()));
    //connect(sslserver,SIGNAL()
    //connect(sslServer, SIGNAL(newConnection()), this, SLOT(processMess()));
}

void server::displayStartUpInfo()
{
    emit updateServer("My IP address is: " + myIP);
    emit updateServer("Running on port: " + QString::number(sslServer->serverPort()));
}

void server::sendWelcome()
{
    qDebug() << "Creating welcome message...";

    QByteArray block;
    /*QDataStream out(&block, QIODevice::ReadWrite); //WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);

    QString message = "Welcome to the server!";
    out << (quint16)0;
    out << message;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));*/

    QString message = "Welcome to the server!";
    block.append(message.toAscii());

    qDebug() << "About to send welcome message: " + QString(block);

    QSslSocket* clientConnection = sslServer->nextPendingConnection();
    //tempSocket = clientConnection;

    if (!clientConnection->waitForEncrypted(1000)){
        qDebug() << "Waited for 1 second for encryption handshake with client without success";
        updateServer("Waited for 1 second for encryption handshake with client without success");
        return;
    }

    qDebug() << "Successfully waited for secure handshake with the client...";
    updateServer("Successfully waited for secure handshake with the client...");

    //connect(clientConnection,SIGNAL(readyRead()),this,processMess());
    connect(clientConnection, SIGNAL(disconnected()),clientConnection, SLOT(deleteLater()));

    clientConnection->write(block);

    //waits for message for ten seconds... this can be changed
    if(clientConnection->waitForReadyRead(10000))
    {
        QByteArray in = clientConnection->readAll();

        QString clientMess = QString(in);

        processMess(clientMess);
        //qDebug() << "*************Message from client:************** " << clientMess;
    }




    //maybe maybe not?
    //clientConnection->disconnectFromHost();

    //add client connection to its own thread****
    myClientSockets.push_back(clientConnection);

    //temporary call of processmess
    //processMess();
}

void server::processMess(QString message)
{

    qDebug() << "Messaged received from client: " + message;
    updateServer("Messaged received from client: " + message);

    /*QSslSocket* thisConnection = myClientSockets.pop_back();

    QByteArray incoming = thisConnection->readAll();

    QString message = QString(incoming);

    qDebug() << "Message received from client: " + message;

    return;*/

    /*QByteArray in = tempSocket->readAll();

    QString message = QString(in);

    qDebug() << "Messaged received from client: " + message;
    updateServer(message);
*/
   //Break down the received message and do something


}
