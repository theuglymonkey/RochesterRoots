#include "appMain.h"
#include "BluetoothHandler.h"
#include "HumidityAndTempSensors.h"
BluetoothHandler bl;
HumidityAndTempSensors humTempSense;

AppMain::AppMain(void)
{

}

void AppMain::SetupArduino(void)
{
  Serial.begin(9600);
  bl.Setup();

}

void AppMain::AppMainLoop(void)
{
    SetupArduino();
    for(;;)
    {
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

    }
}
