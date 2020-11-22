String data="Hello From Arduino!";
int r = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println(data);//data that is being Sent
  if(Serial.available()){         //From RPi to Arduino
    r = r * (Serial.read() - '0');  //conveting the value of chars to integer
    Serial.print("Value: ");
    Serial.println(r);
  }

  if(r==1){
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else{
    digitalWrite(LED_BUILTIN, LOW);
  }
}
