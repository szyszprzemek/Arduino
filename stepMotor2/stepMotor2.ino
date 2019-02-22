#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 13

boolean motorDirection = true;
int stepsLeft = 512;

void setup() {
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void stepper(void);

void loop() {

  // just do some movement for tests
  while(stepsLeft > 0){
    if(stepsLeft > 100){ 
      stepper(true, 1000); // 1000 is the min, do not go below
    } else {stepper(false, 1000);}
    stepsLeft--;
  }
  Serial.println("Wait...!");
  delay(2000);
  stepsLeft = 512; // 512 -> 360 degress
}

void stepper(boolean motorDirection, int delayValue){
  
  int x = 0;
  if(!motorDirection){ x = 7;}
  
  while((x < 8) && (x > -1)){
    switch(x){
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
    if(motorDirection){x++;} 
    else {x--;}
    delayMicroseconds(delayValue);
  }
}
