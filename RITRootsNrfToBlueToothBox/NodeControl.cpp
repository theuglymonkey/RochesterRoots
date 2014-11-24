#include "NodeControl.h"
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>

static const uint64_t nodeReadingAddrLookup[4] =
{

};
static const uint64_t nodeWritingAddrLookup[4] =
{

};

const uint64_t writingPipes[2] = { 0xF0F0F0F0E1LL, 0xF0F0F0F0D2LL };
const uint64_t readingPipes[2] = { 0xF0F0F0F0E1LL, 0xF0F0F0F0D2LL };


RF24 radio(9,10);

NodeControl::NodeControl(void)
{

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
  uint64_t readingAddr;
  uint32_t nodeNum;

  DecodeNodeData(nodeData, nodeNum);

  NodeLookUp(nodeNum,writingAddr,readingAddr);
  WriteDataToNode(writingAddr, 0x01); //Send Request
  ReadDataFromNode(readingAddr); // get response
}

void NodeControl::NodeLookUp(uint32_t nodeNum, uint64_t &writingPipe, uint64_t &readingPipe)
{
  readingPipe = nodeReadingAddrLookup[nodeNum];
  writingPipe = nodeWritingAddrLookup[nodeNum];
}

void NodeControl::DecodeNodeData(String data, uint32_t &nodeNum)
{

}

void NodeControl::WriteDataToNode(uint64_t writingPipe, uint32_t data)
{

}

String NodeControl::ReadDataFromNode(uint64_t readingPipe)
{

}
