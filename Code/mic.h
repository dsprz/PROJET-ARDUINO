#ifndef MIC_H
#define MIC_H

#include <Arduino.h>

class Mic{
  public:
  Mic(int micPin);
  void readMicrophone();
  
  private:
  int _micPin;
};

#endif
