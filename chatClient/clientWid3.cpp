//Marcus Tedesco and Amre Kebaish
//HW7 Group Project
//ECE 3574
//Due: Dec. 9, 2012

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
    //set window name to friendName
    this->setWindowTitle(toName);
}

void clientWid3::sendMessage()
{
    emit send(ui->messageLine->text(), toName);
}

void clientWid3::update(QString line)
{
    ui->messagesBox->append(line);
}
