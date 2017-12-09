int TextToSound(String msg){
  if(Serial.available() > 0){
    Serial.println(msg);
    delay(10);
    Serial.flush();
    return 1;
  }else{
    return 0;
  }
}

