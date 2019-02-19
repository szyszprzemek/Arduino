void setup() {
  pinMode(8, OUTPUT);
  pinMode(7, INPUT_PULLUP);
  digitalWrite(8, LOW);
}

void loop() {
  if(digitalRead(7) == LOW){
    digitalWrite(8, HIGH);
  }else{
    digitalWrite(8, LOW);
  }
}
