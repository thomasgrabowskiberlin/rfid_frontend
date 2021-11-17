#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <ui_dialog.h>
#include <QMainWindow>
#include <QStringListModel>
#include <QSerialPort>
#include <ostream>
#include "rfidtcpsocket.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    rfidTCPSocket rfidTCP;
    rfidTCPSocket* prfidTCP;
    rfidTCPSocket *prfidTCPlokal = new rfidTCPSocket;


private slots:
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void TestOutput(void);
    void on_pushButton_2_clicked();
    void SaveFile();
    void Serialportinfo(void);
    void OpenComPort(void);
    void CloseComPort(void);
    void WriteData(const QByteArray &data);
    void ReadData();
    void GetVersion();
    void ShowInventory();
    void WriteBlock();
    void TCPDataReceived();
    void TCPConnectionClosed();
    void TCPConnectionOpened();
    void ShowChildWindow();
    void HideChildWindow();
    void CreateChild();
    void CloseAll();










private:
    Ui::MainWindow *ui;
    QStringListModel *model;
    QStringListModel *model2;
    QStringList List;
    QStringList List2;
    QSerialPort *serial;
    Ui_Dialog *dialogUI = new Ui_Dialog;
    QDialog *childWindow = new QDialog;


};

#endif // MAINWINDOW_H
