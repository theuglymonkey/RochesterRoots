#ifndef TEMP_SENSORS_H_
#define TEMP_SENSORS_H_
#include "Arduino.h"

class HumidityAndTempSensors
{
private:
  float ambientTemp;
  float soilTemp;
  float humidity;
public:
    HumidityAndTempSensors(void);
    void Setup();
    void RequestAmbientTemp();
    void RequestSoilTemp();
    void RequestHumidity();
    float GetAmbientTemp();
    float GetSoilTemp();
    float GetHumidity();

};

#endif
