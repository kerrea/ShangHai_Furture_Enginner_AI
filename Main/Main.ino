#include "DFRobot_Veyron_Servo_Driver.h"
//#include "DFRobot_TCS3200.h"
#include "DFRobot_4Channel_Motor_Controller.h"
#include "BasicInfo.h"
// all #define should put in BasicInfo.h

bool isRunning = false;

void setup() {
  initMotorController();
  init
  delay(500);
}

void loop() {
  int Buffer = Serial.read();
  if (Buffer == 100) {
    runMotor(1, 50, false);
    runMotor(2, 50, true);
    isRunning = true;
  } else if (Buffer == 101) {
    runMotor(1, 50, true);
    runMotor(2, 50, false);
    isRunning = true;
  } else if (Buffer == 102) {
    runMotor(1, 50, false);
    runMotor(2, 50, false);
    isRunning = true;
  } else if (Buffer == 103) {
    runMotor(1, 50, true);
    runMotor(2, 50, true);
    isRunning = true;
  }
  if (isRunning) {
    delay(500);
    runMotor(1, 0, false);
    runMotor(2, 0, false);
    isRunning = false;
  }
  if (Serial.available() > 0) {
    Serial.flush();
  }
}
