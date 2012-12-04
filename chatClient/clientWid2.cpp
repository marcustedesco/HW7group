//Marcus Tedesco and Amre Kebaish
//HW7 Group Project
//ECE 3574
//Due: Dec. 9, 2012

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
