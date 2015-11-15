#ifndef BEARING_SLIDE_MOTOR_H
#define BEARING_SLIDE_MOTOR_H

#include <Arduino.h>

#define BEARING_SLIDE_MOTOR_PIN0 1
#define BEARING_SLIDE_MOTOR_PIN1 2
#define BEARING_SLIDE_STANDARD_DURATION 200
#define BEARING_SLIDE_DOWN_DELTA_POS_PER_DURATION 10
#define BEARING_SLIDE_UP_DELTA_POS_PER_DURATION 10
#define BEARING_SLIDE_TOTAL_LENGTH 500
#define BEARING_SLIDE_HIGH_V 255
#define BEARING_SLIDE_GROUND_V 0

enum BearingState {
   UP,
   DOWN,
   MIDDLE
};

class BearingSlideMotor
{
public:
   BearingSlideMotor();
   void BearingSlideDown();
   void BearingSlideUp();
   void BearingSlideStop();
   void BearingSlideMiddle();
   void Update(unsigned long deltaTime);
private:
   unsigned long duration;
   int currentPos;
   int lastState;
};

#endif
