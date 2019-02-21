#include "tcpip_client.h"
#include <QObject>
#include <QtNetwork/QtNetwork>
#include <QTcpSocket>
#include <QHostAddress>
#include "packet_typedef.h"

tcpip_client::tcpip_client(QObject *parent)
{
   // qDebug() << "start" << &socket_id;
    socket_id = new QTcpSocket();
   // qDebug() << "create socket" << &socket_id;
    connect(socket_id,SIGNAL(readyRead()), this, SLOT(slotGetData()));
    //connect(&t1, SIGNAL(timeout()), this, SLOT (slotLifePack()));
    connect( socket_id, SIGNAL(error(QAbstractSocket::SocketError)), this,
             SLOT(slotError(QAbstractSocket::SocketError)), Qt::DirectConnection);
}

void tcpip_client::dowork()
{
    //t1 = new QTimer(this);
    //
    stop_soc=false;
//socket_id=nullptr;
  //  qDebug() << "Thread TCPIP Start";

    int i=0;
    while(1)
        {
  //      if (stop_soc) {break;}
//        qDebug() << "Thread" << i++;
        }
}
void tcpip_client::slotStop()
{
  //  stop_soc = true;
   // socket_id->close();
   // this->~tcpip_client();
}
void tcpip_client::slotDataToSend(my_tcp_packet* data)
{
  //  qDebug() << "sent tcp" << data->start_1 << data->start_2;
    if (socket_id->isOpen())
        {
            qDebug() << data->distanation << data->Left_Right << data->Value;
            socket_id->write((char *)data, sizeof(my_tcp_packet));
        }
}


void tcpip_client::slotGetData()
{
    //qDebug () << "Data read in thread;";
    if (socket_id->bytesAvailable()>0)
        {
            while (1)
                {
                    if (socket_id->bytesAvailable()<sizeof (my_tcp_packet)-1) {qDebug ()<<"break"<< socket_id->bytesAvailable(); return;}
    //                qDebug ()<<"ReadyRead"<< socket_id->bytesAvailable();
    //                qDebug() << "Read" << socket_id->read((char *)&data,sizeof(my_tcp_packet));
    //                qDebug ()<<"last read"<< socket_id->bytesAvailable();
    //                qDebug() << sizeof(my_tcp_packet)<<(char*)&data;
                    emit signalDataSend(&data);
                    memset(&data,0, sizeof (my_tcp_packet));
                }
        }
}
void tcpip_client::slotOpenConnection(QString str)
{


    socket_id->connectToHost(QHostAddress(str), 8787);
   // qDebug () <<"open1";
    if (socket_id->waitForConnected(5000))
        {
     //       qDebug() << "Connection";
            QString str;
            //QHostAddress s = socket_id->peerAddress();
            //s.toString();
            str = socket_id->peerName()+ ":"+ QString::number(socket_id->peerPort());
            signalIsConnected(str);
        }
            else
                {
       //             qDebug() << "not connect" << QString(socket_id->errorString());
                }
    if (socket_id->isOpen())
        {


        }
}
void tcpip_client::slotCloseConnection()
{
    if (socket_id->isOpen()) {socket_id->close();}
}


void tcpip_client::slotLifePack()
{

    if (socket_id==nullptr) {return;}
    my_tcp_packet *life= new(my_tcp_packet);
    life->start_1='+';
    life->start_2='+';
    life->distanation=DestanationToLife;
    life->Up_Down=255;
    life->Left_Right=255;
    life->Value=125;
    if (socket_id->isOpen())
        {
          socket_id->write((char*)life, sizeof(my_tcp_packet));
        }

}

void tcpip_client::slotError(QAbstractSocket::SocketError err)
{
    //qDebug() << "slot error";
    QString strError =
        "Error: " + (err == QAbstractSocket::HostNotFoundError ?
                     "The host was not found." :
                     err == QAbstractSocket::RemoteHostClosedError ?
                     "The remote host is closed." :
                     err == QAbstractSocket::SocketTimeoutError ?
                      "The connection timeout :" :
                     err == QAbstractSocket::ConnectionRefusedError ?
                     "The connection was refused." :
                     QString(socket_id->errorString())
                    );

    emit signalTCPProblems(strError);
}
tcpip_client::~tcpip_client()
{
    socket_id->flush();
    socket_id->close();
    delete socket_id;
}
