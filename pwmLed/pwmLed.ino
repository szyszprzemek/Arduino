#define pinLed 3

int fill = 0;
int change = 5;

void setup() {
  pinMode(pinLed, OUTPUT);
}

void loop() {
  analogWrite(pinLed, fill);

  //change from max to min PWM
  if(fill < 255){
    fill = fill + change;
  } else {
    fill = 0;
  }
  delay(50);
}
