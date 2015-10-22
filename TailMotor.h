#ifndef TAIL_MOTOR_H
#define TAIL_MOTOR_H

#include <Arduino.h>
#include <Servo.h>

#define TAIL_MOTOR_PIN 3

#define TAIL_NONE 0
#define TAIL_FORWARD 1
#define TAIL_LEFT 2
#define TAIL_RIGHT 3
#define TAIL_DELAY_TIME 15

class TailMotor
{
public:
   TailMotor();
   void Forward();
   void TurnLeft();
   void TurnRight();
   void Stop();
   void Update(unsigned long deltaTime);
private:
   Servo tailServo;
   unsigned long delayTime;
   int currentPos;
   int finalPos;
   int state;
};

#endif