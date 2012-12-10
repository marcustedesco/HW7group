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


    connect(ui->connectButton,SIGNAL(pressed()),this, SLOT(sendButtonPushed()));
}

clientWid2::~clientWid2()
{
    delete ui;
}

void clientWid2::sendButtonPushed()
{
    emit buttonPushed(ui->clientListBox->itemText(ui->clientListBox->currentIndex()));
}

void clientWid2::updateFriends(QString friends)
{
    QStringList users = friends.split("***");
    qDebug() << users.size();

    for(int i = 0; i < (ui->clientListBox->count()); ++i)
    {
        ui->clientListBox->removeItem(i);
    }

    for(int i = 0; i < users.size(); ++i)
    {
        qDebug() << users.at(i);

        ui->clientListBox->addItem(users.at(i));

    }
}
