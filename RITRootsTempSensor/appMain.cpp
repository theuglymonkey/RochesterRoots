#include "appMain.h"

AppMain::AppMain(void)
{

}

void AppMain::SetupArduino(void)
{
  Serial.begin(9600);


}

void AppMain::AppMainLoop(void)
{
    SetupArduino();
    for(;;)
    {

    }
}
