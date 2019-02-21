#ifndef TCPIP_CLIENT_H
#define TCPIP_CLIENT_H

#include <QObject>
#include <QtNetwork/QtNetwork>
#include <QTcpSocket>
#include <QHostAddress>
#include "packet_typedef.h"

class tcpip_client: public QObject
{
    Q_OBJECT
public:
explicit tcpip_client(QObject *parent = 0);
~tcpip_client();
private slots:
    void slotGetData();
    void slotError(QAbstractSocket::SocketError err);

public slots:
    void dowork();
    void slotStop();
    void slotDataToSend(my_tcp_packet *data);
    void slotOpenConnection(QString str);
    void slotCloseConnection();
    void slotLifePack();

    signals:
    void signalTCPError(QAbstractSocket::SocketError err);
    void signalFinished();
   // void signalDataReady();
    void signalDataSend(my_tcp_packet* data);
    void signalTCPProblems(QString str);
    void signalIsConnected(QString str);
private:
    QTcpSocket *socket_id;
    bool stop_soc = false;
    my_tcp_packet data;
    int i=0;

};

#endif // TCPIP_CLIENT_H
