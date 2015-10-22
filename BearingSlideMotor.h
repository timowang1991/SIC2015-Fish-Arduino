#ifndef BEARING_SLIDE_MOTOR_H
#define BEARING_SLIDE_MOTOR_H

#include <Arduino.h>

#define BEARING_SLIDE_MOTOR_PIN0 2
#define BEARING_SLIDE_MOTOR_PIN1 3
#define BEARING_SLIDE_STANDARD_DURATION 200
#define BEARING_SLIDE_DOWN_DELTA_POS_PER_DURATION 10
#define BEARING_SLIDE_UP_DELTA_POS_PER_DURATION 10
#define BEARING_SLIDE_TOTAL_LENGTH 500

class BearingSlideMotor
{
public:
   BearingSlideMotor();
   void BearingSlideDown();
   void BearingSlideUp();
   void Update(unsigned long deltaTime);
private:
   unsigned long duration;
   int currentPos;
};

#endif
