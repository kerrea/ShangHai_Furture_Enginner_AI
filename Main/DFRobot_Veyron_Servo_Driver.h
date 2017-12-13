#include "BasicInfo.h"
void initServoController(){
  Serial.begin(BaudRate);
  Serial.flush();
  Serial.println("Serial Open success");
}

/*
 * Position [0,100]
 * Channel [1,24]
 */
void servoRun(int Channel,int Position,long duration){
  Position = map(Position,0,100,500,2500);
  if(duration != 0){
    Serial.println("#" + Channel +" P");
  }else{
    Serial.println("#" + Channel +" P" + Position +" T" + duration);
  }
}

