//ESP8266 Setup Function
//Returns 1 if success, 0 if fail
boolean setup_ESP(){
  Serial.println("        Wifi Setup");
  Serial.println("--------------------------");

  //Checking if module available
  delay(1000);
  Serial.println("1)Checking ESP8266");
  delay(1000);
  ESP.print("AT\r\n");
  if(ESP.find("ERROR"))
    Serial.println("Module not responding.");
  serial_dump_ESP();

  //Reset module
  delay(1000);
  Serial.println("2)Resetting ESP8266");
  delay(1000);
  ESP.print("AT+RST\r\n");
  if(ESP.find("ERROR"))
    Serial.println("Reset failed.");
  serial_dump_ESP();

  //Set to station mode
  delay(1000);
  Serial.println("3)Setting operation mode");
  delay(1000);
  ESP.print("AT+CWMODE=1\r\n");// CWMODE = '1';//CWMODE 1=STATION, 2=APMODE, 3=BOTH
  if(ESP.find("ERROR"))
    Serial.println("Mode set failed.");
  serial_dump_ESP();

  //Connecting to network
  delay(1000);
  Serial.println("4) Connecting to network");
  
  ESP.print("AT+CWJAP=\"");// set the SSID AT+CWJAP="SSID","PW"
  ESP.print(SSID_ESP);//from constant 
  ESP.print("\",\"");
  ESP.print(SSID_KEY);//form constant
  ESP.print("\"\r\n");
  if(ESP.find("ERROR"))
    Serial.println("Failed.");   
  serial_dump_ESP();
  delay(6000);
  Serial.println("--------------------------");
}


