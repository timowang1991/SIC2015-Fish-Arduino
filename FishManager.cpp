#include "FishManager.h"

FishManager::FishManager(){
   bearingSlideMotor = new BearingSlideMotor();
   finMotor = new FinMotor();
   tailMotor = new TailMotor();
}

FishManager::update(){
   switch(state){
      case UP:
      case DOWN:
      case LEFT:
      case RIGHT:
      case FRONT:
      case OPEN_MOUTH:
      case CLOSE_MOUTH:
         break;
   }
}

FishManager::updateState(char newState){
   state = newState;
}