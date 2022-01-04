#include <TonePlayer.h>

#include <NewPing.h>


const int trig = 10;
const int buzzer = 9;
const int echo = 8;
float distance = 0.0;
TonePlayer tone1 (TCCR1A, TCCR1B, OCR1AH, OCR1AL, TCNT1H, TCNT1L);
void setup() {
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  NewPing sonar(trig, echo, 200);
  distance = sonar.ping_cm();
  Serial.println(distance);
  tone1.tone(220);
}
