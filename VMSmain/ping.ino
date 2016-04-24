//Pings google.com
void ping(){
   //Checking if module available
  Serial.println("Pinging google.com");
  delay(1000);
  ESP.print("AT+PING=\"www.google.com\"\r\n");
  if(ESP.find("OK"))
    Serial.println("Success.");
  else
    Serial.println("Failed.");
  serial_dump_ESP();
}

