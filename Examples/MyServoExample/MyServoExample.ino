#include <CustServo.h>

CustServo myServo;

void setup(){
  myServo.Number_of_Channels(4);
  delay(100);
  myServo.SetBaud(19200);
}

void loop() {
  for (int i = 0; i <= 180; i+=10){
  myServo.Move(1,i);
  delay(100);
  }
}
