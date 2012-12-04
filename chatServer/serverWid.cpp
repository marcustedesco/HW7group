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
