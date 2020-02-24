#include "Server.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("Server"));
    init();
    ui->textEdit->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString msg = ui->lineEdit->text();
    if(!msg.isEmpty())
        m_pInterFace->sendMsg(msg);
    ui->textEdit->append(QString("Server:")+msg);
    ui->lineEdit->clear();
}

void MainWindow::onReceiveMsg(const QString &msg)
{
    ui->textEdit->append(QString("Client:")+ msg);
}

void MainWindow::on_lineEdit_returnPressed()
{
    on_pushButton_clicked();
}

void MainWindow::init()
{
    m_pHost = new QRemoteObjectHost(this);
    m_pHost->setHostUrl(QUrl("local:interfaces"));
    m_pInterFace = new CommonInterface(this);
    m_pHost->enableRemoting(m_pInterFace);
    connect(m_pInterFace, &CommonInterface::sigReceiveMsg, this, &MainWindow::onReceiveMsg);
}

