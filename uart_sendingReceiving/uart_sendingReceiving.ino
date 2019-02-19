String receivedData = "";

void setup() {
  Serial.begin(9600);
}

void loop() {
  if(Serial.available() > 0){
    receivedData = Serial.readStringUntil('\n'); //receiving all line
    Serial.println("Hello " + receivedData + "!"); //printing
  }
}
