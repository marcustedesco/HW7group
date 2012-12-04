#include "clientWid2.h"
#include "ui_clientWid2.h"

clientWid2::clientWid2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::clientWid2)
{
    ui->setupUi(this);
}

clientWid2::~clientWid2()
{
    delete ui;
}
