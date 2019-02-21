#-------------------------------------------------
#
# Project created by QtCreator 2019-01-11T19:36:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Video
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11
INCLUDEPATH += /home/maxx/develop/OPENCV/include
INCLUDEPATH += /home/maxx/develop/OPENCV/include/opencv2
INCLUDEPATH += /home/maxx/develop/OPENCV/include/opencv2/core
INCLUDEPATH += /home/maxx/develop/OPENCV/include/opencv2/highgui
INCLUDEPATH += /home/maxx/develop/OPENCV/include/opencv2/imgproc
INCLUDEPATH += /home/maxx/develop/OPENCV/include/opencv2/flann
INCLUDEPATH += /home/maxx/develop/OPENCV/include/opencv2/photo
INCLUDEPATH += /home/maxx/develop/OPENCV/include/opencv2/video
INCLUDEPATH += /home/maxx/develop/OPENCV/include/opencv2/features2d
INCLUDEPATH += /home/maxx/develop/OPENCV/include/opencv2/objdetect
INCLUDEPATH += /home/maxx/develop/OPENCV/include/opencv2/calib3d
INCLUDEPATH += /home/maxx/develop/OPENCV/include/opencv2/ml
INCLUDEPATH += /home/maxx/develop/OPENCV/include/opencv2/contrib

SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h

FORMS += \
        mainwindow.ui


LIBS += -L/home/maxx/develop/OPENCV/lib -lopencv_calib3d\
 -lopencv_core\
 -lopencv_dnn\
 -lopencv_features2d\
 -lopencv_flann\
 -lopencv_gapi\
 -lopencv_highgui\
 -lopencv_imgcodecs\
 -lopencv_imgproc\
 -lopencv_ml\
 -lopencv_objdetect\
 -lopencv_photo\
 -lopencv_stitching\
 -lopencv_videoio\
 -lopencv_video
