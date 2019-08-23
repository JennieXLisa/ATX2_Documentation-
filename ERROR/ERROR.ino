#include <ATX2.h>

#define DRIVER2_IN1 6  
#define DRIVER2_IN2 5  
#define DRIVER2_IN3 4 
#define DRIVER2_IN4 7  
#define DRIVER2_EN1 15
#define DRIVER2_EN2 30
#define ch1 13
#define ch2 14

const int numReadings = 5;
int readings_ch1[numReadings];      // the readings from the analog input
int readings_ch2[numReadings];
int readIndex = 0;              // the index of the current reading
int total_ch1 = 0;                  
int total_ch2 = 0;
int average_ch1 = 0;                
int average_ch2 = 0;


void RC();
void FW(int pwm);
void BW(int pwm);
void TUL(int pwm);
void TUR(int pwm);
void STOP();


void setup(){
  //OK();
  XIO();
  pinMode(DRIVER2_IN1,OUTPUT);
  pinMode(DRIVER2_IN2,OUTPUT);
  pinMode(DRIVER2_EN1,OUTPUT);
  pinMode(DRIVER2_IN4,OUTPUT);
  pinMode(DRIVER2_IN3,OUTPUT);
  pinMode(DRIVER2_EN2,OUTPUT);

  pinMode(ch1,INPUT);
  pinMode(ch2,INPUT);
  Serial.begin(9600);

  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings_ch1[thisReading] = 0;
    readings_ch2[thisReading] = 0;
  }
}



void loop(){
//
//  total_ch1 = total_ch1 - readings_ch1[readIndex];
//  total_ch2 = total_ch2 - readings_ch2[readIndex];
//  readings_ch1[readIndex] = pulseIn(ch1, HIGH, 25000);
//  readings_ch2[readIndex] = pulseIn(ch2, HIGH, 25000);
//  
//  /*
//  double rc1 = pulseIn(ch1, HIGH, 25000);
//  double rc2 = pulseIn(ch2, HIGH, 25000);
//  Serial.print("Normal RC1: ");
//  Serial.print(rc1);
//  Serial.print(" | ");
//  Serial.print("Normal RC2: ");
//  Serial.println(rc2);
//  */
//  delay(10);
//  total_ch1= total_ch1 + readings_ch1[readIndex];
//  total_ch2= total_ch2 + readings_ch2[readIndex];
//  readIndex = readIndex + 1;
//
//  if (readIndex >= numReadings) {
//    readIndex = 0;
//  }
//
//  
//  average_ch1 = total_ch1 / numReadings;
//  average_ch2 = total_ch2 / numReadings;
//  Serial.print("Average RC1: ");
//  Serial.print(average_ch1);
//  Serial.print(" Average RC2: ");
//  Serial.println(average_ch2);
//  glcd(0,1,"%d",average_ch1);
//  glcd(1,1,"%d",average_ch2);
//  if(average_ch2 > 1400 && average_ch2 < 1600 && average_ch1 > 1400 && average_ch1 < 1600)
//  {
//    STOP();
//  }
//  else if(average_ch2 > 1600 && average_ch2 <= 2900 )
//  {
//      int pwm = map(average_ch2, 1600, 2900, 150, 255); //map our speed to 0-255 range
//      FW(pwm);
//  }
//  else if(average_ch2 < 1600 && average_ch2 >= 800)
//  {
//   int pwm = map(average_ch2, 800, 1600, 150, 255); 
//   BW(pwm);
//  }
//  else if(average_ch2 <= 9999 && average_ch2 >= 8999){
//   int pwm = map(average_ch2/1000.0,800,1600,150,255);
//   BW(pwm);
//  }
//  else if(average_ch1 > 1600 && average_ch1 <= 2900)
//  {
//  int pwm = map(average_ch2, 1600, 2900, 150, 255); //map our speed to 0-255 range
//  TUL(pwm);
//  }
//  else if(average_ch1 < 1600 && average_ch1 >= 800)
//  {
//  int pwm = map(average_ch2, 800, 1600, 150, 255); 
//  TUR(pwm);
//  }
  digitalWrite(DRIVER2_IN1,HIGH); //LEFT
  digitalWrite(DRIVER2_IN2,HIGH);
  analogWrite(DRIVER2_EN1,255);

  digitalWrite(DRIVER2_IN4,HIGH); //RIGHT
  digitalWrite(DRIVER2_IN3,LOW);
  analogWrite(DRIVER2_EN2,255);

}

void FW(int pwm){
  digitalWrite(DRIVER2_IN1,HIGH); //LEFT
  digitalWrite(DRIVER2_IN2,LOW);
  analogWrite(DRIVER2_EN1,255);

  digitalWrite(DRIVER2_IN4,HIGH); //RIGHT
  digitalWrite(DRIVER2_IN3,LOW);
  analogWrite(DRIVER2_EN2,255);
  
}


void BW(int pwm){
  digitalWrite(DRIVER2_IN1,HIGH); //LEFT
  digitalWrite(DRIVER2_IN2,HIGH);
  analogWrite(DRIVER2_EN1,pwm);

  digitalWrite(DRIVER2_IN4,HIGH); //RIGHT
  digitalWrite(DRIVER2_IN3,HIGH);
  analogWrite(DRIVER2_EN2,pwm);
}


void STOP(){
   digitalWrite(DRIVER2_IN1,LOW); //LEFT
  digitalWrite(DRIVER2_IN2,LOW);

  digitalWrite(DRIVER2_IN4,LOW); //RIGHT
  digitalWrite(DRIVER2_IN3,LOW);
  
  analogWrite(DRIVER2_EN1,0);
  analogWrite(DRIVER2_EN2,0);
}


void TUL(int pwm){
  digitalWrite(DRIVER2_IN1,HIGH); // LEFT
  digitalWrite(DRIVER2_IN2,HIGH);
  analogWrite(DRIVER2_EN1,255);

  digitalWrite(DRIVER2_IN4,HIGH); //RIGHT
  digitalWrite(DRIVER2_IN3,LOW);
  analogWrite(DRIVER2_EN2,255);
}


void TUR(int pwm){
  digitalWrite(DRIVER2_IN1,HIGH); // LEFT
  digitalWrite(DRIVER2_IN2,LOW);
  analogWrite(DRIVER2_EN1,255);

  digitalWrite(DRIVER2_IN4,HIGH); //RIGHT
  digitalWrite(DRIVER2_IN3,HIGH );
  analogWrite(DRIVER2_EN2,255);
}


