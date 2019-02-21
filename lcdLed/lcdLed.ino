#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

double value = 0.0;
int brightness = 0;
int change = 5;

void setup() {
  lcd.begin(16, 2); // deklaration of the type
  lcd.setCursor(0, 0);
  lcd.print("Voltage [V]");
  lcd.setCursor(0,1);
  lcd.print("0.00");
}

void loop() {
  value = analogRead(A0)*5.0/1024.0;
  lcd.setCursor(0, 1);
  lcd.print(value, 8);

  // PWM to change brigtness of the LCD
  analogWrite(11, brightness);
  brightness = brightness + change;
  
  if (brightness == 0 || brightness == 255){
    change = 0 - change;
  }
  
  delay(100);
}
