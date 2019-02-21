#ifndef MY_JOY_H
#define MY_JOY_H
#include <QObject>

#include "SDL.h"

class my_joy: public QObject
{
 Q_OBJECT
public:
     //void run();

public slots:
void  dowork();
void slotStop();

signals:
void signalAxisChange(int Axis, int Value );
void signalButtonPUP(int Button, int Stat);
void signalHATChange(qint8 Value);
void signalJoyError(QString str);
void signalFinished();
private:
 SDL_Joystick *joy;
 bool stop_joy = false;

};

#endif // MY_JOY_H
