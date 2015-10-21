#ifndef FISH_MANAGER_H
#define FISH_MANAGER_H

#include <Arduino.h>
#include "BearingSlideMotor.h"
#include "FinMotor.h"
#include "TailMotor.h"

#define UP '0'
#define DOWN '1'
#define LEFT '2'
#define RIGHT '3'
#define FRONT '4'
#define OPEN_MOUTH '5'
#define CLOSE_MOUTH '6'

class FishManager
{
public:
   FishManager();
   void update();
   void updateState(char);

private:
   char state;

   BearingSlideMotor * bearingSlideMotor;
   FinMotor * finMotor;
   TailMotor * tailMotor;
};

#endif