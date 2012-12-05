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
    ipChanged = false;
    portChanged = false;
    nameChanged = false;

    ui->setupUi(this);

    connect(ui->ipBox,SIGNAL(textChanged(QString)),this,SLOT(ipBoxChanged()));
    connect(ui->portBox,SIGNAL(textChanged(QString)),this,SLOT(portBoxChanged()));
    connect(ui->nameBox,SIGNAL(textChanged(QString)),this,SLOT(nameBoxChanged()));

    connect(ui->connectButton,SIGNAL(pressed()),this,SLOT(sendButtonPushed()));
}

clientWid1::~clientWid1()
{
    delete ui;
}

void clientWid1::ipBoxChanged()
{
    if(ui->ipBox->text().size() == 0)
        ipChanged = false;
    else
        ipChanged = true;

    if(ipChanged && portChanged && nameChanged)
        ui->connectButton->setEnabled(true);
    else
        ui->connectButton->setEnabled(false);

}

void clientWid1::portBoxChanged()
{
    if(ui->portBox->text().size() == 0)
        portChanged = false;
    else
        portChanged = true;

    if(ipChanged && portChanged && nameChanged)
        ui->connectButton->setEnabled(true);
    else
        ui->connectButton->setEnabled(false);
}

void clientWid1::nameBoxChanged()
{
    if(ui->nameBox->text().size() == 0)
        nameChanged = false;
    else
        nameChanged = true;

    if(ipChanged && portChanged && nameChanged)
        ui->connectButton->setEnabled(true);
    else
        ui->connectButton->setEnabled(false);
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
