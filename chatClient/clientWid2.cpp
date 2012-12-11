//Marcus Tedesco and Amre Kebaish
//HW7 Group Project
//ECE 3574
//Due: Dec. 9, 2012
//clientWid2.cpp

#include "clientWid2.h"
#include "ui_clientWid2.h"

clientWid2::clientWid2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::clientWid2)
{
    ui->setupUi(this);


    connect(ui->connectButton,SIGNAL(pressed()),this, SLOT(sendConnectPushed()));
    connect(ui->disconnectButton,SIGNAL(pressed()),this,SLOT(sendDisconnectPushed()));
    //connect(ui->disconnectButton,SIGNAL(pressed()),this,SLOT(deleteLater()));

}

clientWid2::~clientWid2()
{
    delete ui;
}

void clientWid2::sendConnectPushed()
{
    emit connectPushed(ui->clientListBox->itemText(ui->clientListBox->currentIndex()));
}

void clientWid2::sendDisconnectPushed()
{
    emit disconnectPushed();
}

void clientWid2::updateFriends(QStringList friends)
{
    //QStringList users = friends.split("***");
    //qDebug() << users.size();

    ui->clientListBox->clear();

    /*for(int i = 0; i < (ui->clientListBox->count()); ++i)
    {
        ui->clientListBox->removeItem(i);
    }*/

    ui->clientListBox->addItem("Group Chat");

    for(int i = 0; i < friends.size(); ++i)
    {
        qDebug() << "adding this friend: " + friends.at(i);

        ui->clientListBox->addItem(friends.at(i));

    }
}
