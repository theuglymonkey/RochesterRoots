#include "BluetoothHandler.h"
#include <SoftwareSerial.h>
int bluetoothTx = 10;  // TX-O pin of bluetooth mate, Arduino D4,
int bluetoothRx = 11;  // RX-I pin of bluetooth mate, Arduino D5

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

BluetoothHandler::BluetoothHandler(void)
{

}

void BluetoothHandler::BluetoothHandler::Setup(void)
{
  bluetooth.begin(9600);
}


void BluetoothHandler::EncodeData(sensorData rawData)
{
  encodedData = "";
  encodedData = "Humidity" + ','
  + (String)rawData.Humidity + ','
  + "AmbientTemp" + ','
  + (String)rawData.AmbientTemp + ','
  + "SoilTemp" + ','
  + (String)rawData.SoilTemp + ','
  + "SoilMoisture" + ','
  + (String)rawData.SoilMoisture;


}

void BluetoothHandler::DecodeData(String Data)
{
  
}

void BluetoothHandler::RequestBluetoothData()
{
  while (bluetooth.available())
  {
    delay(3);
    char c = bluetooth.read();
    rxData += c;
  }
  if (rxData.length() > 0)
  {
    Serial.println(bluetooth.println(rxData));
    rxData = "";
  }
}

void BluetoothHandler::TransmitBluetoothData()
{
  bluetooth.print(txData);
  delay(4000); //interval between sensor readings
}

void BluetoothHandler::SetTxData(String blTxData)
{
  txData = blTxData;
}

String BluetoothHandler::GetRxData()
{
  return rxData;
}
