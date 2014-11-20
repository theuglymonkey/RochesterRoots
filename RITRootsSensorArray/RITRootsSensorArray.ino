#include <SoftwareSerial.h>
#include <Wire.h>
#include "HTU21D.h"

#include <MsTimer2.h>
#include <OneWire.h>

byte bluetoothTx = 10;  // TX-O pin of bluetooth mate, Arduino D4,
byte bluetoothRx = 11;  // RX-I pin of bluetooth mate, Arduino D5

byte TempSensor1_DS18S20_Pin = 2; // Use this pin for OneWire talking to temp sensor

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

HTU21D HumiditySensor;

//Connect wire object to temp pin
OneWire DS18S20(TempSensor1_DS18S20_Pin); // on digital pin 2


String readString;

void setup(void)
{
  Serial.begin(9600);
  bluetooth.begin(9600);
  HumiditySensor.begin();
}

void loop(void)
{
 
 sendSensorDataOverBluetooth(); 
 //float temperature1 = GetTempSesnor1Reading();
 //Serial.println(temperature1);
 
 //float humidity1 = GetHumidityLevel();
 //Serial.println(humidity1);
 
 //float amTemp = GetAmbientTemp();
 //Serial.println(amTemp);
 
 delay(100); //just here to slow down the output so it is easier to read

}

void sendSensorDataOverBluetooth()
{
  float temperature1 = GetTempSesnor1Reading();
  float amTemp = GetAmbientTemp();
  float humidity1 = GetHumidityLevel();
  
  bluetooth.print("SoilTemp,");
  bluetooth.print(String(temperature1));
  bluetooth.print("AmbTemp,");
  bluetooth.print(String(amTemp));
  bluetooth.print("Humidity,");
  bluetooth.print(String(humidity1));
}

float GetTempSesnor1Reading()
{
   //returns the temperature from one DS18S20 in DEG Celsius
  
   byte data[12];
   byte addr[8];
  
   if ( !DS18S20.search(addr)) 
   {
     //no more sensors on chain, reset search
     DS18S20.reset_search();
     return -1000;  
   }
  
   if ( OneWire::crc8( addr, 7) != addr[7]) 
   {
     Serial.println("CRC is not valid!");
     return -1000;
   }
  
   if ( addr[0] != 0x10 && addr[0] != 0x28) 
   {
     Serial.print("Device is not recognized");
     return -1000;
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
   
   return TemperatureSum;
}

float GetAmbientTemp()
{
  return HumiditySensor.readTemperature();
}

float GetHumidityLevel()
{
  return HumiditySensor.readHumidity();
}
