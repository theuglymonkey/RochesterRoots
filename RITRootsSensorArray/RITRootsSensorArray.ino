#include "appMain.h"
#include <SoftwareSerial.h>
#include <Wire.h>
#include "HTU21D.h"
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>
//#include <MsTimer2.h>




void setup(void)
{
}

void loop(void)
{
  AppMain appMain;
  appMain.AppMainLoop();

 //float temperature1 = GetTempSesnor1Reading();
 //Serial.println(temperature1);

 //float humidity1 = GetHumidityLevel();
 //Serial.println(humidity1);

 //float amTemp = GetAmbientTemp();
 //Serial.println(amTemp);

 delay(100); //just here to slow down the output so it is easier to read

}
