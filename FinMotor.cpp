#include "FinMotor.h"

FinMotor::FinMotor(){
   tailServo = new Servo();
   tailServo->attach(FIN_MOTOR_PIN);
}

