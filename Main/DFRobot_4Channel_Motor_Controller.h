/*
   Name of Pins should like this
   Motor_Port_Function
   S -> Speed Control
   D -> Direction Control
   Port -> [1,4]
*/
const int Motor_1_S = 3;
const int Motor_1_D = 4;
const int Motor_2_S = 11;
const int Motor_2_D = 12;
const int Motor_3_S = 5;
const int Motor_3_D = 8;
const int Motor_4_S = 6;
const int Motor_4_D = 7;
/*
   you must run this first.
   put the function in void setup();
   don't use the pins in arduino programme.
*/
void initMotorController() { // init pins
  pinMode(Motor_1_S, OUTPUT);
  pinMode(Motor_1_D, OUTPUT);
  pinMode(Motor_2_S, OUTPUT);
  pinMode(Motor_2_D, OUTPUT);
  pinMode(Motor_3_S, OUTPUT);
  pinMode(Motor_3_D, OUTPUT);
  pinMode(Motor_4_S, OUTPUT);
  pinMode(Motor_4_D, OUTPUT);
}

/*
  Port int Num [1,4]
  Speed int Num [-100,100]
  isReverse false Forward
  isReverse true Backward
*/
int runMotor(int Port, int Speed, bool isReverse) {

  //  define the pin for control the motor
  int SpeedPin, DirectionPin;
  int result;
  // init PINS
  switch (Port) {
    case 1:
      SpeedPin = Motor_1_S;
      DirectionPin = Motor_1_D;
      break;
    case 2:
      SpeedPin = Motor_2_S;
      DirectionPin = Motor_2_D;
      break;
    case 3:
      SpeedPin = Motor_3_S;
      DirectionPin = Motor_3_D;
      break;
    case 4:
      SpeedPin = Motor_4_S;
      DirectionPin = Motor_4_D;
      break;
    default:
      if (Serial.available() > 0) {
        Serial.print("No such a port: Port " + Port);
        return 1;
      }
      break;
  }
  // Limit the speed
  if (Speed < 0 && Speed >= -100) {
    Speed = -Speed;
    isReverse = !isReverse;
    result = 2;
  } else if (Speed < -100) {
    // exception
    Speed = 100;
    isReverse = !isReverse;
    result = 3;
  } else if (Speed > 100) {
    // exception
    Speed = 100;
    result = 4;
  }
  // map speed for write;
  int Speed_Local = map(Speed, 0, 100, 0, 255);
  // write Direction Data
  if (Port == 1 || Port == 3) {
    digitalWrite(DirectionPin, isReverse);
    result = 0;
  } else if (Port == 2 || Port == 4) {
    digitalWrite(DirectionPin, !isReverse);
    result = 0;
  } else {
    // exception. but upper code have treated this.
    if (Serial.available() > 0) {
      Serial.print("No such a port: Port " + Port);
      return 1;
    }
  }
  analogWrite(SpeedPin, Speed_Local);
  return result;
}
