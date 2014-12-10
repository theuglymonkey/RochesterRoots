#include "appMain.h"
#include "HumidityAndTempSensors.h"
#include "NodeControl.h"
#include "MoistureSensor.h"

NodeControl Node;
HumidityAndTempSensors humTempSense;
MoistureSensor moSensor;
sensorData sensorTx;

AppMain::AppMain(void)
{

}

void AppMain::SetupArduino(void)
{
  Serial.begin(9600);
  Node.Setup();
  humTempSense.Setup();

}

void AppMain::AppMainLoop(void)
{
    SetupArduino();
    sensorTx.request = false;

    //sensorTx.SoilTemp = 15.2;
    //sensorTx.SoilMoisture = 82;
    for(;;)
    {


      humTempSense.RequestAmbientTemp();
      humTempSense.RequestHumidity();
      humTempSense.RequestSoilTemp();
      moSensor.Read();
      sensorTx.SoilMoisture = moSensor.getLevel();
      sensorTx.SoilTemp = humTempSense.GetSoilTemp();
      sensorTx.AmbientTemp = humTempSense.GetAmbientTemp();
      sensorTx.Humidity = humTempSense.GetHumidity();
      Serial.println(sensorTx.SoilMoisture);

      Node.SendSensorDataFromNode(sensorTx);
    }
}
