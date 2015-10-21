#include "TailMotor.h"

TailMotor::TailMotor(){
   tailServo = new Servo();
   tailServo->attach(TAIL_MOTOR_PIN);
}

