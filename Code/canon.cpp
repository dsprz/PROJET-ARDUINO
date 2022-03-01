#include "canon.h"

Canon::Canon(int canonPin){
  pinMode(canonPin, OUTPUT);
  _canonPin = canonPin;
}
void Canon::tire()
{
  digitalWrite(_canonPin, HIGH);
}

void Canon::desarme()
{
  digitalWrite(_canonPin , LOW);
}

