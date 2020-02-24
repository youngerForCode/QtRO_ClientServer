#include "Client.h"
#include "ui_Client.h"

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
        m_pInterface->onMessage(msg);
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
    m_pInterface = m_pRemoteNode->acquire<CommonInterfaceReplica>();
    connect(m_pInterface, &CommonInterfaceReplica::sigMessage, this, &Client::onReceiveMsg);
}

