#include <LiquidCrystal.h>
LiquidCrystal LCD (2, 3, 4, 5, 6, 7);
void setup() {
  // put your setup code here, to run once:
  LCD.begin(16, 2);
  LCD.print("bonjour");
}

void loop() {
  // put your main code here, to run repeatedly:

}
