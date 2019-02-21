#define trigPin 12
#define echoPin 11
#define buzzerPin 13

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  int distance;
  
  distance = measureDistance();
  Serial.print(distance);
  Serial.println(" cm");

  //start buzzer on close distance
  if (distance < 10){
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(buzzerPin, LOW);
  }
  
  delay(500);
}

int measureDistance(){
  long time1;
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  time1 = pulseIn(echoPin, HIGH);
  return time1 / 58;
}
