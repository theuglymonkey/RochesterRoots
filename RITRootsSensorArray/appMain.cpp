#include "appMain.h"
#include "HumidityAndTempSensors.h"
#include "NodeControl.h"
NodeControl Node;
HumidityAndTempSensors humTempSense;

sensorData sensorTx;

AppMain::AppMain(void)
{

}

void AppMain::SetupArduino(void)
{
  Serial.begin(9600);
  Node.Setup();
  humTempSense.Setup();
  //bl.Setup();

}

void AppMain::AppMainLoop(void)
{
    SetupArduino();
    sensorTx.request = false;

    sensorTx.SoilTemp = 15.2;
    sensorTx.SoilMoisture = 82;
    for(;;)
    {
      /*
        bl.SetTxData("SoilTemp,"); // set data to transmit
        bl.TransmitBluetoothData();
        bl.SetTxData(String(humTempSense.GetSoilTemp())); // set data to transmit
        bl.TransmitBluetoothData();

        bl.SetTxData("AmbTemp,"); // set data to transmit
        bl.TransmitBluetoothData();
        bl.SetTxData(String(humTempSense.GetAmbientTemp())); // set data to transmit
        bl.TransmitBluetoothData();

        bl.SetTxData("Humidity,"); // set data to transmit
        bl.TransmitBluetoothData();
        bl.SetTxData(String(humTempSense.GetHumidity())); // set data to transmit
        bl.TransmitBluetoothData();
      */


      humTempSense.RequestAmbientTemp();
      humTempSense.RequestHumidity();
      sensorTx.AmbientTemp = humTempSense.GetAmbientTemp();
      sensorTx.Humidity = humTempSense.GetHumidity();
      Serial.println(sensorTx.AmbientTemp);

      Node.SendSensorDataFromNode(sensorTx);
    }
}
