#include "FishManager.h"

FishManager::FishManager(){
   bearingSlideMotor = new BearingSlideMotor();
   finMotor = new FinMotor();
   tailMotor = new TailMotor();
   previous_time = millis();
}

void FishManager::Update(){

   unsigned long current_time = millis();
   unsigned long time_passed = 0;

   if(current_time >= previous_time ){
     time_passed = current_time - previous_time;
   }
   else{
     time_passed = ULONG_MAX - previous_time + current_time;
   }
   
   tailMotor->Update(time_passed);
//   bearingSlideMotor->Update(time_passed);
   finMotor->Update(time_passed);

   previous_time = current_time;
}

void FishManager::UpdateState(char newState){
   state = newState;

   switch(state){
      case UP:
         bearingSlideMotor->BearingSlideUp();
         tailMotor->Forward();
         Serial.println("UP");
         break;
      case DOWN:
         bearingSlideMotor->BearingSlideDown();
         tailMotor->Forward();
         Serial.println("DOWN");
         break;
      case LEFT:
         bearingSlideMotor->BearingSlideStop();
         tailMotor->TurnLeft();
         Serial.println("LEFT");
         break;
      case RIGHT:
         bearingSlideMotor->BearingSlideStop();
         tailMotor->TurnRight();
         Serial.println("RIGHT");
         break;
      case FORWARD:
         bearingSlideMotor->BearingSlideStop();
         tailMotor->Forward();
         Serial.println("FORWARD");
         break;
      case OPEN_MOUTH:
      case CLOSE_MOUTH:
      case NONE:
         bearingSlideMotor->BearingSlideStop();
         tailMotor->Stop();
         Serial.println("NONE");
         break;
   }
}
