#ifndef CLIENTDIALOG_H
#define CLIENTDIALOG_H

#include <QDialog>
#include <QTcpSocket>
#include <QHostAddress>
#include <QMessageBox>
#include <QDebug>
#include <QTime>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

QT_BEGIN_NAMESPACE
namespace Ui { class ClientDialog; }
QT_END_NAMESPACE

class ClientDialog : public QDialog
{
    Q_OBJECT

public:
    ClientDialog(QWidget *parent = nullptr);
    ~ClientDialog();

private slots:
    void on_sendButton_clicked();

    void on_connectButton_clicked();

    void onConnected();

    void onDisconnected();

    void onReadyRead();

    void onError();
private:
    Ui::ClientDialog *ui;
    bool status;
    QTcpSocket tcpSocket;
    QHostAddress serverIP;
    quint16 serverPort;
    QString username;
    QString password;
};
#endif // CLIENTDIALOG_H
