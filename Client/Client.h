#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QRemoteObjectNode>

#ifdef DYNAMIC_REPLICA
#include <QRemoteObjectDynamicReplica>
#else
#include "rep_CommonInterface_replica.h"
#endif


QT_BEGIN_NAMESPACE
namespace Ui { class Client; }
QT_END_NAMESPACE

class Client : public QMainWindow
{
    Q_OBJECT

public:
    Client(QWidget *parent = nullptr);
    ~Client();
public  slots:
    void onReceiveMsg(const QString &msg);
    void on_pushButton_clicked();
    void on_lineEdit_returnPressed();
private:
    void init();
    Ui::Client *ui;
    QRemoteObjectNode *m_pRemoteNode = nullptr;

#ifndef DYNAMIC_REPLICA
    CommonInterfaceReplica *m_pInterface = nullptr;
#else
    QRemoteObjectDynamicReplica *m_pInterface = nullptr;
signals:
    void sigSendMsg(QString msg);
#endif


};
#endif // CLIENT_H
