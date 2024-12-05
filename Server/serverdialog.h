#ifndef SERVERDIALOG_H
#define SERVERDIALOG_H

#include <QDialog>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QMessageBox>
#include <QTime>
#include <QTimer>
#include <QTimerEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class ServerDialog; }
QT_END_NAMESPACE

class ServerDialog : public QDialog
{
    Q_OBJECT

public:
    ServerDialog(QWidget *parent = nullptr);
    ~ServerDialog();

private slots:
    void on_creatButton_clicked();
    void onNewconnection();
    void onReadyRead();
    void sendMessage(const QByteArray& buf);
    void onTimeout(void);
    void on_sendButton_clicked();
private:
    Ui::ServerDialog *ui;
    QTcpServer tcpServer;
    quint16 port;
    QList<QTcpSocket*> tcpClientList;
    QTimer timer;
    QTcpSocket tcpSocket;
    int timeid;
};
#endif // SERVERDIALOG_H
