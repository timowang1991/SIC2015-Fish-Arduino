#include "TailMotor.h"

TailMotor::TailMotor(){
   tailServo.attach(TAIL_MOTOR_PIN);
   currentPos = 90;
   finalPos = 90;
   tailServo.write(currentPos);
   delayTime = TAIL_DELAY_TIME;
   state = TAIL_NONE;
}

void TailMotor::Forward()
{
	state = TAIL_FORWARD;
}

void TailMotor::TurnLeft(){
    state = TAIL_LEFT;
}

void TailMotor::TurnRight()
{
	state = TAIL_RIGHT;
}

void TailMotor::Stop()
{
	state = TAIL_NONE;
}

void TailMotor::Update(unsigned long deltaTime)
{	
	switch(state){
      case TAIL_NONE:
      	finalPos = 90;
      	break;
      case TAIL_FORWARD:
      	if (finalPos == currentPos)
      	{
      		if(finalPos >= 180)
	      	{
	      		finalPos = 0;
	      	}
	      	else
	      	{
	      		finalPos = 180;
	      	}
      	}
      	break;
      case TAIL_LEFT:
      	finalPos = 180;
     	break;
      case TAIL_RIGHT:
      	finalPos = 0;
        break;
   }

   if(deltaTime >= delayTime)
   {
   		if(finalPos > currentPos)
   			currentPos ++;
   		else if(finalPos < currentPos)
   			currentPos --;

   		tailServo.write(currentPos);
   		
   		delayTime = TAIL_DELAY_TIME;
   }
   else
   {
   		delayTime -= deltaTime;
   }
}

