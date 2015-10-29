#include "BearingSlideMotor.h"

BearingSlideMotor::BearingSlideMotor(){
   pinMode(BEARING_SLIDE_MOTOR_PIN0, OUTPUT);
   pinMode(BEARING_SLIDE_MOTOR_PIN1, OUTPUT);
   currentPos = BEARING_SLIDE_TOTAL_LENGTH / 2;
   duration = 0;
   analogWrite(BEARING_SLIDE_MOTOR_PIN0, BEARING_SLIDE_GROUND_V);
   analogWrite(BEARING_SLIDE_MOTOR_PIN1, BEARING_SLIDE_GROUND_V); 
}

void BearingSlideMotor::BearingSlideDown(){
    Serial.println("SlideDown");
		duration = BEARING_SLIDE_STANDARD_DURATION * 1.5;
		analogWrite(BEARING_SLIDE_MOTOR_PIN0, BEARING_SLIDE_HIGH_V); 
    analogWrite(BEARING_SLIDE_MOTOR_PIN1, BEARING_SLIDE_GROUND_V);   
}

void BearingSlideMotor::BearingSlideUp(){
    Serial.println("SlideUP");
		analogWrite(BEARING_SLIDE_MOTOR_PIN0, BEARING_SLIDE_GROUND_V); 
    analogWrite(BEARING_SLIDE_MOTOR_PIN1, BEARING_SLIDE_HIGH_V); 
}

void BearingSlideMotor::BearingSlideStop(){
    Serial.println("SlideSTOP");
    analogWrite(BEARING_SLIDE_MOTOR_PIN0, BEARING_SLIDE_GROUND_V); 
    analogWrite(BEARING_SLIDE_MOTOR_PIN1, BEARING_SLIDE_GROUND_V); 
}

//
//void BearingSlideMotor::Update(unsigned long deltaTime){
//	if(duration > deltaTime)
//   {
//   		duration -= deltaTime;
//   }
//   else
//   {
//   		digitalWrite(BEARING_SLIDE_MOTOR_PIN0, LOW); 
//    	digitalWrite(BEARING_SLIDE_MOTOR_PIN1, LOW); 
//    	duration = 0;
//   }
//}
