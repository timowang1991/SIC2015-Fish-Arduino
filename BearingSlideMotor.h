#ifndef BEARING_SLIDE_MOTOR_H
#define BEARING_SLIDE_MOTOR_H

#include <Arduino.h>

#define BEARING_SLIDE_MOTOR_PIN 5

class BearingSlideMotor
{
public:
   BearingSlideMotor();
   void bearingSlideDown();
   void bearingSlideUp();

private:

};

#endif