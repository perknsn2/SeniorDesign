
//Pings google.com

void postData(bool gyro, bool accel, int velocity){
  char postData1[30];
  char postData2[20] = "Host: 54.86.75.167";
  sprintf(postData1,"GET /vms/data/%d HTTP/1.1",velocity);
  
  //Serial.println(postData1);
  Serial.println("Connecting to server");
  delay(1000);
  ESP.print("AT+CIPSTART=\"TCP\",\"54.86.75.167\",80\r\n");
  delay(4000);
  if(ESP.find("OK")||ESP.find("ALREADY"))
    Serial.println("Connected to server.");
  else{
    Serial.println("Failed connection.");
  }
  //Serial.println(strlen(postData1));
  //Serial.println(strlen(postData2));
  Serial.println(postData1);
  Serial.println(postData2);
  delay(1000);
  ESP.print("AT+CIPSEND=");
  ESP.println((strlen(postData1)+strlen(postData2)+6));
  delay(2000);
  Serial.print("Message Size: ");
  Serial.println((strlen(postData1)+strlen(postData2)+6));
  delay(2000);
  ESP.print(postData1);
  ESP.print("\r\n");
  ESP.print(postData2);
  ESP.print("\r\n\r\n");
  if(ESP.find("SEND OK"))
    Serial.println("Data Sent");
  else
    Serial.println("Data Send Failed");
  delay(1000);
  ESP.println("AT+CIPCLOSE");
}

