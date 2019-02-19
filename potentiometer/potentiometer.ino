#define pinAnalog 5

int value = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  value = analogRead(pinAnalog);
  Serial.println(value);
  delay(200);
}
