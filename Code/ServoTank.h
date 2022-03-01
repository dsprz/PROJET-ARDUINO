#ifndef SERVO_TANK_H
#define SERVO_TANK_H

#include <Arduino.h>
#include <Servo.h>

class ServoTank
{
   public:
   ServoTank(int servoPin);
   void servoDroite(int angle);
   void servoGauche(int angle);
   
   private:
   int _servoPin;
   Servo _servo;
};

#endif