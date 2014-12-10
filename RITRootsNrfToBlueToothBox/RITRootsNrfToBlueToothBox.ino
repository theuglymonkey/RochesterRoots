#include "appMain.h"
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>


#define NODECOUNT 2

void setup()
{
}

void loop()
{

  AppMain appMain;
  appMain.AppMainLoop();

  //setup nrf stuff with lookuptable
  //tx with nrf
  //wait for nrf data
  //get data and tx through bl

}


String ConstructBluetoothData()
{

}
