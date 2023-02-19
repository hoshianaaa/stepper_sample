#include <Arduino.h>

/*
TB6600 module connected with the ARDUINO:
EN +, DIR + : PUL + (total Yang connection mode)
EN-  5
DIR-  6
PUL-  7
*/
int EN = 5;
int DIR = 6;
int PUL = 7;

boolean  dir = true;

void setup()
{
  pinMode(EN,OUTPUT);
  pinMode(DIR,OUTPUT);
  pinMode(PUL,OUTPUT);
}
void clockwiseRotation(unsigned char rotationspeed)  //
{
    digitalWrite(DIR,LOW);
    digitalWrite(EN,HIGH);  
    digitalWrite(PUL,LOW);
    delay(rotationspeed);
    digitalWrite(PUL,HIGH);
    delay(rotationspeed);
}

void negativeRotation(unsigned char rotationspeed)
{
    digitalWrite(DIR,HIGH);
    digitalWrite(EN,HIGH);
    digitalWrite(PUL,LOW);
    delay(rotationspeed);
    digitalWrite(PUL,HIGH);
    delay(rotationspeed);
}

/*
Multiple_Of_45_Degrees:Stepper motor rotation multiples of 45 degrees;
Speed:Adjust the speed of stepper motor 
*/
void stepByStepClockwiseRotation(unsigned int Multiple_Of_45_Degrees,unsigned int Speed)   //+45.
{
  unsigned int n=0;
  for(n = 0;n < 50 * Multiple_Of_45_Degrees;n++)
  {
    clockwiseRotation(Speed); //The Speed value, the greater the stepper motor rotate Speed is slow
  }
  dir = true;
}

void stepByStepNegativeRotation(unsigned int Multiple_Of_45_Degrees,unsigned int Speed)   //-45.
{
  unsigned int n=0;
  for(n = 0;n < 50 * Multiple_Of_45_Degrees ;n++)
  {
    negativeRotation(Speed);
  }
  dir = false;
}
void loop()
{
    //clockwiseRotation();  
    if(dir)
    {
    delay(5000);
    stepByStepNegativeRotation(35,5);
    delay(1000);
    }
    else
   {
    stepByStepClockwiseRotation(35,5) ;
    delay(1000);
    }
}
