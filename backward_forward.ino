#include <ATX2.h>


void fw();
void bw();

void setup(){
    pinMode(6,OUTPUT);
    pinMode(5,OUTPUT);
    pinMode(7,OUTPUT);
    pinMode(4,OUTPUT);
    pinMode(16,OUTPUT);
    pinMode(19,OUTPUT);
    pinMode(20,OUTPUT);
    pinMode(27,OUTPUT);
}

void loop(){
  bw();
}   


void fw(){
    digitalWrite(6,HIGH);
    digitalWrite(5,LOW);
    
    digitalWrite(7,HIGH);
    digitalWrite(4,LOW);

    digitalWrite(19,HIGH);
    digitalWrite(16,LOW);

    digitalWrite(20,HIGH);
    digitalWrite(17,LOW);
}

void bw(){
    digitalWrite(6,HIGH);
    digitalWrite(5,HIGH);
    
    digitalWrite(7,HIGH);
    digitalWrite(4,HIGH);

    digitalWrite(19,HIGH);
    digitalWrite(16,HIGH);

    digitalWrite(20,HIGH);
    digitalWrite(17,HIGH);
}
