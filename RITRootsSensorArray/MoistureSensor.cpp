#include "MoistureSensor.h"

MoistureSensor::MoistureSensor(void)
{

}

void MoistureSensor::Setup()
{

}

void MoistureSensor::Read()
{
  MoistureLevel = analogRead(A0);
}

float MoistureSensor::getLevel()
{
  float moist = (MoistureLevel * (100.0 / 1023.0))-100;
  moist = abs(moist);
  return moist;
}
