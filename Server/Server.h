#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "CommonInterface.h"
#include <QRemoteObjectHost>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_pushButton_clicked();
    void onReceiveMsg(const QString &msg);
    void on_lineEdit_returnPressed();
private:
    void init();
    Ui::MainWindow *ui;
    CommonInterface *m_pInterFace = nullptr;
    QRemoteObjectHost *m_pHost = nullptr;
};
#endif // MAINWINDOW_H
