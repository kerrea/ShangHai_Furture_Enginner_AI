#include "DFRobot_Veyron_Servo_Driver.h"
#include "DFRobot_TCS3200.h"
#include "DFRobot_4Channel_Motor_Controller.h"
#include "BasicInfo.h"
#include "Bluno_Nano_Sensor.h"
// all #define should put in BasicInfo.h 
void setup(){
  initTCS3200();
  initMotorController();
}

void loop(){
  
}
