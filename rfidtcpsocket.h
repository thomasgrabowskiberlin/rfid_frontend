#ifndef rfidTCPSocket_H
#define rfidTCPSocket_H

#include <QObject>
#include <QString>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>


class rfidTCPSocket : public QObject
{
    Q_OBJECT
public:
    explicit rfidTCPSocket(QObject *parent = 0);
    //char IPstr[255];
    QString IPstr;
    QString Portstr;
    bool    bconntcted;
    QString ReceiveStr;





signals:
    void mySignal();
    void SignalDisconnected();
    void SignalDataReceived();


public slots:
    int connected();
    int disconnected();
    int bytesWritten(qint64 bytes);
    int readyRead();
    int doConnect();
    int doDisconnect();

private:
    QTcpSocket *socket;
    void myTCPSignalconnected();
    void TCPSignaldisconnected();
    void TCPSignalDataReceived();



};

#endif // rfidTCPSocket_H
