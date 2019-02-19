#define pinAnalog 5

int value = 0;
float voltage;

void setup() {
  Serial.begin(9600);
}

void loop() {
  value = analogRead(pinAnalog);
  voltage = value * (5.0 / 1024.0); // value in Volts
  Serial.println(voltage);
  delay(200);
}
