void setup_ESP(){
  //Checking if module available
  delay(2000);
  Serial.print("AT\r\n");
  //Reset module
  delay(2000);
  Serial.print("AT+RST\r\n");
  //Set to station mode
  delay(5000);
  Serial.print("AT+CWMODE=1\r\n");
  delay(5000);
  Serial.print("AT+CWJAP=\"Test2\",\"helloworld\"\r\n");
  delay(5000);
}


