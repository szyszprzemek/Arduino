#include <Servo.h>
#include <LiquidCrystal.h>

Servo myservo;  // create servo object to control a servo

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int buttonPin = 7;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

int pos = 0;    // variable to store the servo position
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  //SERVO
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object

  // button and led control
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);

  // LCD
  lcd.begin(16, 2);
  lcd.print("WATER STATION");
}

void loop() {
  buttonState = digitalRead(buttonPin);
  int water_sensor = analogRead(A0); // Incoming analog signal read and appointed sensor
  lcd.setCursor(0, 1);

  if (buttonState == HIGH or water_sensor < 299) {
    digitalWrite(ledPin, HIGH);
    myservo.write(180);
    lcd.print("Open  Valve");
  }
    
  else if(buttonState == LOW and water_sensor > 299){
    digitalWrite(ledPin, LOW);
    myservo.write(0);
    lcd.print("Close Valve");
  }
  
  delay(10);
}
