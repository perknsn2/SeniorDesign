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
  if(read_ESP(keyword_OK,sizeof(keyword_OK),5000,0))//go look for keyword "OK" with a 5sec timeout
    Serial.println("Module ready.");
  else
    Serial.println("Module not responding.");
  serial_dump_ESP();

  //Reset module
  delay(1000);
  Serial.println("2)Resetting ESP8266");
  delay(1000);
  ESP.print("AT+RST\r\n");
  if(read_ESP(keyword_ready,sizeof(keyword_OK),5000,0))//go look for keyword "OK" with a 5sec timeout
    Serial.println("Reset successful.");
  else
    Serial.println("Reset failed.");
  serial_dump_ESP();

  //Set to station mode
  delay(1000);
  Serial.println("3)Setting operation mode");
  delay(1000);
  ESP.print("AT+CWMODE=");// set the CWMODE
  ESP.print(CWMODE);//just send what is set in the constant
  ESP.print("\r\n");
  if(read_ESP(keyword_OK,sizeof(keyword_OK),1000,0))//go look for keyword "OK"
    Serial.println("Mode set.");
  else
    Serial.println("Mode set failed.");
  serial_dump_ESP();

  //Connecting to network
  delay(1000);
  Serial.println("4) Connecting to network");
  delay(1000);
  ESP.print("AT+CWJAP=\"");// set the SSID AT+CWJAP="SSID","PW"
  ESP.print(SSID_ESP);//from constant 
  ESP.print("\",\"");
  ESP.print(SSID_KEY);//form constant
  ESP.print("\"\r\n");
  if(read_ESP(keyword_OK,sizeof(keyword_OK),10000,0))//Wait for response
    Serial.println("Connected.");
  else
    Serial.println("Failed.");   
  serial_dump_ESP();

  /*//Check IP Address
  delay(1000);
  Serial.println("5)Finding IP Address");
  delay(7000);
  ESP.print("AT+CIFSR\r\n");
  if(read_ESP(keyword_rn,sizeof(keyword_rn),20000,0)){//look for first \r\n after AT+CIFSR echo - note mode is '0', the ip address is right after this
  if(read_ESP(keyword_rn,sizeof(keyword_rn),20000,1)){//look for second \r\n, and store everything it receives, mode='1'
    //store the ip adress in its variable, ip_address[]
    for(int i=1; i<=(scratch_data_from_ESP[0]-sizeof(keyword_rn)+1); i++)//that i<=... is going to take some explaining, see next lines
       ip_address[i] = scratch_data_from_ESP[i];//fill up ip_address with the scratch data received
                                                //i=1 because i=0 is the length of the data found between the two keywords, BUT this includes the length of the second keyword, so i<= to the length minus
                                                //size of teh keyword, but remember, sizeof() will return one extra, which is going to be subtracted, so I just added it back in +1
    ip_address[0] = (scratch_data_from_ESP[0]-sizeof(keyword_rn)+1);//store the length of ip_address in [0], same thing as before
    Serial.print("IP Address: ");//print it off to verify
    for(int i=15; i<=ip_address[0]-1; i++)//send out the ip address
    Serial.print(ip_address[i]);
    Serial.println("");
  }}//if first \r\n
  else
  Serial.print("Failed");
  serial_dump_ESP();*/
  Serial.println("--------------------------");
}


