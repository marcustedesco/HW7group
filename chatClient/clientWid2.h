//Marcus Tedesco and Amre Kebaish
//HW7 Group Project
//ECE 3574
//Due: Dec. 9, 2012

#ifndef CLIENTWID2_H
#define CLIENTWID2_H

#include <QWidget>

namespace Ui {
class clientWid2;
}

class clientWid2 : public QWidget
{
    Q_OBJECT
    
public:
    explicit clientWid2(QWidget *parent = 0);
    ~clientWid2();
    
private:
    Ui::clientWid2 *ui;

private slots:
    void sendButtonPushed();

signals:
    void buttonPushed(QString);

};

#endif // CLIENTWID2_H
