#include "ServoTank.h"


ServoTank::ServoTank(int servoPin){
    Servo _servo;
   _servoPin = servoPin;
   _servo.attach(_servoPin);

}

void ServoTank::servoDroite(int angle){
   _servo.write(angle);
}

void ServoTank::servoGauche(int angle){
   _servo.write(angle);
}
