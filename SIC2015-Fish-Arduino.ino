#include "FishManager.h"
#include <Servo.h>

FishManager * fishManager;

void setup(){
   Serial.begin(38400); 
   fishManager = new FishManager();
}

void loop(){
   fishManager->Update();
}

void serialEvent(){
   while(Serial.available()){
      fishManager->UpdateState(Serial.read());
   }
}
