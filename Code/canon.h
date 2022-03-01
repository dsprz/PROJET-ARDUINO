#ifndef CANON_H
#define CANON_H

#include <Arduino.h>

class Canon
{
  public:
   Canon(int canonPin);
   void tire();
   void desarme();
   int getCanon();
  private:
   int _canonPin;
};
#endif
