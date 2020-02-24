#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QRemoteObjectNode>
#include "rep_CommonInterface_replica.h"

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
    CommonInterfaceReplica *m_pInterface = nullptr;
};
#endif // CLIENT_H
