#include <MsTimer2.h>

volatile static int Flag_to_take_sample=0;
volatile static int analogTempSensor0 =0;
volatile static int analogTempSensor1 =0;
volatile static int analogTempSensor2 =0;

void Interrupt_To_Set_Sample_Flag ()
{
  Flag_to_take_sample = 1;    // Set sample flag to true
                              //(time to collect data)
}

void setup()
{
  Serial.begin(9600);
  MsTimer2::set(100, Interrupt_To_Set_Sample_Flag);

  // set sample interrupt period to 100 milliseconds
  MsTimer2::start(); // start running the Timer
}

void loop() {
 if (Flag_to_take_sample>0)
 {
    Flag_to_take_sample=0; // clear the sample flag so that you do not

		// sample again until interrupt is triggered again
    // do the main work of the loop

    analogTempSensor0 = analogRead(0);
    analogTempSensor1 = analogRead(1);
    analogTempSensor2 = analogRead(2);

    //Serial.print("Temp0: ");
    Serial.println("A");
    Serial.println(analogTempSensor0, DEC);

    //Serial.print("   ");
    //Serial.print("Temp1: ");
    Serial.println("B");
    Serial.print(analogTempSensor1, DEC);

    //Serial.print("   ");
    //Serial.print("Temp2: ");
    Serial.println("C");
    Serial.print(analogTempSensor2, DEC);
    //Serial.println();
  }
}
