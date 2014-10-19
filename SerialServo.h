//SerialServo.h
#ifndef SerialServo_h
#define SerialServo_h

#include <Arduino.h>

class SerialServo
{
  Stream & port_; // http://forum.arduino.cc/index.php?topic=190210.0#lastPost  Reply #14
  
  public:
  // constructor
    SerialServo (Stream & port) : port_ (port) { }
  
  // methods
    void Number_of_Channels(uint8_t channel = 4);
    void Move(uint8_t channel, uint8_t position);
	void AdjustLeftRight(uint8_t L, uint8_t R);
	void Calibrate();

  private:
    uint8_t left, right;
    unsigned int ServoNum[35];
};
#endif
