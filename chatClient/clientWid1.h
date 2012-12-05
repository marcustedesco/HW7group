//Marcus Tedesco and Amre Kebaish
//HW7 Group Project
//ECE 3574
//Due: Dec. 9, 2012

#ifndef CLIENTWID1_H
#define CLIENTWID1_H

#include <QWidget>
#include <QDebug>
#include <QString>

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
    bool ipChanged;
    bool portChanged;
    bool nameChanged;

public slots:
    QString getIP();
    QString getPort();
    QString getName();

private slots:
    void ipBoxChanged();
    void portBoxChanged();
    void nameBoxChanged();
    void sendButtonPushed();

signals:
    void buttonPushed();
};

#endif // CLIENTWID1_H
