//Marcus Tedesco and Amre Kebaish
//HW7 Group Project
//ECE 3574
//Due: Dec. 9, 2012

#ifndef SERVERWID_H
#define SERVERWID_H

#include <QWidget>
#include <QString>

namespace Ui {
class serverWid;
}

class serverWid : public QWidget
{
    Q_OBJECT
    
public:
    explicit serverWid(QWidget *parent = 0);
    ~serverWid();
    
private:
    Ui::serverWid *ui;

public slots:
    void update(QString line);
};

#endif // SERVERWID_H
