#include "clientdialog.h"
#include "ui_clientdialog.h"

ClientDialog::ClientDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ClientDialog)
{
    ui->setupUi(this);
    status = false;
    connect(&tcpSocket,SIGNAL(connected()),this,SLOT(onConnected()));
    connect(&tcpSocket,SIGNAL(disconnected()),this,SLOT(onDisconnected()));
    connect(&tcpSocket,SIGNAL(readyRead()),this,SLOT(onReadyRead()));
    connect(&tcpSocket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(onError()));
}

ClientDialog::~ClientDialog()
{
    delete ui;
}


void ClientDialog::on_sendButton_clicked()
{
    QString msg = ui->messageEdit->text();
    if(msg == "")
    {
        return;
    }
    msg = username + ":" + msg;
    tcpSocket.write(msg.toUtf8());

    ui->messageEdit->clear();
}

void ClientDialog::on_connectButton_clicked()
{
    QString names[20][10] = { {"qq"},{"ww"},{"ee"},{"rr"},{"tt"},{"yy"},{"uu"},{"ii"},{"oo"},{"pp"},{"aa"},{"ss"},{"dd"},{"ff"},{"gg"},{"hh"},{"\0"}};
    int flag = 0;
    if(status == false)
    {
        serverIP.setAddress("127.0.0.1");
        serverPort = 8888;
        username = ui->usernameEdit->text();
        password = ui->passwordEdit->text();
        if(ui->passwordEdit->text()=="123456")
        {
            for(int i = 0 ;i <16;i++){
                if(ui->usernameEdit->text() == names[i])
                {
                    flag = 1;
                    break;
                }
            }
        }

        if(flag == 1)
        {
            tcpSocket.connectToHost(serverIP,serverPort);
        }
        else if(flag ==0)
        {
            qDebug() << "login failed!";
            QMessageBox msgBox(
                        QMessageBox::Critical,
                        "Error",
                        "Uesr Name or Password wrong",
                        QMessageBox::Ok,
                        this);
            msgBox.exec();
        }

    }
    else
    {
        QString msg = username + " leave the room";
        tcpSocket.write(msg.toUtf8());
        tcpSocket.disconnectFromHost();
    }
}

void ClientDialog::onConnected()
{
    status = true;
    ui->sendButton->setEnabled(true);
    ui->usernameEdit->setEnabled(false);
    ui->passwordEdit->setEnabled(false);
    ui->connectButton->setText("logout");

    QString msg = username + " enter the room";

    tcpSocket.write(msg.toUtf8());
}

void ClientDialog::onDisconnected()
{
    status = false;
    ui->sendButton->setEnabled(false);
    ui->usernameEdit->setEnabled(true);
    ui->passwordEdit->setEnabled(true);
    ui->connectButton->setText("login");
}

void ClientDialog::onReadyRead()
{
    if(tcpSocket.bytesAvailable())
    {
        QByteArray buf = tcpSocket.readAll();
        QTime time = QTime::currentTime();
        QString str = "time : " + time.toString("hh:mm:ss");
        ui->listWidget->addItem(str);
        ui->listWidget->addItem(buf);
        ui->listWidget->scrollToBottom();
    }
}

void ClientDialog::onError()
{
    QMessageBox::critical(this,"ERROR",tcpSocket.errorString());
}
