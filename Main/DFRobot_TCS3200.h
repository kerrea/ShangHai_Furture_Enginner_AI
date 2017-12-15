//  TCS 3200
int LED, OE, S0, S1, S2, S3, Input;
bool inited = false;
bool isLED_Enabled = false;
const int Red = 0;
const int Green = 1;
const int Blue = 2;
const int Clear = 3;
void initTCS3200(int LED_Pin, int OE_Pin, int S0_Pin, int S1_Pin, int S2_Pin, int S3_Pin, int Input_Pin) {
  LED = LED_Pin;
  OE = OE_Pin;
  S0 = S0_Pin;
  S1 = S1_Pin;
  S2 = S2_Pin;
  S3 = S3_Pin;
  pinMode(LED_Pin, OUTPUT);
  pinMode(OE_Pin, OUTPUT);
  pinMode(S0_Pin, OUTPUT);
  pinMode(S1_Pin, OUTPUT);
  pinMode(S2_Pin, OUTPUT);
  pinMode(S3_Pin, OUTPUT);
  pinMode(Input_Pin, INPUT);
  inited = true;
}

void enableLED(bool Enable) {
  if (inited) {
    digitalWrite(LED, Enable);
    isLED_Enabled = Enable;
  }
}

bool getIsLED_Enabled() {
  return isLED_Enabled;
}

/**
   ------------------------------------
   Ratio integer from 0 to 3
   0 Power Down
   1 2%
   2 20%
   3 100%
   ------------------------------------
   Filter Type integer frome 0 to 3
   0 Red
   1 Green
   2 Blue
   3 Clear
   ------------------------------------
*/
long readData(int Ratio, int Type) {
  switch (Ratio) {
    case 0:
      digitalWrite(S0, false);
      digitalWrite(S1, false);
      break;
    case 1:
      digitalWrite(S0, false);
      digitalWrite(S1, true);
      break;
    case 2:
      digitalWrite(S0, true);
      digitalWrite(S1, false);
      break;
    case 3:
      digitalWrite(S0, true);
      digitalWrite(S1, true);
      break;
    default:
      if (Serial.available() > 0) {
        Serial.println("Error Ratio: " + Ratio);
      }
      return 0;
      break;
  }
  switch (Type) {
    case Red:
      digitalWrite(S2, false);
      digitalWrite(S3, false);
      break;
    case Green:
      digitalWrite(S2, true);
      digitalWrite(S3, true);
      break;
    case Blue:
      digitalWrite(S2, false);
      digitalWrite(S3, true);
      break;
    case Clear:
      digitalWrite(S2, true);
      digitalWrite(S3, false);
      break;
    default:
      if (Serial.available() > 0) {
        Serial.println("Error Type: " + Type);
      }
      return 0;
      break;
  }
  return pulseIn(Input, HIGH);
}
