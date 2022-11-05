#include "Interval.h"

Interval::Interval(){
  reset();
}

void Interval::reset(){
  previousMillis = millis();
}

bool Interval::elapsed(unsigned long intervalMillis){
   unsigned long currentMillis = millis();
   if((currentMillis-previousMillis)<intervalMillis){
    return false;
  }
  previousMillis = currentMillis;
  return true;
}
