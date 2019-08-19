#include <ATX2.h>


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


  digitalWrite(6,HIGH);
  digitalWrite(5,HIGH);
  analogWrite(14,255);

//
  digitalWrite(7,HIGH);
  digitalWrite(4,HIGH);
  analogWrite(13,255);

  digitalWrite(19,HIGH);
  digitalWrite(16,HIGH);
  analogWrite(15,255);

//
  digitalWrite(20,HIGH);
  digitalWrite(17,HIGH);
  analogWrite(30,255);

}
