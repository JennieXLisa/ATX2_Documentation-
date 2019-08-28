#include <ATX2.h>

#define DRIVER2_IN1 6  
#define DRIVER2_IN2 5  
#define DRIVER2_IN3 4 
#define DRIVER2_IN4 7
#define DRIVER2_EN1 30
#define DRIVER2_EN2 26

//LEFT MOTOR
#define DRIVER1_IN1 19   
#define DRIVER1_IN2 16  

#define DRIVER1_IN3 20 
#define DRIVER1_IN4 17

#define DRIVER1_EN1 15
#define DRIVER1_EN2 28

const int numReadings = 5;
int readings_ch1[numReadings];      // the readings from the analog input
int readings_ch2[numReadings];
int readIndex = 0;              // the index of the current reading
int total_ch1 = 0;                  
int total_ch2 = 0;
int average_ch4 = 0;                
int average_ch2 = 0;
int pwm = 0;

void STOP();
void FW(int pwm);
void BW(int pwm);
void TUL();
void TUR();

void setup() {
  // put your setup code here, to run once:
  OK();
  XIO();
  pinMode(13,INPUT);
  pinMode(14,INPUT);
  pinMode(28,OUTPUT);
  pinMode(15,OUTPUT);
  pinMode(30,OUTPUT);
  pinMode(26,OUTPUT);
  
  pinMode(DRIVER2_IN1,OUTPUT);
  pinMode(DRIVER2_IN2,OUTPUT);
  
  pinMode(DRIVER2_IN4,OUTPUT);
  pinMode(DRIVER2_IN3,OUTPUT);
  
  pinMode(DRIVER1_IN1,OUTPUT);
  pinMode(DRIVER1_IN2,OUTPUT);
  //pinMode(DRIVER1_EN1,OUTPUT);
  
  pinMode(DRIVER1_IN4,OUTPUT);
  pinMode(DRIVER1_IN3,OUTPUT);
  //pinMode(DRIVER1_EN2,OUTPUT);
  
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings_ch1[thisReading] = 0;
    readings_ch2[thisReading] = 0;
  }

}

void loop() {
  
  average_ch4 = pulseIn(13, HIGH);
  average_ch2 = pulseIn(14, HIGH);

  setTextColor(GLCD_RED);
  glcd(0,1,"ch4 : %d",average_ch4);
  glcd(1,1,"ch2 : %d",average_ch2);

  if (average_ch4 > 1300 && average_ch4 < 1550 && average_ch2 > 1300 && average_ch2 < 1550){
    SLOW();
    STOP();
  }
  else if (average_ch4 < 1300 && average_ch4 > 900){
    TUL();
  }
  else if (average_ch4 > 9000){
    TUL();
  }
  else if (average_ch4 > 1550 && average_ch4 < 2300){
    TUR();
  }
  else if (average_ch2 < 1300 && average_ch2 > 900){
    pwm = map(average_ch2, 1400, 900, 170, 255);
    glcd(2,1,"PWM : %d",pwm);
    BW(pwm);
  }
  else if ( average_ch2 > 8000){
    pwm = 255;
    glcd(2,1,"PWM : %d",pwm);
    BW(pwm);
  }
  else if (average_ch2 > 1550 && average_ch2 < 2300){
    pwm = map(average_ch2, 1550, 1992, 150, 255);
    glcd(2,1,"PWM : %d",pwm);

    FW(pwm);
  }
  
}


void TUR(){
  digitalWrite(DRIVER2_IN1,HIGH); 
  digitalWrite(DRIVER2_IN2,LOW);
  digitalWrite(DRIVER2_IN4,HIGH);
  digitalWrite(DRIVER2_IN3,LOW);
  analogWrite(DRIVER2_EN1,150);
  analogWrite(DRIVER2_EN2,150);
  
  digitalWrite(DRIVER1_IN4,HIGH); 
  digitalWrite(DRIVER1_IN3,HIGH);
  digitalWrite(DRIVER1_IN1,HIGH); 
  digitalWrite(DRIVER1_IN2,HIGH);
  analogWrite(DRIVER1_EN1,150);
  analogWrite(DRIVER1_EN2,150);
}

void TUL(){
  digitalWrite(DRIVER1_IN4,LOW); 
  digitalWrite(DRIVER1_IN3,HIGH);
  digitalWrite(DRIVER1_IN1,HIGH); 
  digitalWrite(DRIVER1_IN2,LOW);
  analogWrite(DRIVER1_EN1,150);
  analogWrite(DRIVER1_EN2,150);

  digitalWrite(DRIVER2_IN1,HIGH); 
  digitalWrite(DRIVER2_IN2,HIGH);
  digitalWrite(DRIVER2_IN4,HIGH); 
  digitalWrite(DRIVER2_IN3,HIGH);
  analogWrite(DRIVER2_EN1,150);
  analogWrite(DRIVER2_EN2,150);
}

void FW(int pwm){
  digitalWrite(DRIVER2_IN1,HIGH); 
  digitalWrite(DRIVER2_IN2,LOW);
  digitalWrite(DRIVER2_IN4,HIGH);
  digitalWrite(DRIVER2_IN3,LOW);
  analogWrite(DRIVER2_EN1,pwm);
  analogWrite(DRIVER2_EN2,pwm);
  
  digitalWrite(DRIVER1_IN4,LOW); 
  digitalWrite(DRIVER1_IN3,HIGH);
  digitalWrite(DRIVER1_IN1,HIGH); 
  digitalWrite(DRIVER1_IN2,LOW);
  analogWrite(DRIVER1_EN1,pwm);
  analogWrite(DRIVER1_EN2,pwm);
}


void BW(int pwm){
  digitalWrite(DRIVER2_IN1,HIGH); 
  digitalWrite(DRIVER2_IN2,HIGH);
  digitalWrite(DRIVER2_IN4,HIGH); 
  digitalWrite(DRIVER2_IN3,HIGH);
  analogWrite(DRIVER2_EN1,pwm);
  analogWrite(DRIVER2_EN2,pwm);
  
  digitalWrite(DRIVER1_IN4,HIGH); 
  digitalWrite(DRIVER1_IN3,HIGH);
  digitalWrite(DRIVER1_IN1,HIGH); 
  digitalWrite(DRIVER1_IN2,HIGH);
  analogWrite(DRIVER1_EN1,pwm);
  analogWrite(DRIVER1_EN2,pwm);
}


void STOP(){
  digitalWrite(DRIVER2_IN1,LOW); 
  digitalWrite(DRIVER2_IN2,LOW);
  digitalWrite(DRIVER2_IN4,LOW); 
  digitalWrite(DRIVER2_IN3,LOW);
  
  digitalWrite(DRIVER1_IN4,LOW); 
  digitalWrite(DRIVER1_IN3,LOW);
  digitalWrite(DRIVER1_IN1,LOW); 
  digitalWrite(DRIVER1_IN2,LOW);
}


void SLOW(){
  analogWrite(DRIVER1_EN1,155);
  analogWrite(DRIVER1_EN2,155);
  analogWrite(DRIVER2_EN1,155);
  analogWrite(DRIVER2_EN2,155);

  delay(100);
  
  analogWrite(DRIVER1_EN1,100);
  analogWrite(DRIVER1_EN2,100);
  analogWrite(DRIVER2_EN1,100);
  analogWrite(DRIVER2_EN2,100);

  delay(250);



  analogWrite(DRIVER1_EN1,0);
  analogWrite(DRIVER1_EN2,0);
  analogWrite(DRIVER2_EN1,0);
  analogWrite(DRIVER2_EN2,0);


//
//  for( int x = 155; x == 0 ; x--){
//    analogWrite(DRIVER1_EN1,x);
//    analogWrite(DRIVER1_EN2,x);
//    analogWrite(DRIVER2_EN1,x);
//    analogWrite(DRIVER2_EN2,x); 
//    delay(100);
//  } 
}
