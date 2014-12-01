#include "appMain.h"
#include "BluetoothHandler.h"
#include "NodeControl.h"

BluetoothHandler bl;
NodeControl nodeNet;
sensorData test;
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
    //String blData = "test";
    for(;;)
    {
      while(bl.RequestBluetoothData() != true)
      {
      }
//bl.RequestBluetoothData();
      nodeNet.RequestSensorDataFromNode(bl.GetRxData());
      bl.TransmitBluetoothData(nodeNet.GetInData());

    }
}
