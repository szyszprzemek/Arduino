#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup() {
  lcd.begin(16, 2); // deklaration of the type
  lcd.setCursor(0, 0);
  lcd.print("Przemyslaw");
  lcd.setCursor(0,1);
  lcd.print("I Wielki");
}

void loop() {
}
