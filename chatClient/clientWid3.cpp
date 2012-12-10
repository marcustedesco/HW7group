//Marcus Tedesco and Amre Kebaish
//HW7 Group Project
//ECE 3574
//Due: Dec. 9, 2012
//clientWid3.cpp

#include "clientWid3.h"
#include "ui_clientWid3.h"

clientWid3::clientWid3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::clientWid3)
{
    ui->setupUi(this);

    connect(ui->messageLine,SIGNAL(returnPressed()),this,SLOT(sendMessage()));
}

clientWid3::~clientWid3()
{
    delete ui;
}

void clientWid3::setName(QString friendName)
{
    toName = friendName;
    this->setWindowTitle("Chat with " + toName);
}

void clientWid3::setMyName(QString name)
{
    myName = name;
}

void clientWid3::sendMessage()
{
    if(!(ui->messageLine->text() == ""))
    {
        emit send(ui->messageLine->text(), toName);
        ui->messagesBox->append(myName + "> " + ui->messageLine->text());
        ui->messageLine->clear();

    }
}

void clientWid3::update(QString line)
{
    ui->messagesBox->append(line);
}

QString clientWid3::getName()
{
    return toName;
}
