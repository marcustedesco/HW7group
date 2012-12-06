/********************************************************************************
** Form generated from reading UI file 'serverWid.ui'
**
** Created: Wed Dec 5 22:18:43 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERWID_H
#define UI_SERVERWID_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_serverWid
{
public:
    QGridLayout *gridLayout;
    QTextEdit *messageBox;

    void setupUi(QWidget *serverWid)
    {
        if (serverWid->objectName().isEmpty())
            serverWid->setObjectName(QString::fromUtf8("serverWid"));
        serverWid->resize(400, 300);
        gridLayout = new QGridLayout(serverWid);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        messageBox = new QTextEdit(serverWid);
        messageBox->setObjectName(QString::fromUtf8("messageBox"));

        gridLayout->addWidget(messageBox, 0, 0, 1, 1);


        retranslateUi(serverWid);

        QMetaObject::connectSlotsByName(serverWid);
    } // setupUi

    void retranslateUi(QWidget *serverWid)
    {
        serverWid->setWindowTitle(QApplication::translate("serverWid", "serverWid", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class serverWid: public Ui_serverWid {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERWID_H
