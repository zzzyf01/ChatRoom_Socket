#include "serverdialog.h"
#include "ui_serverdialog.h"

ServerDialog::ServerDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ServerDialog)
{
    ui->setupUi(this);
    connect(&timer,SIGNAL(timeout()),SLOT(onTimeout()));
    connect(&tcpServer,SIGNAL(newConnection()),this,SLOT(onNewconnection()));
}

ServerDialog::~ServerDialog()
{
    delete ui;
}

//an niu
void ServerDialog::on_creatButton_clicked()
{
    port = 8888;
    if(tcpServer.listen(QHostAddress::Any,port)==true && ui->usernameEdit->text()=="zyf2001" && ui->passwordEdit->text()=="123456")
    {
        qDebug() << "build server successfully!";
        QMessageBox msgBox(
                    QMessageBox::Critical,
                    "Hit",
                    "Login successfully",
                    QMessageBox::Ok,
                    this);
        msgBox.exec();
        ui->sendButton->setEnabled(true);
        ui->creatButton->setEnabled(false);
        ui->usernameEdit->setEnabled(false);
        ui->passwordEdit->setEnabled(false);
        timer.start(3000);
    }
    else
    {
        qDebug() << "build server failed!";
        QMessageBox msgBox(
                    QMessageBox::Critical,
                    "Error",
                    "Uesr Name or Password wrong",
                    QMessageBox::Ok,
                    this);
        msgBox.exec();
    }
}

void ServerDialog::onNewconnection()
{
    QTcpSocket* tcpClient = tcpServer.nextPendingConnection();
    tcpClientList.append(tcpClient);
    connect(tcpClient,SIGNAL(readyRead()),this,SLOT(onReadyRead()));
}

void ServerDialog::onReadyRead()
{
    char names[20][10] = { {"qq"},{"ww"},{"ee"},{"rr"},{"tt"},{"yy"},{"uu"},{"ii"},{"oo"},{"pp"},{"aa"},{"ss"},{"dd"},{"ff"},{"gg"},{"hh"},{"\0"}};
    static char online[20][10] = { "\0"};
    char * names2;
    static int onlinenum = 0;
    int nflag = 0;
    int index = -1;
    for(int i = 0; i < tcpClientList.size(); i++)
    {
        if(tcpClientList.at(i)->bytesAvailable())
        {
            QTime time = QTime::currentTime();
            QString str = "time : " + time.toString("hh:mm:ss");
            QByteArray buf = tcpClientList.at(i)->readAll();
            ui->listWidget->addItem(str);
            ui->listWidget->addItem(buf);
            ui->listWidget->scrollToBottom();
            names2 = buf.data();
            for(int j = 0; j<16;j++){
                if( names2[0] == names[j][0] && names2[1] == names[j][1] && names2[3] == 'e')
                {
                    for(int k = 0; k < onlinenum ; k ++ )
                    {
                        if(online[k][0] == names2[0] && online[k][1] == names2[1])
                        {
                            nflag = 1;
                            break;
                        }
                    }
                    if(nflag == 0)
                    {
                        online[onlinenum][0] = names2[0];
                        online[onlinenum][1] = names2[1];
                        onlinenum ++;
                    }
                }
                else if( names2[0] == names[j][0] && names2[1] == names[j][1] && names2[3] == 'l')
                {
                    qDebug() << "!!!!!!!!!!!!!!!!!";
                    qDebug() <<  onlinenum;
                    qDebug() << online[0][0] + online[0][1] ;
                    for(int k = 0; k < onlinenum ; k ++ )
                    {
                        if(online[k][0] == names2[0] && online[k][1] == names2[1])
                        {
                            qDebug() << "????????????????????";
                            index = k;
                            break;
                        }
                    }
                    if(index != -1)
                    {
                        for(int j = index; j<onlinenum - 1; j++ )
                        {
                            online[j][0] = online[j+1][0];
                            online[j][1] = online[j+1][1];
                        }
                        onlinenum --;
                    }
                }

            }
            sendMessage(buf);
        } 
    }
    qDebug() << onlinenum;
    ui->peopleList->clear();
    for( int j = 0 ; j < onlinenum ; j++)
    {
        ui->peopleList->addItem(QByteArray(online[j]));
    }
}

void ServerDialog::sendMessage(const QByteArray& buf)
{
    for(int i =0; i < tcpClientList.size(); i++)
    {
        tcpClientList.at(i)->write(buf);
    }
}

void ServerDialog::onTimeout()
{
    for(int i = 0; i < tcpClientList.size(); i++)
    {
        if(tcpClientList.at(i)->state() == QAbstractSocket::UnconnectedState)
        {
            tcpClientList.removeAt(i);
            i --;
        }

    }
}

void ServerDialog::on_sendButton_clicked()
{
    QString msg = ui->messageEdit->text();
    if(msg == "")
    {
        return;
    }
    msg = ui->usernameEdit->text() + ":" + msg;
    tcpSocket.write(msg.toUtf8());
    ui->messageEdit->clear();
    QTime time = QTime::currentTime();
    QString str = "time : " + time.toString("hh:mm:ss");
    QByteArray buf = msg.toUtf8();
    ui->listWidget->addItem(str);
    ui->listWidget->addItem(buf);
    ui->listWidget->scrollToBottom();
    sendMessage(buf);


}


