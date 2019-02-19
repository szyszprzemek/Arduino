#include <Servo.h>

Servo servomechanism;
int servoPosition = 0;
int change = 6;

void setup() {
  servomechanism.attach(9);
}

void loop() {

  // If position not yet max move servo. If max move to the beginning
  if(servoPosition < 180){
    servomechanism.write(servoPosition);
  } else {
    servoPosition = 0;
  }

  servoPosition =+ change;
  delay(200);
}
