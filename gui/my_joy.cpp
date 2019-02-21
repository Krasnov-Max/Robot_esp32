#include <QDebug>
#include "my_joy.h"
#include "SDL.h"
// main определена и в SDL и в QT, поэтому #undef
#undef main

void my_joy::dowork()
{
  SDL_Event event;

  SDL_InitSubSystem(SDL_INIT_JOYSTICK);
  this->joy = SDL_JoystickOpen(0);
  if (!this->joy)
   {
      qDebug() <<"Couldn't open Joystick 0\n";
      emit signalJoyError("Joystic not found!");

      return ;
  } else {/*
            qDebug() << "Opened Joystick №0\n";
            qDebug() << "Name: " << SDL_JoystickNameForIndex(0) << "\n";
            qDebug() << "Number of Axes: " << SDL_JoystickNumAxes(this->joy) << "\n";
            qDebug() << "Number of Buttons: " << SDL_JoystickNumButtons(this->joy) << "\n";
            qDebug() << "Number of Balls: " << SDL_JoystickNumBalls(this->joy) << "\n";
            qDebug() << "Number of Hats: " << SDL_JoystickNumHats(this->joy) << "\n";
           */ while(!stop_joy)

                {
                    while(SDL_WaitEvent(&event))
                        {
                            switch (event.type)
                                {
                                    case SDL_JOYAXISMOTION:
                                    emit signalAxisChange(event.jaxis.axis, event.jaxis.value);
                                    //   qDebug() << event.jaxis.axis << "----" << event.jaxis.value;
                                    break;
                                    case SDL_JOYBUTTONDOWN:
                                    emit signalButtonPUP(event.jbutton.button, event.jbutton.state);
                                    break;
                                    case SDL_JOYBUTTONUP:
                                    emit signalButtonPUP(event.jbutton.button, event.jbutton.state);
                                    break;
                                    case SDL_JOYHATMOTION:
                                    emit signalHATChange(event.jhat.value);
                                    break;
                                }
                            }
                    }
            }
    return;
}
void my_joy::slotStop()
{
    emit signalFinished();
    stop_joy = true;
  //  qDebug () << "Signal stop;";

}
