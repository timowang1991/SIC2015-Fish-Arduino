#include "FishManager.h"
#include <Servo.h>

FishManager * fishManager;

void setup(){
   Serial.begin(38400); 
   fishManager = new FishManager();
}

void loop(){
   fishManager->Update();
   serialEvent();
}

void serialEvent(){
   while(Serial.available()){
//      Serial.println((char)Serial.read());
      fishManager->UpdateState(Serial.read());
   }
}
