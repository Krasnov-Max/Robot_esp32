#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStatusBar>
#include <QtNetwork/QtNetwork>
#include <QTcpSocket>
#include <QHostAddress>
#include <QKeyEvent>
#include <QProcess>
#include "my_joy.h"
#include "tcpip_client.h"
#include <cstdlib>

#define IP "192.168.10.122"
//#define IP "127.0.0.1"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ValueLeft = 0;
    ValueRight = 0;

    thread_joy= new QThread();
    Joy = new my_joy;
     TCPIP = new tcpip_client();

    Joy->moveToThread(thread_joy);



   connect(thread_joy, SIGNAL(started()), Joy, SLOT(dowork()), Qt::DirectConnection);
   connect(Joy, SIGNAL(signalFinished()), thread_joy, SLOT(quit()),Qt::DirectConnection);
   connect(Joy, SIGNAL(signalFinished()), Joy, SLOT(deleteLater()),Qt::DirectConnection);
   connect(thread_joy, SIGNAL(finished()), thread_joy, SLOT(deleteLater()),Qt::DirectConnection);
   connect(this, SIGNAL(signalStopJoy()), Joy, SLOT(slotStop()),Qt::DirectConnection);
/* при запуске потока будет вызван метод run(), который создаст наш объект для джостика,
 *  который будет работать в новом потоке.
 * при завершении работы наш объект передаст потоку сигнал signalFinished() ,
 *  вызвав срабатывание слота quit()
 * наш объект пометит себя для удаления при окончании работы
 * и поток пометит себя для удаления, по окончании работы нашего объекта.
 *  Удаление будет произведено только после полной остановки потока.
 */
   connect(Joy, SIGNAL(signalAxisChange(int, int )), this, SLOT(slotJoy_Axis(int, int )),Qt::DirectConnection);
   connect(Joy, SIGNAL(signalHATChange(qint8)), this, SLOT(slotJoy_HAT(qint8)),Qt::DirectConnection);
   connect(Joy, SIGNAL(signalButtonPUP(int, int)), this, SLOT(slotJoy_Button(int, int)),Qt::DirectConnection);
   connect(Joy, SIGNAL(signalJoyError(QString)), this, SLOT(slotJoyError(QString)),Qt::DirectConnection);

   t1 = new QTimer(this) ;
   t1->start(1000);
   connect(t1, SIGNAL(timeout()), TCPIP, SLOT (slotLifePack()), Qt::DirectConnection);

    ui->setupUi(this);
    this->move(0,0);
    ui->centralWidget->move(0,0);
    mstatusBar = new QStatusBar(this);
    mstatusBar->setGeometry(0,800,500,20);
    text = new QPlainTextEdit(this);
    ui->verticalLayout_4->addWidget(text);
    text->show();

    thread_joy->start();
   thread_joy->setPriority(QThread::HighPriority);

    connect (ui->ConnBut, SIGNAL(clicked(bool)), this, SLOT(slotOpen()));
    connect (ui->CloseBut,SIGNAL(clicked(bool)), TCPIP, SLOT(slotCloseConnection()));
    connect(TCPIP, SIGNAL(signalTCPProblems(QString)), this, SLOT(slotTCPIPError(QString)));
    connect (this, SIGNAL(signalOpenTCP(QString)), TCPIP, SLOT(slotOpenConnection(QString)));
    connect(this, SIGNAL(signalSendData(my_tcp_packet*)), TCPIP, SLOT(slotDataToSend(my_tcp_packet*)) );
    connect (this ,SIGNAL(signalStopTCPIP()), TCPIP, SLOT(slotCloseConnection()));
    connect(TCPIP, SIGNAL(signalIsConnected(QString)), this, SLOT(slotConnected(QString)));
    connect (ui->em_stop, SIGNAL(clicked(bool)), this, SLOT(EM_Stop()));
    ui->LeftUpBar->setValue(0);
    ui->LeftDownBar->setValue(0);
    ui->RightUpBar->setValue(0);
    ui->RightDownBar->setValue(0);
    ui->LeftDownBar->setMaximum(32767);
    ui->LeftUpBar->setMaximum(32768);
    ui->RightDownBar->setMaximum(32767);
    ui->RightUpBar->setMaximum(32768);
    ui->label->setNum(acsererate);
    process = new QProcess(this);
   // QString file = "/usr/bin/cvlc v4l2:///dev/video0";
    QString file = "/home/maxx/Project/robot/gui/Video/build/Video";
    connect(process, SIGNAL(finished(int,QProcess::ExitStatus)), this, SLOT(slotProcessExit(int,QProcess::ExitStatus)));
    process->setReadChannel (QProcess::StandardError);
    process->start(file);
   // process->exitCode()
   // if (process->exitCode() == -1) {qDebug() << "Exit not video";qApp->exit(-1);};

}
void MainWindow::slotProcessExit(int code,QProcess::ExitStatus stat)
{

            //qDebug() << "Proc exit code: " << code <<"Proc stat: " << stat;
            if (code == 255)
                {
                mstatusBar->showMessage("FPV adapter not found!",5000);
                emit signalStopJoy();
                QThread::sleep(5);
              //  t1->stop();
             //   delete TCPIP;
                qApp->exit(-1);
                }
}
MainWindow::~MainWindow()
{
    delete ui;
}

/*
void MainWindow::keyReleaseEvent(QKeyEvent *event)
{

    if (!event->isAutoRepeat())
     {
        switch (event->key())
        {
          case Qt::Key_A:
            ValueLeft=0;
            emit changeValueLeft(ValueLeft);
          break;
          case Qt::Key_Z:
            ValueLeft=0;
            emit changeValueLeft(ValueLeft);
          break;
          case Qt::Key_K:
            ValueRight=0;
            emit changeValueRight(ValueRight);
          break;
          case Qt::Key_M:
            ValueRight=0;
            emit changeValueRight(ValueRight);
          break;
        }
      }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{

        switch (event->key())
          {
             case Qt::Key_A:
               ValueLeft=ValueLeft+50;
               if (ValueLeft >=ui->Left->maximum()) { ValueLeft = ui->Left->maximum();}
               emit changeValueLeft(ValueLeft);
             break;
             case Qt::Key_Z:
               ValueLeft=ValueLeft-50;
               if (ValueLeft <=ui->Left->minimum()) { ValueLeft = ui->Left->minimum();}
               emit changeValueLeft(ValueLeft);
             break;
             case Qt::Key_K:
               ValueRight=ValueRight+50;
               if (ValueRight >=ui->Right->maximum()) { ValueRight = ui->Right->maximum();}
               emit changeValueRight(ValueRight);
             break;
             case Qt::Key_M:
               ValueRight=ValueRight-50;
               if (ValueRight <=ui->Right->minimum()) { ValueRight = ui->Right->minimum();}
               emit changeValueRight(ValueRight);
             break;
           }
}

*/
void MainWindow::slotJoy_Axis(int Axis, int Value )
{
 //   qDebug() << Axis << Value;
     int ax;
    QString name ;
    my_tcp_packet pack;
    ax = Value;
    switch (Axis)
      {
       case 0:
         name = "Axis X";
       break;
       case 1:
         name = "Axis Y";
         if (ax == 0)
            {
                ui->LeftDownBar->setValue(0);
                ui->LeftUpBar->setValue(0);
         //       my_tcp_packet pack;
                memset(&pack, 0, sizeof(my_tcp_packet));
                pack.start_1 = '+';
                pack.start_2 = '+';
                pack.Left_Right= LeftMotorData;
                pack.Up_Down = StopMotor;
                pack.Value=0;
                pack.distanation=DestanationToMotor;
              //  qDebug() << "send  " <<pack.start_1 << pack.start_2;
                signalSendData(&pack);
            } else
                {
                    if (ax > 0)
                        {
                            ui->LeftDownBar->setValue(ax);
                            ui->LeftUpBar->setValue(0);
                   //         my_tcp_packet pack;
                            memset(&pack, 0, sizeof(my_tcp_packet));
                            pack.start_1 = '+';
                            pack.start_2 = '+';
                            pack.Left_Right= LeftMotorData;
                            pack.Up_Down = DownMotor;
                            pack.Value=ax;
                            pack.distanation=DestanationToMotor;
                            pack.acs = acsererate;
                            signalSendData(&pack);
                        }
                    if (ax < 0)
                        {
                            ui->LeftDownBar->setValue(0);
                            ui->LeftUpBar->setValue(ax*-1);
                 //           my_tcp_packet pack;
                            memset(&pack, 0, sizeof(my_tcp_packet));
                            pack.start_1 = '+';
                            pack.start_2 = '+';
                            pack.Left_Right= LeftMotorData;
                            pack.Up_Down = UpMotor;
                            pack.Value=ax*-1;
                            pack.distanation=DestanationToMotor;
                            pack.acs = acsererate;
                            signalSendData(&pack);
                        }
                }
         //emit changeValueLeft(round(Value*-di));
       break;
       case 2:
         name = "Axis Z";
       break;
       case 4:
        if (ax == 0)
           {
               ui->RightDownBar->setValue(0);
               ui->RightUpBar->setValue(0);
               //my_tcp_packet pack;
               memset(&pack, 0, sizeof(my_tcp_packet));
               pack.start_1 = '+';
               pack.start_2 = '+';
               pack.Left_Right= RightMotorData;
               pack.Up_Down = StopMotor;
               pack.Value=0;
               pack.distanation=DestanationToMotor;
               pack.acs = acsererate;
               signalSendData(&pack);
           } else
               {
                   if (ax > 0)
                       {
                           ui->RightDownBar->setValue(ax);
                           ui->RightUpBar->setValue(0);
                  //         my_tcp_packet pack;
                           memset(&pack, 0, sizeof(my_tcp_packet));
                           pack.start_1 = '+';
                           pack.start_2 = '+';
                           pack.Left_Right= RightMotorData;
                           pack.Up_Down = DownMotor;
                           pack.Value=ax;
                           pack.distanation=DestanationToMotor;
                           pack.acs = acsererate;
                           signalSendData(&pack);
                       }
                   if (ax < 0)
                       {
                           ui->RightDownBar->setValue(0);
                           ui->RightUpBar->setValue(ax*-1);
                    //       my_tcp_packet pack;
                           memset(&pack, 0, sizeof(my_tcp_packet));
                           pack.start_1 = '+';
                           pack.start_2 = '+';
                           pack.Left_Right= RightMotorData;
                           pack.Up_Down = UpMotor;
                           pack.Value=ax*-1;
                           pack.distanation=DestanationToMotor;
                           pack.acs = acsererate;
                           signalSendData(&pack);
                       }
               }
         //emit changeValueRight(round(Value*-di));
         name = "Axis Q";
      }

}

void MainWindow::slotJoy_Button(int Button, int Stat)
{
qDebug() << Button << Stat;
if (Button==0)
    {
    if (Stat==1) {acsererate = acsererate+0.01; if (acsererate>1){acsererate=1;}}
   ui->label->setNum(acsererate);
    }

    if (Button==2)
    {
    if (Stat==1) {acsererate = acsererate-0.01; if (acsererate<0.5){acsererate=0.5;}}
      ui->label->setNum(acsererate);
    }
}
void MainWindow::slotJoy_HAT(qint8 Value)
{

    if ((Value & 0x01) == 1 && (CurrentStateButtons & 0x01)== 0)
        {
            qDebug() << "UP Press";
            //CurrentStateButtons =Value;
        }
    if ( Value == 0 && (CurrentStateButtons & 0x01) == 1)
        {
            qDebug() << "UP UnPress";
            //CurrentStateButtons=Value;
         }
    if ((Value & 0x02) == 2 && (CurrentStateButtons & 0x02) == 0)
        {
            qDebug() << "Right Press";
            //CurrentStateButtons = Value;
        }
    if ( Value == 0 && (CurrentStateButtons & 0x02) == 2)
        {
            qDebug() << "Right UnPress";
            //CurrentStateButtons = Value;
        }
    if ((Value & 0x04) == 4 && (CurrentStateButtons & 0x04) == 0)
        {
            qDebug() << "Down Press";
        }
    if ( Value == 0 && (CurrentStateButtons & 0x04) == 4)
        {
            qDebug() << "Down UnPress";
            //CurrentStateButtons = Value;
        }
    if ((Value & 0x08) == 8 && (CurrentStateButtons & 0x08) == 0)
        {
            qDebug() << "Left Press";
        }
    if ( Value == 0 && (CurrentStateButtons & 0x08) == 8)
        {
            qDebug() << "Left UnPress";
            //CurrentStateButtons = Value;
        }
    CurrentStateButtons = Value;


}
void MainWindow::slotJoyError(QString str)
{
    mstatusBar->showMessage(str,5000);
    emit signalStopJoy();
    QThread::sleep(5);
    t1->stop();
    delete TCPIP;
    qApp->exit(-1);
}
void MainWindow::slotVideoError(QString str)
{
    VideoOK = false;
    QString st;
    st = str;
    mstatusBar->showMessage(st,5000);

}

void MainWindow::slotTCPIPError(QString str)
{
    mstatusBar->showMessage(str,5000);
    text->appendPlainText(str);
    emit signalStopTCPIP();
}
void MainWindow::slotEM_Stop()
{
 /*
 emit changeValueLeft(0);
 emit changeValueRight(0);*/
 ValueRight = 0;
 ValueLeft = 0;
}






void MainWindow::slotConnected( QString str)
{

     mstatusBar->showMessage(str,5000);
     text->appendPlainText(str);
}

void MainWindow::slotView( QImage pix)
{
    //pixmap.setPixmap( QPixmap::fromImage(pix.rgbSwapped()) );
    //ui->graphicsView->fitInView(&pixmap, Qt::KeepAspectRatio);

}

void MainWindow::slotOpen()
{
    qDebug() << "slotOpen_MainWindow";
    QString st = IP;
    emit signalOpenTCP(st);
}

void MainWindow::slotWinStart()
{
//    t2->setInterval(40);
//     t2->start();
//     connect(t2, SIGNAL(timeout()), &Video, SLOT (slotgetTimer2()), Qt::DirectConnection);
//     qDebug () << "Slot T2";
}

