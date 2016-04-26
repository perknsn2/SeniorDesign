//ESP8266 Setup Function
//Returns 1 if success, 0 if fail
boolean setup_ESP(){
  //Checking if module available
  delay(3000);
  ESP.print("AT\r\n");
  if(ESP.find("ERROR"))
    Serial.println("Module not responding.");
  //Reset module
  delay(3000);
  ESP.print("AT+RST\r\n");
  if(ESP.find("ERROR"))
    Serial.println("Reset failed.");
  //Set to station mode
  delay(5000);
  ESP.print("AT+CWMODE=1\r\n");// CWMODE = '1';//CWMODE 1=STATION, 2=APMODE, 3=BOTH
  if(ESP.find("ERROR"))
    Serial.println("Mode set failed.");
  //Connecting to network
  delay(5000);
  ESP.print("AT+CWJAP=\"Test\",\"helloworld\"\r\n");
  if(ESP.find("ERROR"))
    Serial.println("Failed.");   
  Serial.println("--------------------------");
}


