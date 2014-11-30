#ifndef BLUETOOTH_HANDLER_H_
#define BLUETOOTH_HANDLER_H_
#include "Arduino.h"
#include "NodeControl.h"
class BluetoothHandler
{
private:
  String txData;
  String rxData;
  sensorData decodedData;
  String encodedData;
public:
    BluetoothHandler(void);
    void Setup(void);
    void EncodeData(sensorData rawData);
    void DecodeData(String Data);
    void RequestBluetoothData();
    void TransmitBluetoothData();
    void SetTxData(String blTxData);
    String GetRxData();
};


#endif
