#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QImage>
#include <QPixmap>
#include <QDebug>
#include <QMainWindow>
#include <QGraphicsView>
#include <QCloseEvent>
#include "mainwindow.h"
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/video.hpp>
#include <opencv2/videoio.hpp>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->move(570,0);
    using namespace cv;
    using namespace Ui;
  //  capture = new VideoCapture(0);
 //   cv::namedWindow("Video", WINDOW_AUTOSIZE);

    ui->graphicsView->setScene(new QGraphicsScene(this));
    ui->graphicsView->scene()->addItem(&pixmap);
    connect(this, SIGNAL(signalStarted()), this, SLOT(slotStartVideo()));
    this->show();
    emit signalStarted();

}

void MainWindow::slotStartVideo()
{
    qDebug() << "Video start";
    if(capture.isOpened())
    {
       capture.release();
    }

       if(!capture.open(0))
        {
           qDebug() << "Video not open";
           exit(-1);
        }
                cv::Mat frame;
                while(capture.isOpened())
                    {
                        capture >> frame;
                        if(!frame.empty())
                            {
                                qDebug () << "Frame" << frame.rows;
                                QImage qimg(frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);
                                ui->label->setText("X: "+ QString::number(frame.cols));
                                ui->label_3->setText("Y: "+ QString::number(frame.rows));
                                pixmap.setPixmap( QPixmap::fromImage(qimg.rgbSwapped()) );
                               // ui->graphicsView->scene()->addItem(&pixmap);
                                ui->graphicsView->fitInView(&pixmap, Qt::KeepAspectRatio);
//                                IgnoreAspectRatio
//                                KeepAspectRatio
//                                KeepAspectRatioByExpanding
                           }
                    qApp->processEvents();
                }
}
void MainWindow::closeEvent(QCloseEvent *event)
{
    if(capture.isOpened())
    {
        capture.release();
        event->accept();
        exit(0);
    }
    else
    {
        event->accept();
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}
