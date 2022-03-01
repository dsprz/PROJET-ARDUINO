#include "mic.h"
int micVal = 0;

Mic::Mic(int micPin){
  pinMode(micPin, INPUT);
  _micPin = micPin;
}

void Mic::readMicrophone(){
   micVal = analogRead(_micPin);
   Serial.print(F("mic val ")); Serial.println(micVal);
   if (micVal > 600) {
   Serial.println("mic detected");
   }
} 
