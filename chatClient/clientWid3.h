//Marcus Tedesco and Amre Kebaish
//HW7 Group Project
//ECE 3574
//Due: Dec. 9, 2012
//clientWid3.h

#ifndef CLIENTWID3_H
#define CLIENTWID3_H

#include <QWidget>

namespace Ui {
class clientWid3;
}

class clientWid3 : public QWidget
{
    Q_OBJECT
    
public:
    explicit clientWid3(QWidget *parent = 0);
    ~clientWid3();

    void setFriendName(QString friendName);
    void setMyName(QString name);
    QString getName();
private:
    Ui::clientWid3 *ui;
    QString toName;
    QString myName;

public slots:
    void update(QString line);

private slots:
    void sendMessage();

signals:
    void send(QString,QString);
};

#endif // CLIENTWID3_H
