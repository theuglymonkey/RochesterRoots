#ifndef Moisture_SENSORS_H_
#define Moisture_SENSORS_H_
#include "Arduino.h"

class MoistureSensor
{
private:
  float MoistureLevel;

public:
    MoistureSensor(void);
    void Setup();
    void Read();
    float getLevel();


};

#endif
