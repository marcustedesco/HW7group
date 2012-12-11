/********************************************************************************
** Form generated from reading UI file 'clientWid2.ui'
**
** Created: Tue Dec 11 02:37:12 2012
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
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_clientWid2
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QComboBox *clientListBox;
    QPushButton *connectButton;
    QFrame *line;
    QPushButton *disconnectButton;

    void setupUi(QWidget *clientWid2)
    {
        if (clientWid2->objectName().isEmpty())
            clientWid2->setObjectName(QString::fromUtf8("clientWid2"));
        clientWid2->resize(449, 48);
        gridLayout = new QGridLayout(clientWid2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        clientListBox = new QComboBox(clientWid2);
        clientListBox->setObjectName(QString::fromUtf8("clientListBox"));
        clientListBox->setFocusPolicy(Qt::TabFocus);

        horizontalLayout->addWidget(clientListBox);

        connectButton = new QPushButton(clientWid2);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));

        horizontalLayout->addWidget(connectButton);

        line = new QFrame(clientWid2);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        disconnectButton = new QPushButton(clientWid2);
        disconnectButton->setObjectName(QString::fromUtf8("disconnectButton"));

        horizontalLayout->addWidget(disconnectButton);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(clientWid2);

        QMetaObject::connectSlotsByName(clientWid2);
    } // setupUi

    void retranslateUi(QWidget *clientWid2)
    {
        clientWid2->setWindowTitle(QApplication::translate("clientWid2", "Connection", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_ACCESSIBILITY
        clientListBox->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        connectButton->setText(QApplication::translate("clientWid2", "Chat", 0, QApplication::UnicodeUTF8));
        disconnectButton->setText(QApplication::translate("clientWid2", "Disconnect", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class clientWid2: public Ui_clientWid2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWID2_H
