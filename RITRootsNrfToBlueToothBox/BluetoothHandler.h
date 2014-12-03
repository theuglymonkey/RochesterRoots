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
  char txDataCA[100];
public:
    BluetoothHandler(void);
    void Setup(void);
    void EncodeData(sensorData rawData);
    void DecodeData(String Data);
    bool RequestBluetoothData();
    void TransmitBluetoothData(sensorData data);
    void SetTxData(String blTxData);
    String GetRxData();
    void ClearRxData();
    String GetEncodedData();
};


#endif
