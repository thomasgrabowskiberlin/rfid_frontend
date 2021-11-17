#include <QFileDialog>
#include <QSize>
#include <QMessageBox>
#include <QScrollBar>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QSharedPointer>
#include <vector>

#include "mainwindow.h"
#include "rfiddata.h"
#include "ui_mainwindow.h"
#include "ui_dialog.h"







void MainWindow::Serialportinfo(void)
{

qDebug() << "SerialPortInfo\n\n\n";
    // Example use QSerialPortInfo
       foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
             qDebug() << "Name : " << info.portName();

             ui->comboBox->addItem(info.portName());
             qDebug() << "Description : " << info.description();
             qDebug() << "Manufacturer: " << info.manufacturer();
         }

}

void MainWindow::OpenComPort(void)
{
    QString str,str2;

    qDebug() <<  ui->comboBox->currentText();
    //serial.setPort(info[ui->comboBox->currentIndex()]);

    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
          //qDebug() << "Name : " << info.portName();
          str=info.portName();


          if (str == ui->comboBox->currentText() )
          {
              serial->setPortName(str);
              str2=ui->comboBox_2->currentText();
              serial->setBaudRate(str2.toInt());

              if (serial->open(QIODevice::ReadWrite))
              {
                  qDebug() << "success!";
                     ui->label_3->setText("connection opened.");
              }
              else qDebug() << "error!";
          }
      }
}

void MainWindow::CloseComPort(void)
{
    if (serial->isOpen())
        serial->close();

    ui->label_3->setText("connection closed");
}


void MainWindow::WriteData(const QByteArray &data)
{
    serial->write(data);
    qDebug() << data;
}

void MainWindow::GetVersion()
{
    QByteArray data;
    data[1]='v';
    data[2]=0;
    this->WriteData(data);
}

void MainWindow::ShowInventory()
{
    QByteArray data;
    data[1]='x';
    data[2]=0;
    this->WriteData(data);
}

void MainWindow::WriteBlock()
{
    QString str=ui->lineEdit->text();
    QByteArray ar;
    QString strdebug;

    int cnt;
    cnt=0;
    while(str[cnt]!=0)
    {
        ar[cnt]=str.toStdString()[cnt];
        cnt++;
    }

    this->WriteData(ar);
}

void MainWindow::CloseAll()
{

    emit dialogUI->actionClose->triggered();
    close();
}

void MainWindow::ReadData()
{
    QScrollBar *sb = ui->textBrowser->verticalScrollBar();
    QByteArray data = serial->readAll();

    ui->label_4->setText(data);
    ui->textBrowser->insertPlainText(data);

    sb->triggerAction(QScrollBar::SliderToMaximum);
}


void MainWindow::TCPConnectionOpened()
{
    ui->label_5->setText("connected!");
}

void MainWindow::TCPDataReceived()
{
    ui->textBrowser->append(prfidTCPlokal->ReceiveStr);
}

void MainWindow::TCPConnectionClosed()
{
    ui->label_5->setText("Disconnected!");
    ui->textBrowser->append("connection closed!");
}

void MainWindow::ShowChildWindow()
{
    childWindow->show();
}

void MainWindow::HideChildWindow()
{
    childWindow->hide();
}

void MainWindow::CreateChild()
{
    childWindow->show();
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    const QString msg3= "www.google.de";
    int items[] = { 1200,2400,4800,9600,19200,38400,57600,115200 };


    model = new QStringListModel(this);
    model2= new QStringListModel(this);

    model->setStringList(List);
    model2->setStringList(List2);

    serial = new QSerialPort(this);

    ui->setupUi(this);
    dialogUI->setupUi(childWindow);


    ui->action_Quit->setShortcut(tr("CTRL+Q"));
    connect(ui->action_Quit,SIGNAL (triggered()), this, SLOT(close()));
    connect(ui->actionS_peichern,SIGNAL (triggered()), this, SLOT(SaveFile()));
    connect(ui->actionSerialPortInfo, SIGNAL(triggered()), this, SLOT(Serialportinfo()));
    connect(serial, &QSerialPort::readyRead, this, &MainWindow::ReadData);


    ui->textEdit->setText(msg3);
    prfidTCPlokal->IPstr=ui->textEdit->toPlainText();
    prfidTCPlokal->Portstr=ui->textEdit_2->toPlainText();
    connect(prfidTCPlokal, SIGNAL(mySignal()), this, SLOT(TCPDataReceived()));

    connect(prfidTCPlokal, SIGNAL(SignalDisconnected()), this, SLOT(TCPConnectionClosed()));
    connect(prfidTCPlokal, SIGNAL(SignalDataReceived()), this, SLOT(TCPDataReceived()));
    connect(prfidTCPlokal, SIGNAL(mySignal()), this, SLOT(TCPConnectionOpened()));

    connect(ui->pushButton,   SIGNAL (clicked()), (prfidTCPlokal) , SLOT( doConnect() ));
    connect(ui->pushButton_2, SIGNAL (clicked()), (prfidTCPlokal) , SLOT( doDisconnect() ));
    connect(ui->pushButton_3, SIGNAL (clicked()), this,  SLOT(Serialportinfo()));
    connect(ui->pushButton_4, SIGNAL (clicked()), this,  SLOT(OpenComPort()));
    connect(ui->pushButton_5, SIGNAL (clicked()), this,  SLOT(CloseComPort()));
    connect(ui->pushButton_6, SIGNAL (clicked()), this,  SLOT(GetVersion()));
    connect(ui->pushButton_7, SIGNAL (clicked()), this,  SLOT(ShowInventory()));
    connect(ui->pushButton_9, SIGNAL (clicked()), this,  SLOT(WriteBlock()));
    connect(ui->pushButton_10,SIGNAL (clicked()), this,  SLOT(CreateChild()));
    connect(dialogUI->pushButton, SIGNAL(clicked()), this, SLOT(CloseAll()));
    connect(ui->pushButton_11, SIGNAL(clicked()), (this), SLOT(HideChildWindow()));

    ui->comboBox->setModel(model);
    ui->comboBox_2->setModel(model2);

    std::vector<int> BRvec (items, items+sizeof(items) / sizeof(items[0]));

    for(auto Item: BRvec)
        ui->comboBox_2->addItem(QString::number(Item));
    ui->comboBox_2->setCurrentText("19200");
    ui->textEdit_2->setText("80");

}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
     ui->checkBox->click();
     prfidTCPlokal->IPstr=ui->textEdit->toPlainText();
     prfidTCPlokal->Portstr=ui->textEdit_2->toPlainText();
}

void MainWindow::on_pushButton_3_clicked()
{

}

void MainWindow::on_pushButton_2_clicked()
{
      ui->checkBox_2->click();
}

void MainWindow::SaveFile()
{
    QFileDialog saveFile;
    QSize Dialogsize(300, 200);

    saveFile.resize(Dialogsize);

    QString fileName = saveFile.getSaveFileName(this,
           tr("Save RFID Data"), "",
           tr("RFIDdata (*.dat);;All Files (*)"));

    if (fileName.isEmpty())
            return;
        else {
            QFile file(fileName);
            if (!file.open(QIODevice::WriteOnly)) {
                QMessageBox::information(this, tr("Unable to open file"),
                    file.errorString());
                return;
            }
            QDataStream out(&file);
            out.setVersion(QDataStream::Qt_4_5);
            out << "contacts";
        }

}

void MainWindow::TestOutput(void)
{
    qDebug() << "Button pressed!";
}

void TestCall(rfidTCPSocket* tcpsocket)
{
    QString msg2 = "192.168.137.37";

    tcpsocket->doConnect();
}

void updateComboBox(QComboBox *comboToUpdate, const QStringList & list )
{
    QString currentText = comboToUpdate->currentText();
    comboToUpdate->clear();
    comboToUpdate->insertItems(1,list);
    comboToUpdate->setCurrentIndex(comboToUpdate->findText(currentText));
}
