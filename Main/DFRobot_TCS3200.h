//  TCS 3200
int LED,OE,S0,S1,S2,S3,Input;
bool inited = false;
bool isLED_Enabled = false;
void initTCS3200(int LED_Pin,int OE_Pin,int S0_Pin,int S1_Pin,int S2_Pin,int S3_Pin,int Input_Pin){
  LED = LED_Pin;
  OE = OE_Pin;
  S0 = S0_Pin;
  S1 = S1_Pin;
  S2 = S2_Pin;
  S3 = S3_Pin;
  pinMode(LED_Pin,OUTPUT);
  pinMode(OE_Pin,OUTPUT);
  pinMode(S0_Pin,OUTPUT);
  pinMode(S1_Pin,OUTPUT);
  pinMode(S2_Pin,OUTPUT);
  pinMode(S3_Pin,OUTPUT);
  pinMode(Input_Pin,INPUT);
  inited = true;
}

void enableLED(bool Enable){
  if(inited){
    digitalWrite(LED,Enable);
    isLED_Enabled = Enable;
  }
}

bool getIsLED_Enabled(){
  return isLED_Enabled;
}



