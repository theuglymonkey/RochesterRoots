#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>
#include <SoftwareSerial.h>

#define NODECOUNT 2

int bluetoothTx = 10;  // TX-O pin of bluetooth mate, Arduino D4,
int bluetoothRx = 11;  // RX-I pin of bluetooth mate, Arduino D5

RF24 radio(9,10);

// Radio pipe addresses for the 2 nodes to communicate.
const uint64_t writingPipes[2] = { 0xF0F0F0F0E1LL, 0xF0F0F0F0D2LL };
const uint64_t readingPipes[2] = { 0xF0F0F0F0E1LL, 0xF0F0F0F0D2LL };

String blStringData;
String

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

static const uint64_t nodeReadingAddrLookup[4] =
{

};
static const uint64_t nodeWritingAddrLookup[4] =
{

};

void setup()
{
  Serial.begin(9600);
  bluetooth.begin(9600);
  radio.begin();

  // optionally, increase the delay between retries & # of retries
  radio.setRetries(15,15);
  delay(100);
}

void loop()
{
  GetBluetoothData(blStringData);
  RequestSensorDataFromNode(blStringData);
  TransmitBluetoothData(String Data);
  //setup nrf stuff with lookuptable
  //tx with nrf
  //wait for nrf data
  //get data and tx through bl

}

void GetBluetoothData(String &data) // pass ref to string
{
  while (bluetooth.available())
  {
    delay(3);
    char c = bluetooth.read();
    data += c;
  }
  if (data.length() > 0)
  {
    Serial.println(bluetooth.println(data));
    data = "";
  }
}

String ConstructBluetoothData()
{

}

void TransmitBluetoothData(String Data)
{
   bluetooth.print(Data);

   delay(4000); //interval between sensor readings
}

void RequestSensorDataFromNode(String nodeData)
{
  uint64_t writingAddr;
  uint64_t readingAddr;
  uint32_t nodeNum;

  DecodeNodeData(nodeData, nodeNum);

  NodeLookUp(nodeNum,writingAddr,readingAddr);
  WriteDataToNode(writingAddr, 0x01); //Send Request
  ReadDataFromNode(readingAddr); // get response
}

void DecodeNodeData(String data, uint32_t &nodeNum)
{

}

void NodeLookUp(uint32_t nodeNum, uint64_t &writingPipe, uint64_t &readingPipe)
{
  readingPipe = nodeReadingAddrLookup[nodeNum];
  writingPipe = nodeWritingAddrLookup[nodeNum];
}

void WriteDataToNode(uint64_t writingPipe, uint32_t data)
{

}

string ReadDataFromNode(uint64_t readingPipe)
{

}
