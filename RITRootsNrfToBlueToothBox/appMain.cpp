#include "appMain.h"
#include "BluetoothHandler.h"
#include "NodeControl.h"

BluetoothHandler bl;
NodeControl nodeNet;

AppMain::AppMain(void)
{

}

void AppMain::SetupArduino(void)
{
  Serial.begin(9600);
  nodeNet.Setup();
  bl.Setup();

}

void AppMain::AppMainLoop(void)
{
    SetupArduino();
    String blData = "test";
    for(;;)
    {
      bl.RequestBluetoothData();
      nodeNet.RequestSensorDataFromNode(bl.GetRxData());
      bl.SetTxData(blData); // set data to transmit
      bl.TransmitBluetoothData();
    }
}
