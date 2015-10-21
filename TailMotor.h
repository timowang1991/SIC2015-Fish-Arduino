#ifndef TAIL_MOTOR_H
#define TAIL_MOTOR_H

#include <Arduino.h>
#include <Servo.h>

#define TAIL_MOTOR_PIN 3

class TailMotor
{
public:
   TailMotor();
   
private:
   Servo * tailServo;
};

#endif