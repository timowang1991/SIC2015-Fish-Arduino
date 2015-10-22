#ifndef FISH_MANAGER_H
#define FISH_MANAGER_H

#include <Arduino.h>
#include "BearingSlideMotor.h"
#include "FinMotor.h"
#include "TailMotor.h"
#include <limits.h>

#define UP '0'
#define DOWN '1'
#define LEFT '2'
#define RIGHT '3'
#define FORWARD '4'
#define OPEN_MOUTH '5'
#define CLOSE_MOUTH '6'
#define NONE '7'

class FishManager
{
public:
   FishManager();
   void Update();
   void UpdateState(char);

private:
   char state;
   unsigned long previous_time;
   BearingSlideMotor * bearingSlideMotor;
   FinMotor * finMotor;
   TailMotor * tailMotor;
};

#endif