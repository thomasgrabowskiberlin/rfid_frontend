#include "rfidtcpsocket.h"


rfidTCPSocket::rfidTCPSocket(QObject *parent) : QObject(parent)
{

}


int rfidTCPSocket::doConnect()
{

    QString Address;
    int Port;

    socket = new QTcpSocket(this);

    connect(socket, SIGNAL(connected()),this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()),this, SLOT(disconnected()));     
    connect(socket, SIGNAL(bytesWritten(qint64)),this, SLOT(bytesWritten(qint64)));
    connect(socket, SIGNAL(readyRead()),this, SLOT(readyRead()));

    qDebug() << "connecting...";
    Address = this->IPstr;
    Port    = this->Portstr.toInt();

    qDebug() << Address << ":" << Port << endl;

    // this is not blocking call
      socket->connectToHost( Address, Port);
    // we need to wait...
    if(!socket->waitForConnected(5000))
    {
        qDebug() << "Error: " << socket->errorString();
        return 0;
    } else return 1;
}

int rfidTCPSocket::doDisconnect()
{
    QString Z;

    Z = this->IPstr;
    socket->disconnectFromHost();

    return 0;

}

int rfidTCPSocket::connected()
{
    qDebug() << "connected...";

    // Hey server, tell me about you.
    socket->write("HEAD / HTTP/1.0\r\n\r\n\r\n\r\n");
    myTCPSignalconnected();


    return 0;
}

int rfidTCPSocket::disconnected()
{
    qDebug() << "disconnected...";
    TCPSignaldisconnected();
    return 0;
}

int rfidTCPSocket::bytesWritten(qint64 bytes)
{
    qDebug() << bytes << " bytes written...";
    return 0;
}

int rfidTCPSocket::readyRead()
{
    qDebug() << "reading...";

    // read the data from the socket
    //qDebug() << socket->readAll();
    rfidTCPSocket::ReceiveStr=socket->readAll();
    TCPSignalDataReceived();


    return 0;

}

void rfidTCPSocket::myTCPSignalconnected()
{
    emit mySignal();
}

void rfidTCPSocket::TCPSignaldisconnected()
{
    emit SignalDisconnected();
}

void rfidTCPSocket::TCPSignalDataReceived()
{
    emit SignalDataReceived();
}
