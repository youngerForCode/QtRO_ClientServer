#include "Client.h"
#include "ui_Client.h"
#include <QDebug>

Client::Client(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Client)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("Client"));
    init();
    ui->textEdit->setReadOnly(true);
}

Client::~Client()
{
    delete ui;
}
/**
 * @brief MainWidget::onReceiveMsg
 * @param msg
 * 接收服务器下发的消息
 */
void Client::onReceiveMsg(const QString &msg)
{
    ui->textEdit->append(QString("Server:") + msg);
}

void Client::on_pushButton_clicked()
{
    QString msg = ui->lineEdit->text();
    if(!msg.isEmpty())
    {
#ifndef DYNAMIC_REPLICA
     m_pInterface->onMessage(msg); // 调用槽发送消息给服务器
#else
        emit sigSendMsg(msg); //动态Replica时不能直接调用了，会报错找不到这个槽，所以改成连接信号槽的方式
#endif
    }

    ui->textEdit->append(QString("Client:")+msg);
    ui->lineEdit->clear();
}

void Client::on_lineEdit_returnPressed()
{
    on_pushButton_clicked();
}

void Client::init()
{
    m_pRemoteNode = new QRemoteObjectNode(this);
    m_pRemoteNode->connectToNode(QUrl("local:interfaces"));
#ifndef  DYNAMIC_REPLICA
    m_pInterface = m_pRemoteNode->acquire<CommonInterfaceReplica>();
    connect(m_pInterface, &CommonInterfaceReplica::sigMessage, this, &Client::onReceiveMsg);
 #else
    m_pInterface = m_pRemoteNode->acquireDynamic("Interface1");
    // 只有Replica初始化好了之后，才能真正使用它，要不然connect无效。
    connect(m_pInterface, &QRemoteObjectDynamicReplica::initialized,[&](){

        connect(m_pInterface,SIGNAL(sigMessage(QString)),
                this,SLOT(onReceiveMsg(QString)));
        connect(this,SIGNAL(sigSendMsg(QString)),
                m_pInterface,SLOT(onMessage(QString)));
    });
#endif

}



