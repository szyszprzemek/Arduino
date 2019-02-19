#define pinLed 8
#define pinAnalog 5

void setup() {
  Serial.begin(9600);
  pinMode(pinLed, OUTPUT);
}

void loop() {
  int value;
  value = analogRead(pinAnalog); //read fotoresistor's value
  Serial.println(value);
  delay(100);

  // when dark, then ledOn
  if(value < 100){
    digitalWrite(pinLed, HIGH);
  } else {
    digitalWrite(pinLed, LOW);
  }
}
