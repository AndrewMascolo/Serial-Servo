//SerialServo.cpp

#include "SerialServo.h"
#include "Arduino.h"

void SerialServo::Number_of_Channels(uint8_t channel)
{		
  switch(channel)
  {
    case 4: 
	  left = 7; right = 247;
	  break;
	  
	case 10:
	case 23:
	case 34:
	  left = 15; right = 240;
	  break;	  
  }
  
  
  for(int i = 0; i < (channel + 1); i++)
    ServoNum[i] = i + 48;
}
void SerialServo::AdjustLeftRight(uint8_t L, uint8_t R)
{
  left = L;
  right = R;
}

void SerialServo::Move(uint8_t chan, uint8_t position)
{
  port_.write (ServoNum[chan]);            // What channel to use   
  port_.write (map(position,0,179,left,right)); // send position command
  delay(10);	
} 

void SerialServo::Calibrate()
{	
  for (int j = 1; j <= 5; j++)
  { 
    port_.write(48);                  //time check null channel
    port_.write(left);                   //check 0 degree
  
    delay(1000);                       // Give 1 second between movements
	  
    port_.write(48);                  
    port_.write(127);                 //check 90 degree "CENTER"
	  
    delay(1000);
	  
    port_.write(48);                  
    port_.write(right);                 //check 180 degree
	
	delay(1000);
  }
}