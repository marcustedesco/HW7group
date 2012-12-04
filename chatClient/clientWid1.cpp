#include "clientWid1.h"
#include "ui_clientWid1.h"

clientWid1::clientWid1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::clientWid1)
{
    ui->setupUi(this);
}

clientWid1::~clientWid1()
{
    delete ui;
}
