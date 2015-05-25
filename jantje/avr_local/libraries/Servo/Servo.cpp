/*
 Servo.cpp - mockup servo class for local debugging
 */


#include "Servo.h"

Servo::Servo()
{
}

uint8_t Servo::attach(int pin)
{
  return pin;
}

uint8_t Servo::attach(int pin, int min, int max)
{

  return pin ;
}

void Servo::detach()  
{
}

void Servo::write(int value)
{  
}

void Servo::writeMicroseconds(int value)
{
}

int Servo::read() // return the value as degrees
{
  return  0;
}

int Servo::readMicroseconds()
{
  return 0;
}

bool Servo::attached()
{
  return true ;
}

