void initServoController() {
  if (Serial) {
    Serial.begin(9600);
    Serial.flush();
    Serial.println("Servo Controller Connected");
  } else {
    Serial.println("Servo Controller Connected");
  }
}

/*
   This is used to run a servo.
   Position [0,100]
   Channel [1,24]
*/
void servoRun(int Channel, int Position) {
  Position = map(Position, 0, 100, 500, 2500);
  Serial.print("#" + (String)Channel + " P" + (String)Position + " ");
}

/*
   This is used to run a servo.
   Position [0,100]
   Channel [1,24]
   Speed [1,2500]
*/
void servoRun(int Channel, int Position, int Speed) {
  Position = map(Position, 0, 100, 500, 2500);
  Serial.print("#" + (String)Channel + " P" + (String)Position + " S" + (String)Position + " ");
}
/*
   This is used to control a pin as a digitalPin.
*/
void digitalOutput(int Channel, bool Data) {
  char Output = Data ? 'H' : 'L';
  Serial.print("#" + (String)Channel + Output);
}

/*
   This is used to write data to 8 pins.
   Bank 0 Pin:0 - 7
   Bank 1 Pin:8 - 15
   Bank 2 Pin:16 - 23
*/
void digitalWriteByte(int Bank, byte data) {
  Serial.print("#" + (String)Bank + ":" + (String)data);
}

/**
   To get output or input pulse width
*/
void scanPulseWidth(int Channel) {
  Serial.print("QP" + (String)Channel);
}
/**
   You must call updateData() after call any function in this head file;
   after call this, the data in Serial cache will lost.
*/
void updateData() {
  Serial.println("<cr>");
  Serial.println(Serial.read());
  Serial.flush();
}
