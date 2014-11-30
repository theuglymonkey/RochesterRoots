#include "NodeControl.h"
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>


static const uint64_t nodeWritingAddrLookup[3] =
{
  0xF000000001LL, 0xF000000002LL
};

sensorData SA1rx;
sensorData SA1tx;


RF24 radio(9,10);

NodeControl::NodeControl(void)
{
 readingPipes[0] = 0xF000000000LL;
}

void NodeControl::Setup(void)
{
  radio.begin();
  radio.setRetries(15,15);
  delay(100);
}

void NodeControl::RequestSensorDataFromNode(String nodeData)
{
  uint64_t writingAddr;
  uint32_t nodeNum;

  DecodeNodeData(nodeData, nodeNum);

  NodeLookUp(nodeNum,writingAddr);
  WriteDataToNode(writingAddr, SA1tx); //Send Request
  ReadDataFromNode(); // get response
}

void NodeControl::NodeLookUp(uint32_t nodeNum, uint64_t &writingPipe)
{
  writingPipe = nodeWritingAddrLookup[nodeNum];
}

void NodeControl::DecodeNodeData(String data, uint32_t &nodeNum)
{
  nodeNum = 0;
  SA1tx.request = true;
}

void NodeControl::WriteDataToNode(uint64_t writingPipe, sensorData data)
{
  bool dataTransmitted = false;
  uint32_t timoutValue = 0;

  radio.stopListening();
  radio.openWritingPipe(writingPipe);
  dataTransmitted = radio.write(&data, sizeof(data));

}

sensorData NodeControl::ReadDataFromNode()
{
  sensorData incomingData;
  volatile bool done = false;
  radio.openReadingPipe(1,readingPipes[0]);
  radio.startListening();
  delay(5);
  if ( radio.available() )
  {
    while (!done)
    {
      // Fetch the data
      done = radio.read( &incomingData, sizeof(incomingData));
    }
    Serial.print(incomingData.Humidity);
    Serial.print(" ");
    Serial.print(incomingData.AmbientTemp);
    Serial.print(" ");
    Serial.print(incomingData.SoilTemp);
    Serial.print(" ");
    Serial.print(incomingData.SoilMoisture);
    Serial.println(" ");
  }
}
