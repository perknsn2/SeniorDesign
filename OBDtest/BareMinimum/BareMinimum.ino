#include <SoftwareSerial.h>

#define debug_TX 4
#define debug_RX 5

//SoftwareSerial debug(debug_RX, debug_TX);

char inData[64];
char inChar=-1;

void setup() {
  // put your setup code here, to run once:
  pinMode(debug_RX, INPUT);
  pinMode(debug_TX, OUTPUT);
  
  Serial.begin(38400);
  //OBD.listen();
  //debug.begin(9600); 
  file.println("Testing");
  delay(2000);
  Serial.print("STMFR\r\n");
  if(Serial.find("Generic"))
    debug.println("Module responding.");
}

void loop() {
  // put your main code here, to run repeatedly:
  debug.println("Testing");
  delay(2000);
  Serial.print("STMFR\r\n");
  //delay(010D);
  //byte numBytesAvailable = OBD.available();
  // if there is something to read
  //delay(2000);
  while(Serial.available()){
     debug.print(Serial.read());
     debug.println();
  }
  /*if (numBytesAvailable > 0){
      // store everything into "inData"
      int i;
      for (i=0;i<numBytesAvailable;i++){
          inChar= OBD.read();
          inData[i] = inChar;
      }

      inData[i] = '\0';
      Serial.print("Arduino Received: ");
      Serial.println(inData);
  }*/
  
}
