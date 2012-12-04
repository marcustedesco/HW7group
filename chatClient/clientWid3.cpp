#include "clientWid3.h"
#include "ui_clientWid3.h"

clientWid3::clientWid3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::clientWid3)
{
    ui->setupUi(this);
}

clientWid3::~clientWid3()
{
    delete ui;
}
