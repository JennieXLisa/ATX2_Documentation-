#include <ATX2.h>

#define DRIVER1_IN1 19
#define DRIVER1_IN2 16
#define DRIVER1_IN3 17
#define DRIVER1_IN4 20
#define DRIVER1_EN1 15
#define DRIVER1_EN2 30


#define DRIVER2_IN1 6
#define DRIVER2_IN2 5
#define DRIVER2_IN3 4
#define DRIVER2_IN4 7 
#define DRIVER2_EN1 14
#define DRIVER2_EN2 13


void setup(){
  OK();
  XIO();
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(14,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(15,OUTPUT);
  pinMode(19,OUTPUT);
  pinMode(20,OUTPUT);
  pinMode(17,OUTPUT);
  pinMode(16,OUTPUT);
  pinMode(30,OUTPUT);
}

void loop(){
  //dirpin 5
  //pwmpin 6
  //Backward is HIGH,HIGH
  //Forward  is HIGH,HIGH
//  digitalWrite(6,HIGH);
//  digitalWrite(5,LOW);
//  analogWrite(14,255);
//
////
//  digitalWrite(7,HIGH);
//  digitalWrite(4,LOW);
//  analogWrite(13,255);
//
//  digitalWrite(19,HIGH);
//  digitalWrite(16,LOW);
//  analogWrite(15,255);
//
////
//  digitalWrite(20,HIGH);
//  digitalWrite(17,LOW);
//  analogWrite(30,255);


  digitalWrite(DRIVER2_IN1,HIGH);
  digitalWrite(DRIVER2_IN2,LOW);
  analogWrite(DRIVER2_EN1,255);

//
  digitalWrite(DRIVER2_IN4,HIGH);
  digitalWrite(DRIVER2_IN3,LOW);
  analogWrite(DRIVER2_EN2,255);

  digitalWrite(DRIVER1_IN1,HIGH);
  digitalWrite(DRIVER1_IN2,LOW);
  analogWrite(DRIVER1_EN1,255);

//
  digitalWrite(DRIVER1_IN4,HIGH);
  digitalWrite(DRIVER1_IN3,LOW);
  analogWrite(DRIVER1_EN2,255);

}
