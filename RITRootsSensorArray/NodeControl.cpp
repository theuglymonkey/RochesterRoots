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
  readingPipes[0] = 0xF000000001LL;
}

void NodeControl::Setup(void)
{
  radio.begin();
  radio.setRetries(15,15);
  delay(100);
}

void NodeControl::SendSensorDataFromNode(sensorData nodeData)
{
  uint64_t writingAddr = 0xF000000000LL;
  ReadDataFromNode(); // get response
  WriteDataToNode(writingAddr, nodeData); //Send Request
}



void NodeControl::WriteDataToNode(uint64_t writingPipe, sensorData data)
{
  bool dataTransmitted = false;
  uint32_t timoutValue = 0;

  radio.stopListening();
  radio.openWritingPipe(writingPipe);
  delay(5);
  while(dataTransmitted != true)
  {
    dataTransmitted = radio.write(&data, sizeof(data));
  }

}

sensorData NodeControl::ReadDataFromNode()
{
  sensorData incomingData;
  volatile bool done = false;
  incomingData.request = false;
  radio.openReadingPipe(1,readingPipes[0]);
  radio.startListening();
  delay(5);
  while(incomingData.request != true)
  {
    if ( radio.available() )
    {
      while (!done)
      {
        // Fetch the data
        done = radio.read( &incomingData, sizeof(incomingData));
      }
      Serial.println("incoming Request");
      Serial.println(incomingData.request);
    }
  }
}
