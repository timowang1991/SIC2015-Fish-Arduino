#ifndef FIN_MOTOR_H
#define FIN_MOTOR_H

#include <Arduino.h>
#include <Servo.h>

#define FIN_MOTOR_PIN 6

class FinMotor
{
public:
   FinMotor();

private:
   Servo * finServo;
};

#endif