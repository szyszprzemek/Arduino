#define pinRedLed 8
#define pinGreenLed 9
#define button 10


void setup() {
  Serial.begin(9600)
  ;
  pinMode(pinRedLed, OUTPUT);
  pinMode(pinGreenLed, OUTPUT);
  pinMode(button, INPUT_PULLUP);

  digitalWrite(pinRedLed, LOW);
  digitalWrite(pinGreenLed, LOW);
}

void loop() {
  if(digitalRead(button) == LOW){
    digitalWrite(pinRedLed, LOW); // Red diod off
    digitalWrite(pinGreenLed, HIGH); // Green diod on
  } else {
    digitalWrite(pinRedLed, HIGH); // Red diod on
    digitalWrite(pinGreenLed, LOW); // Green diod off
    Serial.println("ALARM!!!"); //Alarm when button is not pressed
  
    while (digitalRead(button) == HIGH){
      delay(25); //stop in the loop when button not pressed
    }
  }
}
