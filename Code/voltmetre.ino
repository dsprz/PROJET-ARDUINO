#include <LiquidCrystal.h>

int battPin = A4;

LiquidCrystal lcd(3, 8, 12, 13, 16, 17);

void setup()
{
  lcd.begin(16,2);
  pinMode(battPin, INPUT);
}

void loop() 
{
  int voltReading = analogRead(battPin);
  float volts = (voltReading/113.7);
  lcd.setCursor(11,0);
  lcd.print(volts);
  lcd.print("V");
  delay(1000);
  lcd.clear();
}
