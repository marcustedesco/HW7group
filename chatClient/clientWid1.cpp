//Marcus Tedesco and Amre Kebaish
//HW7 Group Project
//ECE 3574
//Due: Dec. 9, 2012

#include "clientWid1.h"
#include "ui_clientWid1.h"

clientWid1::clientWid1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::clientWid1)
{
    ui->setupUi(this);

    connect(ui->connectButton,SIGNAL(pressed()),this,SLOT(sendButtonPushed()));
}

clientWid1::~clientWid1()
{
    delete ui;
}

void clientWid1::sendButtonPushed()
{
    emit buttonPushed();
}

QString clientWid1::getIP()
{
   return ui->ipBox->text();
}

QString clientWid1::getPort()
{
    return ui->portBox->text();
}

QString clientWid1::getName()
{
    return ui->nameBox->text();
}
