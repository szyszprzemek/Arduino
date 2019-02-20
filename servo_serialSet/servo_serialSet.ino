#include <Servo.h>

Servo servomechanism;

int servoPosition = 0;
int servoPositionOld = 0;

void setup() {
  Serial.begin(9600);
  servomechanism.attach(11);
}

void loop() {

  int valueSensor = analogRead(A0);
  servoPosition = map(valueSensor, 0, 900, 0, 180);

  //debugging print
  Serial.print(valueSensor);
  Serial.print("\t");
  Serial.print(servoPosition);
  Serial.print("\n");

  //perfom movement when diff bigger than 5
  if (abs(servoPosition - servoPositionOld) > 5){
    servomechanism.write(servoPosition); 
    servoPositionOld = servoPosition;
  }
  
  delay(300);
}
