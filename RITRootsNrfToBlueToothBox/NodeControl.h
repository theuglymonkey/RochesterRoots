#ifndef NODE_CONTROL_H_
#define NODE_CONTROL_H_
#include "Arduino.h"

class NodeControl
{
private:
  uint64_t writingPipes[2];
  uint64_t readingPipes[2];
  void NodeLookUp(uint32_t nodeNum, uint64_t &writingPipe, uint64_t &readingPipe);
  void DecodeNodeData(String data, uint32_t &nodeNum);
  void WriteDataToNode(uint64_t writingPipe, uint32_t data);
  String ReadDataFromNode(uint64_t readingPipe);
  
public:
    NodeControl(void);
    void Setup(void);
    void RequestSensorDataFromNode(String nodeData);


};


#endif
