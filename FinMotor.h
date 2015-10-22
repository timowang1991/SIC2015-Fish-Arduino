#ifndef FIN_MOTOR_H
#define FIN_MOTOR_H

#include <Arduino.h>
#include <Servo.h>

#define FIN_MOTOR_PIN 6
#define TAIL_DELAY_TIME 30

class FinMotor
{
public:
   FinMotor();
   void Update(unsigned long deltaTime);
private:
   Servo finServo;
   unsigned long delayTime;
   int currentPos;
   bool isFinDown;
};

#endif
