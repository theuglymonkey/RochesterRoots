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
  //bl.Setup();

}

void AppMain::AppMainLoop(void)
{
    SetupArduino();
    sensorTx.request = false;
    sensorTx.Humidity = 4.56;
    sensorTx.AmbientTemp = 29.2;
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
      Node.SendSensorDataFromNode(sensorTx);
    }
}
