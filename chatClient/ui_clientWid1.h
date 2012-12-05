/********************************************************************************
** Form generated from reading UI file 'clientWid1.ui'
**
** Created: Tue Dec 4 19:08:32 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTWID1_H
#define UI_CLIENTWID1_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_clientWid1
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *ipBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *portBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QLineEdit *nameBox;
    QPushButton *connectButton;

    void setupUi(QWidget *clientWid1)
    {
        if (clientWid1->objectName().isEmpty())
            clientWid1->setObjectName(QString::fromUtf8("clientWid1"));
        clientWid1->resize(428, 206);
        gridLayout = new QGridLayout(clientWid1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(clientWid1);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_4 = new QLabel(clientWid1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(clientWid1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        ipBox = new QLineEdit(clientWid1);
        ipBox->setObjectName(QString::fromUtf8("ipBox"));

        horizontalLayout->addWidget(ipBox);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(clientWid1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        portBox = new QLineEdit(clientWid1);
        portBox->setObjectName(QString::fromUtf8("portBox"));

        horizontalLayout_2->addWidget(portBox);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_5 = new QLabel(clientWid1);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_3->addWidget(label_5);

        nameBox = new QLineEdit(clientWid1);
        nameBox->setObjectName(QString::fromUtf8("nameBox"));

        horizontalLayout_3->addWidget(nameBox);


        gridLayout->addLayout(horizontalLayout_3, 4, 0, 1, 3);

        connectButton = new QPushButton(clientWid1);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));

        gridLayout->addWidget(connectButton, 5, 0, 1, 3);


        retranslateUi(clientWid1);

        QMetaObject::connectSlotsByName(clientWid1);
    } // setupUi

    void retranslateUi(QWidget *clientWid1)
    {
        clientWid1->setWindowTitle(QApplication::translate("clientWid1", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("clientWid1", "Connect to:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("clientWid1", "Connect as:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("clientWid1", "IP:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("clientWid1", "Port", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("clientWid1", "Name", 0, QApplication::UnicodeUTF8));
        connectButton->setText(QApplication::translate("clientWid1", "Connect", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class clientWid1: public Ui_clientWid1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWID1_H
