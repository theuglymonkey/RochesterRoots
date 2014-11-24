#ifndef BLUETOOTH_HANDLER_H_
#define BLUETOOTH_HANDLER_H_
#include "Arduino.h"

class BluetoothHandler
{
private:
  String txData;
  String rxData;

public:
    BluetoothHandler(void);
    void Setup(void);
    void RequestBluetoothData();
    void TransmitBluetoothData();
    void SetTxData(String blTxData);
    String GetRxData();
};


#endif
