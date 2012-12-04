//clientWid1.h
//
//
//Authors: Marcus Tedesco, Amre Kebaish
//
#ifndef CLIENTWID1_H
#define CLIENTWID1_H

#include <QWidget>

namespace Ui {
class clientWid1;
}

class clientWid1 : public QWidget
{
    Q_OBJECT
    
public:
    explicit clientWid1(QWidget *parent = 0);
    ~clientWid1();
    
private:
    Ui::clientWid1 *ui;
};

#endif // CLIENTWID1_H
