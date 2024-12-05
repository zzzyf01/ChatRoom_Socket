/********************************************************************************
** Form generated from reading UI file 'clientdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTDIALOG_H
#define UI_CLIENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ClientDialog
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *messageEdit;
    QPushButton *sendButton;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *usernameEdit;
    QLabel *label_2;
    QLineEdit *passwordEdit;
    QPushButton *connectButton;

    void setupUi(QDialog *ClientDialog)
    {
        if (ClientDialog->objectName().isEmpty())
            ClientDialog->setObjectName(QString::fromUtf8("ClientDialog"));
        ClientDialog->resize(224, 286);
        verticalLayout = new QVBoxLayout(ClientDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listWidget = new QListWidget(ClientDialog);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        messageEdit = new QLineEdit(ClientDialog);
        messageEdit->setObjectName(QString::fromUtf8("messageEdit"));

        horizontalLayout->addWidget(messageEdit);

        sendButton = new QPushButton(ClientDialog);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        sendButton->setEnabled(false);

        horizontalLayout->addWidget(sendButton);


        verticalLayout->addLayout(horizontalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(ClientDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        usernameEdit = new QLineEdit(ClientDialog);
        usernameEdit->setObjectName(QString::fromUtf8("usernameEdit"));

        gridLayout->addWidget(usernameEdit, 0, 1, 1, 1);

        label_2 = new QLabel(ClientDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        passwordEdit = new QLineEdit(ClientDialog);
        passwordEdit->setObjectName(QString::fromUtf8("passwordEdit"));
        passwordEdit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(passwordEdit, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        connectButton = new QPushButton(ClientDialog);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));

        verticalLayout->addWidget(connectButton);


        retranslateUi(ClientDialog);

        QMetaObject::connectSlotsByName(ClientDialog);
    } // setupUi

    void retranslateUi(QDialog *ClientDialog)
    {
        ClientDialog->setWindowTitle(QCoreApplication::translate("ClientDialog", "Client", nullptr));
        sendButton->setText(QCoreApplication::translate("ClientDialog", "send", nullptr));
        label->setText(QCoreApplication::translate("ClientDialog", "user name", nullptr));
        label_2->setText(QCoreApplication::translate("ClientDialog", "password", nullptr));
        connectButton->setText(QCoreApplication::translate("ClientDialog", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientDialog: public Ui_ClientDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTDIALOG_H
