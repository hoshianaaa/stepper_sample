#include <Arduino.h>

/*

ピンリスト

0 TX
1 RX
2
3 pwm
4 
5 pwm
6 pwm
7
8
9 pwm
10 pwm
11 pwm
12
13
14 A0
15 A1
16 A2
17 A3
18 A4
19 A5

*/


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

int command_pin = 2;
int return_pin = 3;

void setup()
{
  pinMode(step_pin, OUTPUT);
  pinMode(dir_pin, OUTPUT);
  pinMode(relay_pin, OUTPUT);
  digitalWrite(dir_pin, HIGH);
  digitalWrite(relay_pin, HIGH);

  pinMode(command_pin, INPUT_PULLUP);
  pinMode(return_pin, OUTPUT);

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
    delayMicroseconds(1000);
    digitalWrite(step_pin, HIGH);
    delayMicroseconds(1000);
  }
}

int deg2step(double deg)
{
  return int(200.0/360.0*deg);
}

double step2deg(int step)
{
  return 360.0/200.0*step;
}

double now_count=0;
int d_count = 0;
double now_deg=0;
double d_deg=90;

int last_command = 0;

int command = 0;

void loop()
{
  command = digitalRead(command_pin);
  Serial.println(command);
  if ((last_command != command) && (command == 0))
  {
    digitalWrite(return_pin, 0);
    now_deg += d_deg;
    d_count = deg2step(now_deg - step2deg(now_count));
    now_count += d_count;

    spinMotor(0,d_count);

    delay(10);
    digitalWrite(return_pin, 1);
  }
  last_command = command;

//  spinMotor(1,200);
//  delay(3000);

}

