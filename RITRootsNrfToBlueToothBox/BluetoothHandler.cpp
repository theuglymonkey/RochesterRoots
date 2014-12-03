#include "BluetoothHandler.h"
#include <SoftwareSerial.h>
int bluetoothTx = 2;  // TX-O pin of bluetooth mate, Arduino D4,
int bluetoothRx = 3;  // RX-I pin of bluetooth mate, Arduino D5

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

BluetoothHandler::BluetoothHandler(void)
{
}

void BluetoothHandler::Setup(void)
{
  //bluetooth.begin(9600);
  Serial1.begin(9600);
}


void BluetoothHandler::EncodeData(sensorData rawData)
{

  encodedData = "HM,"
  + (String)((int)(rawData.Humidity)) + ','
  + "AT,"
  + (String)((int)(rawData.AmbientTemp)) + ','
  + "ST,"
  + (String)((int)(rawData.SoilTemp))+ ","
  + "SM,"
  + (String)((int)(rawData.SoilMoisture));


}

void BluetoothHandler::DecodeData(String Data)
{

}

bool BluetoothHandler::RequestBluetoothData()
{
  bool returnVal = false;
  //Serial.println(rxData);
  //rxData = "";
  while (Serial1.available())
  {
    delay(3);
    char c = Serial1.read();
    rxData += c;
    returnVal = true;
  }
  //Serial.println("done");
  return returnVal;
}

void BluetoothHandler::TransmitBluetoothData(sensorData data)
{
  EncodeData(data);
  Serial.println(encodedData);
  Serial1.print(encodedData);
  delay(300);

}

void BluetoothHandler::SetTxData(String blTxData)
{
  txData = blTxData;

}

void BluetoothHandler::ClearRxData()
{
   rxData = "";
}

String BluetoothHandler::GetRxData()
{
  return rxData;
}

String BluetoothHandler::GetEncodedData()
{
  return encodedData;
}
