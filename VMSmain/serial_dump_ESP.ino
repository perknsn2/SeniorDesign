//Read everything out of the serial buffer and whats coming and get rid of it
void serial_dump_ESP(){
  char temp;
  while(ESP.available()){
    temp =ESP.read();
    delay(1);//could play around with this value if buffer overflows are occuring
  }  
}

