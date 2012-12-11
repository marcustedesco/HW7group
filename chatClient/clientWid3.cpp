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

void clientWid3::setFriendName(QString friendName)
{
    toName = friendName;
    this->setWindowTitle(myName + "'s chat with " + toName);
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
        QString colorName = "<html><b><font color=red>";
        colorName.append(myName);
        colorName.append("</font></b></html>");
        colorName.append(">" + ui->messageLine->text());
        ui->messagesBox->append(colorName);
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
