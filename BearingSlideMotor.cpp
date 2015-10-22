#include "BearingSlideMotor.h"

BearingSlideMotor::BearingSlideMotor(){
   pinMode(BEARING_SLIDE_MOTOR_PIN0, OUTPUT);
   pinMode(BEARING_SLIDE_MOTOR_PIN1, OUTPUT);
   currentPos = BEARING_SLIDE_TOTAL_LENGTH / 2;
   duration = 0;
   digitalWrite(BEARING_SLIDE_MOTOR_PIN0, LOW);
   digitalWrite(BEARING_SLIDE_MOTOR_PIN1, LOW); 
}

void BearingSlideMotor::BearingSlideDown(){

	currentPos += BEARING_SLIDE_DOWN_DELTA_POS_PER_DURATION;

	if (currentPos <= BEARING_SLIDE_TOTAL_LENGTH)
	{
    Serial.println("SlideDown");
		duration = BEARING_SLIDE_STANDARD_DURATION * 1.5;
		digitalWrite(BEARING_SLIDE_MOTOR_PIN0, LOW); 
    digitalWrite(BEARING_SLIDE_MOTOR_PIN1, HIGH);   
	}
	else
	{
		currentPos -= BEARING_SLIDE_DOWN_DELTA_POS_PER_DURATION;
	}
	 Serial.println(currentPos);
}

void BearingSlideMotor::BearingSlideUp(){
   currentPos -= BEARING_SLIDE_UP_DELTA_POS_PER_DURATION;
  
   if (currentPos >= 0)
	{
    Serial.println("SlideUP");
		duration = BEARING_SLIDE_STANDARD_DURATION / 5;
		digitalWrite(BEARING_SLIDE_MOTOR_PIN0, HIGH); 
    digitalWrite(BEARING_SLIDE_MOTOR_PIN1, LOW); 
	}
	else
	{
		currentPos += BEARING_SLIDE_UP_DELTA_POS_PER_DURATION;
	}
  Serial.println(currentPos);
}

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
