#include <Arduino.h>

/*
TB6600 module connected with the ARDUINO:
EN +, DIR + : PUL + (total Yang connection mode)
EN-  5
DIR-  6
PUL-  7
*/
/*
int EN = 5;
int DIR = 6;
int PUL = 7;
*/


int step_pin = 7;
int dir_pin = 6;
int relay_pin = 5;

void setup()
{
  pinMode(step_pin, OUTPUT);
  pinMode(dir_pin, OUTPUT);
  pinMode(relay_pin, OUTPUT);
  digitalWrite(dir_pin, HIGH);
  digitalWrite(relay_pin, LOW);

  Serial.begin( 9600 );
}


void spinMotor(int direction, int num){
  digitalWrite(relay_pin, HIGH);
  if(direction == 0){
    digitalWrite(dir_pin, LOW);
  }else{
    digitalWrite(dir_pin, HIGH);
  }

  for(int i=0;i<num;i++)
  {
    digitalWrite(step_pin, HIGH);
    delayMicroseconds(100);
    digitalWrite(step_pin, LOW);
    delayMicroseconds(100);
  }
 // digitalWrite(relay_pin, );
}

void loop()
{
  spinMotor(0,200*32);
  delay(3000);

  spinMotor(1,200*32);
  delay(3000);

}

