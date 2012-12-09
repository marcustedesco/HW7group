//Marcus Tedesco and Amre Kebaish
//HW7 Group Project
//ECE 3574
//Due: Dec. 9, 2012
//serverWid.cpp

#include "serverWid.h"
#include "ui_serverWid.h"

serverWid::serverWid(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::serverWid)
{
    ui->setupUi(this);


}

serverWid::~serverWid()
{
    delete ui;
}

void serverWid::update(QString line)
{
    ui->messageBox->append(line);
}
