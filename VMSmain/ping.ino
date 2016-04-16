//Pings google.com
void ping(){
   //Checking if module available
  Serial.println("Pinging google.com");
  delay(1000);
  ESP.print("AT+PING=\"www.google.com\"\r\n");
  if(read_ESP(keyword_OK,sizeof(keyword_OK),10000,0))//go look for keyword "OK" with a 5sec timeout
    Serial.println("Success.");
  else
    Serial.println("Failed.");
  serial_dump_ESP();
}

