#include "LightSensor.h"

LightSensor::LightSensor(void)
{

}

void LightSensor::Setup(uint8_t Pin, int threshold)
{
    sensorPin = Pin;
    thresholdVal = threshold;
}

bool LightSensor::GetSensorState()
{
  bool returnVal = false;
  Serial.println(analogRead(sensorPin));
  if(analogRead(sensorPin) > thresholdVal )
  {
    returnVal = true;
  }

  return returnVal;
}
