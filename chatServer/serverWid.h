#ifndef SERVERWID_H
#define SERVERWID_H

#include <QWidget>

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
};

#endif // SERVERWID_H
