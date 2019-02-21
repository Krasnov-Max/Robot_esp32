#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork/QtNetwork>
#include <QHostAddress>
#include <QKeyEvent>
#include <QImage>
#include <QStatusBar>
#include <QPixmap>
#include <QTextBrowser>
#include <QPlainTextEdit>
#include "packet_typedef.h"
#include "my_joy.h"
#include "tcpip_client.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



signals:
    void signalStopJoy();
    void signalStopVideo();
    void signalStopTCPIP();
    void signalOpenTCP(QString str);
    void signalSendData(my_tcp_packet *pack);
private slots:
   void slotJoy_Axis(int Axis, int Value );
   void slotJoy_Button(int Button, int Stat);
   void slotJoy_HAT(qint8 Value);
   void slotEM_Stop();
   void slotView(QImage pix);
   void slotJoyError(QString str);
   void slotVideoError(QString str);
   void slotTCPIPError(QString str);
   void slotOpen();
   void slotConnected(QString str);
   void slotWinStart();
   void slotProcessExit(int code,QProcess::ExitStatus stat);

private:
    const qint16 hyst = 400;
    const qint16 max_pwm = 1024;
    Ui::MainWindow *ui;
    int ValueLeft , ValueRight;
     my_tcp_packet packet;
     QThread *thread_joy;
     my_joy *Joy;
     tcpip_client *TCPIP;
     qint8 CurrentStateButtons=0;
     QPlainTextEdit *text;
     bool VideoOK = true;
    QTimer *t1;
    double acsererate=0.6;
    bool stop_video = false;
    QProcess *process;
    QStatusBar *mstatusBar;
public:

protected:
     /*
  virtual void keyPressEvent(QKeyEvent *event);
  virtual void keyReleaseEvent(QKeyEvent *event);
  */
};

#endif // MAINWINDOW_H
