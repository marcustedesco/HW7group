/********************************************************************************
** Form generated from reading UI file 'clientWid3.ui'
**
** Created: Sun Dec 9 14:32:43 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTWID3_H
#define UI_CLIENTWID3_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_clientWid3
{
public:
    QGridLayout *gridLayout;
    QTextEdit *messagesBox;
    QLineEdit *messageLine;
    QPushButton *quitButton;

    void setupUi(QWidget *clientWid3)
    {
        if (clientWid3->objectName().isEmpty())
            clientWid3->setObjectName(QString::fromUtf8("clientWid3"));
        clientWid3->resize(537, 374);
        gridLayout = new QGridLayout(clientWid3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        messagesBox = new QTextEdit(clientWid3);
        messagesBox->setObjectName(QString::fromUtf8("messagesBox"));
        messagesBox->setReadOnly(true);

        gridLayout->addWidget(messagesBox, 0, 0, 1, 1);

        messageLine = new QLineEdit(clientWid3);
        messageLine->setObjectName(QString::fromUtf8("messageLine"));

        gridLayout->addWidget(messageLine, 1, 0, 1, 1);

        quitButton = new QPushButton(clientWid3);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));

        gridLayout->addWidget(quitButton, 2, 0, 1, 1);


        retranslateUi(clientWid3);

        QMetaObject::connectSlotsByName(clientWid3);
    } // setupUi

    void retranslateUi(QWidget *clientWid3)
    {
        clientWid3->setWindowTitle(QApplication::translate("clientWid3", "Form", 0, QApplication::UnicodeUTF8));
        messageLine->setText(QString());
        messageLine->setPlaceholderText(QApplication::translate("clientWid3", "Type your message here...", 0, QApplication::UnicodeUTF8));
        quitButton->setText(QApplication::translate("clientWid3", "Quit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class clientWid3: public Ui_clientWid3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWID3_H
