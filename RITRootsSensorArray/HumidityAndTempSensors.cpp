#include "HumidityAndTempSensors.h"
#include <Wire.h>
#include "HTU21D.h"
#include <OneWire.h>
byte TempSensor1_DS18S20_Pin = 2; // Use this pin for OneWire talking to temp sensor

HTU21D HumiditySensor;

//Connect wire object to temp pin
OneWire DS18S20(TempSensor1_DS18S20_Pin); // on digital pin 2

HumidityAndTempSensors::HumidityAndTempSensors(void)
{

}

void HumidityAndTempSensors::Setup()
{
  HumiditySensor.begin();
}

void HumidityAndTempSensors::RequestAmbientTemp()
{
  ambientTemp = HumiditySensor.readTemperature();
}

void HumidityAndTempSensors::RequestSoilTemp()
{
    //returns the temperature from one DS18S20 in DEG Celsius

    byte data[12];
    byte addr[8];

    if ( !DS18S20.search(addr))
    {
      //no more sensors on chain, reset search
      DS18S20.reset_search();
    }

    if ( OneWire::crc8( addr, 7) != addr[7])
    {
      Serial.println("CRC is not valid!");
    }

    if ( addr[0] != 0x10 && addr[0] != 0x28)
    {
      Serial.print("Device is not recognized");
    }

    DS18S20.reset();
    DS18S20.select(addr);
    DS18S20.write(0x44,1); // start conversion, with parasite power on at the end

    byte present = DS18S20.reset();
    DS18S20.select(addr);
    DS18S20.write(0xBE); // Read Scratchpad


    for (int i = 0; i < 9; i++) // we need 9 bytes
    {
       data[i] = DS18S20.read();
    }

    DS18S20.reset_search();

    byte MSB = data[1];
    byte LSB = data[0];

    float tempRead = ((MSB << 8) | LSB); //using two's compliment
    float TemperatureSum = tempRead / 16;

    soilTemp = TemperatureSum;
}

void HumidityAndTempSensors::RequestHumidity()
{
  humidity = HumiditySensor.readHumidity();
}

float HumidityAndTempSensors::GetAmbientTemp()
{
  return ambientTemp;
}

float HumidityAndTempSensors::GetSoilTemp()
{
  return soilTemp;
}

float HumidityAndTempSensors::GetHumidity()
{
  return humidity;
}
