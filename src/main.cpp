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
  digitalWrite(relay_pin, HIGH);

  Serial.begin( 9600 );
}


void spinMotor(int direction, int num){
  if(direction == 0){
    digitalWrite(dir_pin, LOW);
  }else{
    digitalWrite(dir_pin, HIGH);
  }

  for(int i=0;i<num;i++)
  {
    digitalWrite(step_pin, LOW);
    delayMicroseconds(2000);
    digitalWrite(step_pin, HIGH);
    delayMicroseconds(2000);
  }
}

void loop()
{
  spinMotor(0,200);
  delay(3000);

  spinMotor(1,200);
  delay(3000);

}

