#include "FinMotor.h"

FinMotor::FinMotor(){
   finServo.attach(FIN_MOTOR_PIN);
   currentPos = 0;
   finServo.write(currentPos);
   delayTime = TAIL_DELAY_TIME;
   isFinDown = true;
}

void FinMotor::Update(unsigned long deltaTime)
{	
   if(deltaTime >= delayTime)
   {
   		if(isFinDown)
   		{
   			currentPos ++;
   			if (currentPos >= 180)
   				isFinDown = false;
   		}
   		else
   		{
   			currentPos --;
   			if (currentPos <= 0)
   				isFinDown = true;
   		}

   		finServo.write(currentPos);
   		
   		delayTime = TAIL_DELAY_TIME;
   }
   else
   {
   		delayTime -= deltaTime;
   }
}


