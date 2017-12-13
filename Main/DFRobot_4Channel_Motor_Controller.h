const int Motor_1_S = 3;
const int Motor_1_D = 4;
const int Motor_2_S = 11;
const int Motor_2_D = 12;
const int Motor_3_S = 5;
const int Motor_3_D = 8;
const int Motor_4_S = 6;
const int Motor_4_D = 7;

void init_MotorContorller(){
  
  pinMode(Motor_1_S,OUTPUT);
  pinMode(Motor_1_D,OUTPUT);
  
  pinMode(Motor_2_S,OUTPUT);
  pinMode(Motor_2_D,OUTPUT);
  
  pinMode(Motor_3_S,OUTPUT);
  pinMode(Motor_3_D,OUTPUT);
  
  pinMode(Motor_4_S,OUTPUT);
  pinMode(Motor_4_D,OUTPUT);
}

void runMotor(int Port,int Speed,bool isReverse){
  
}

