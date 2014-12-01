#ifndef NODE_CONTROL_H_
#define NODE_CONTROL_H_
#include "Arduino.h"
typedef struct
{
  bool request;
  bool gotData;
  float Humidity;
  float AmbientTemp;
  float SoilTemp;
  float SoilMoisture;

}sensorData;

class NodeControl
{
private:
  uint64_t writingPipes[2];
  uint64_t readingPipes[2];
  void NodeLookUp(uint32_t nodeNum, uint64_t &writingPipe);
  void DecodeNodeData(String data, uint32_t &nodeNum);
  void WriteDataToNode(uint64_t writingPipe, sensorData data);
  sensorData ReadDataFromNode();
  sensorData inData;

public:
    NodeControl(void);
    void Setup(void);
    void RequestSensorDataFromNode(String nodeData);
    sensorData GetInData();
};



#endif
