#include <TonePlayer.h>

#include <NewPing.h>


const int trig = 10;
const int buzzer = 9;
const int echo = 8;
float distance = 0.0;
int pause;

NewPing sonar(trig, echo, 200);
TonePlayer tone1 (TCCR1A, TCCR1B, OCR1AH, OCR1AL, TCNT1H, TCNT1L);
void setup() {
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  distance = sonar.ping_cm();
  Serial.println(distance);
  if(distance < 40 & distance >=30){
    tone1.tone(400);
    }
  if (distance < 30){
    tone1.tone(600);
  }
  if (distance>=40){tone1.noTone();}
}
