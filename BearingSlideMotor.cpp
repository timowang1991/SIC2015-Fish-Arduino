#include "BearingSlideMotor.h"

BearingSlideMotor::BearingSlideMotor(){
   pinMode(BEARING_SLIDE_MOTOR_PIN0, OUTPUT);
   pinMode(BEARING_SLIDE_MOTOR_PIN1, OUTPUT);
   currentPos = BEARING_SLIDE_TOTAL_LENGTH / 2;
   duration = 0;
   analogWrite(BEARING_SLIDE_MOTOR_PIN0, BEARING_SLIDE_GROUND_V);
   analogWrite(BEARING_SLIDE_MOTOR_PIN1, BEARING_SLIDE_GROUND_V);

   lastState = MIDDLE;
}

void BearingSlideMotor::BearingSlideDown(){
//    Serial.println("SlideDown");
		duration = BEARING_SLIDE_STANDARD_DURATION * 5;
    analogWrite(BEARING_SLIDE_MOTOR_PIN0, BEARING_SLIDE_GROUND_V);
    analogWrite(BEARING_SLIDE_MOTOR_PIN1, BEARING_SLIDE_HIGH_V);
    lastState = DOWN; 
}

void BearingSlideMotor::BearingSlideUp(){
//    Serial.println("SlideUP");
//    analogWrite(BEARING_SLIDE_MOTOR_PIN0, BEARING_SLIDE_GROUND_V);
    duration = BEARING_SLIDE_STANDARD_DURATION * 5;
    digitalWrite(BEARING_SLIDE_MOTOR_PIN0, HIGH);
//    analogWrite(BEARING_SLIDE_MOTOR_PIN1, BEARING_SLIDE_HIGH_V);
    digitalWrite(BEARING_SLIDE_MOTOR_PIN1, LOW);
    lastState = UP;
}

void BearingSlideMotor::BearingSlideMiddle(){
//    Serial.println("BearingMiddle");
    if (lastState == UP){
        BearingSlideDown();
        duration = BEARING_SLIDE_STANDARD_DURATION * 2.5;
    } else if (lastState == DOWN){
        BearingSlideUp();
        duration = BEARING_SLIDE_STANDARD_DURATION * 2.5;
    }
}

void BearingSlideMotor::BearingSlideStop(){
//    Serial.println("SlideSTOP");
    analogWrite(BEARING_SLIDE_MOTOR_PIN0, BEARING_SLIDE_GROUND_V); 
    analogWrite(BEARING_SLIDE_MOTOR_PIN1, BEARING_SLIDE_GROUND_V); 
}

//
void BearingSlideMotor::Update(unsigned long deltaTime){
	if(duration > deltaTime)
  {
  		duration -= deltaTime;
  }
  else
  {
  	digitalWrite(BEARING_SLIDE_MOTOR_PIN0, LOW); 
   	digitalWrite(BEARING_SLIDE_MOTOR_PIN1, LOW); 
   	duration = 0;
  }
}
