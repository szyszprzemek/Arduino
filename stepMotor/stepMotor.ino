#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 13

int steps = 0;
boolean motorDirection = true;
unsigned long timerOld, currentMillis;
int stepsLeft = 4095;
long timer;

void setup() {
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  while(stepsLeft > 0){
    currentMillis = micros();
    if(currentMillis - timerOld >= 1000){
      stepper(1);
      timer = timer + micros() - timerOld;
      timerOld = micros();
      stepsLeft--;
    }
  }
  Serial.println(timer);
  Serial.println("Wait...!");
  delay(2000);
  motorDirection = !motorDirection;
  stepsLeft = 4095;
}

void stepper(int xw){
  for (int x=0;x<xw;x++){
    switch(steps){
      case 0:
        digitalWrite(IN1, LOW); 
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
      break; 
      case 1:
        digitalWrite(IN1, LOW); 
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, HIGH);
      break; 
      case 2:
        digitalWrite(IN1, LOW); 
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
      break; 
      case 3:
        digitalWrite(IN1, LOW); 
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
      break; 
      case 4:
        digitalWrite(IN1, LOW); 
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
      break; 
      case 5:
        digitalWrite(IN1, HIGH); 
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
      break; 
      case 6:
        digitalWrite(IN1, HIGH); 
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
      break; 
      case 7:
        digitalWrite(IN1, HIGH); 
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
      break; 
      default:
        digitalWrite(IN1, LOW); 
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
      break; 
    }    
    SetDirection();
  }
}
 
void SetDirection(){
  if(motorDirection==1){ steps++;}
  if(motorDirection==0){ steps--; }
  if(steps>7){steps=0;}
  if(steps<0){steps=7; }
}
