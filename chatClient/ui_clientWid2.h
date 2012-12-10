/********************************************************************************
** Form generated from reading UI file 'clientWid2.ui'
**
** Created: Sun Dec 9 20:07:31 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTWID2_H
#define UI_CLIENTWID2_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_clientWid2
{
public:
    QGridLayout *gridLayout;
    QComboBox *clientListBox;
    QPushButton *connectButton;

    void setupUi(QWidget *clientWid2)
    {
        if (clientWid2->objectName().isEmpty())
            clientWid2->setObjectName(QString::fromUtf8("clientWid2"));
        clientWid2->resize(297, 99);
        gridLayout = new QGridLayout(clientWid2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        clientListBox = new QComboBox(clientWid2);
        clientListBox->setObjectName(QString::fromUtf8("clientListBox"));

        gridLayout->addWidget(clientListBox, 0, 0, 1, 1);

        connectButton = new QPushButton(clientWid2);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));

        gridLayout->addWidget(connectButton, 1, 0, 1, 1);


        retranslateUi(clientWid2);

        QMetaObject::connectSlotsByName(clientWid2);
    } // setupUi

    void retranslateUi(QWidget *clientWid2)
    {
        clientWid2->setWindowTitle(QApplication::translate("clientWid2", "Form", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_ACCESSIBILITY
        clientListBox->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        connectButton->setText(QApplication::translate("clientWid2", "Connect", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class clientWid2: public Ui_clientWid2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWID2_H
