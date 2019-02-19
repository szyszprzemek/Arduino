void setup() {
  pinMode(7, INPUT_PULLUP);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
}

void loop() {
  
    //green light
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, HIGH);
    delay(500); //Wait for button to get stable 
    while (digitalRead(7) == HIGH) {} //Wait for button

    //yellow light
    digitalWrite(10, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(8, LOW);
    delay(500); //Wait for button to get stable 
    while (digitalRead(7) == HIGH) {} //Wait for button

    //red light
    digitalWrite(10, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    delay(500); //Wait for button to get stable 
    while (digitalRead(7) == HIGH) {} //Wait for button

    //red and yellow lights
    digitalWrite(10, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(8, LOW);
    delay(500); //Wait for button to get stable 
    while (digitalRead(7) == HIGH) {} //Wait for button
}
