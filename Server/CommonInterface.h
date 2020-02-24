#ifndef COMMONINTERFACE_H
#define COMMONINTERFACE_H

#include "rep_CommonInterface_source.h"

class CommonInterface : public CommonInterfaceSource
{
    Q_OBJECT
public:
    explicit CommonInterface(QObject *parent = nullptr);
    virtual void onMessage(QString msg) override;
    void sendMsg(const QString &msg);
signals:
    void sigReceiveMsg(const QString &msg);
};

#endif // COMMONINTERFACE_H
