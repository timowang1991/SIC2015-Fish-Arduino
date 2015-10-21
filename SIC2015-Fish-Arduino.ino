#include "FishManager.h"

FishManager * fishManager;

void setup(){
   Serial.begin(115200);
   fishManager = new fishManager();
}

void loop(){
   fishManager->update();
}

void serialEvent(){
   while(Serial.available()){
      fishManager->updateState(Serial.read());
   }
}