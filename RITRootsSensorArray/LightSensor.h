#ifndef LIGHT_SENSOR_H_
#define LIGHT_SENSOR_H_
#include "Arduino.h"

class LightSensor
{
private:
  uint8_t sensorPin;
  int thresholdVal;
public:
    LightSensor(void);
    void Setup(uint8_t Pin, int threshold);
    bool GetSensorState();

};

#endif
