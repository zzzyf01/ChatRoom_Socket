/********************************************************************************
** Form generated from reading UI file 'serverdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERDIALOG_H
#define UI_SERVERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ServerDialog
{
public:
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *messageEdit;
    QPushButton *sendButton;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *usernameEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *passwordEdit;
    QPushButton *creatButton;
    QListWidget *peopleList;

    void setupUi(QDialog *ServerDialog)
    {
        if (ServerDialog->objectName().isEmpty())
            ServerDialog->setObjectName(QString::fromUtf8("ServerDialog"));
        ServerDialog->setEnabled(true);
        ServerDialog->resize(458, 302);
        horizontalLayout_5 = new QHBoxLayout(ServerDialog);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listWidget = new QListWidget(ServerDialog);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        messageEdit = new QLineEdit(ServerDialog);
        messageEdit->setObjectName(QString::fromUtf8("messageEdit"));

        horizontalLayout_3->addWidget(messageEdit);

        sendButton = new QPushButton(ServerDialog);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        sendButton->setEnabled(false);

        horizontalLayout_3->addWidget(sendButton);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(ServerDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        usernameEdit = new QLineEdit(ServerDialog);
        usernameEdit->setObjectName(QString::fromUtf8("usernameEdit"));
        usernameEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(usernameEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(ServerDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        passwordEdit = new QLineEdit(ServerDialog);
        passwordEdit->setObjectName(QString::fromUtf8("passwordEdit"));
        passwordEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(passwordEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        creatButton = new QPushButton(ServerDialog);
        creatButton->setObjectName(QString::fromUtf8("creatButton"));

        verticalLayout->addWidget(creatButton);


        horizontalLayout_4->addLayout(verticalLayout);

        peopleList = new QListWidget(ServerDialog);
        peopleList->setObjectName(QString::fromUtf8("peopleList"));

        horizontalLayout_4->addWidget(peopleList);


        horizontalLayout_5->addLayout(horizontalLayout_4);


        retranslateUi(ServerDialog);

        QMetaObject::connectSlotsByName(ServerDialog);
    } // setupUi

    void retranslateUi(QDialog *ServerDialog)
    {
        ServerDialog->setWindowTitle(QCoreApplication::translate("ServerDialog", "Server", nullptr));
        sendButton->setText(QCoreApplication::translate("ServerDialog", "send", nullptr));
        label->setText(QCoreApplication::translate("ServerDialog", "user name", nullptr));
        usernameEdit->setText(QString());
        label_2->setText(QCoreApplication::translate("ServerDialog", "password", nullptr));
        passwordEdit->setText(QString());
        creatButton->setText(QCoreApplication::translate("ServerDialog", "creat", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ServerDialog: public Ui_ServerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERDIALOG_H
