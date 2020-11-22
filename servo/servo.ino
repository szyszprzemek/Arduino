
#include <Servo.h>

Servo myservo;  // create servo object to control a servo

const int buttonPin = 7;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

int pos = 0;    // variable to store the servo position
int buttonState = 0;         // variable for reading the pushbutton status


void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object

  // button and led control
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}


void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
    myservo.write(180);
    
  } else {
    digitalWrite(ledPin, LOW);
    myservo.write(0);
  }
  
  delay(10);
}
