#include "BasicInfo.h"
void initServoController() {
  if (Serial) {
    Serial.begin(BaudRate);
    Serial.flush();
    Serial.println("Servo Controller Connected");
  } else {
    Serial.println("Servo Controller Connected");
  }
}

/*
   Position [0,100]
   Channel [1,24]
*/
void servoRun(int Channel, int Position) {
  Position = map(Position, 0, 100, 500, 2500);
  if (duration == 0) {
    Serial.println("#" + (String)Channel + " P" + (String)Position + "<cr>");
  }
}

