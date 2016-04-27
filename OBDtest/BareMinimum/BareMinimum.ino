#include <SoftwareSerial.h>

#define OBD_TX 4
#define OBD_RX 5

//SoftwareSerial debug(debug_RX, debug_TX);
SoftwareSerial OBD(OBD_RX, OBD_TX);
//char inData[64];
//char inChar=-1;


void setup() {
  // put your setup code here, to run once:
  pinMode(OBD_RX, INPUT);
  pinMode(OBD_TX, OUTPUT);
  
  Serial.begin(115200);
  //OBD.listen();
  OBD.begin(9600); 
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Testing");
  delay(2000);
  OBD.print("STMFR\r\n");
  //Serial.println(OBD.read());
  //debug.println("Testing");
  //delay(2000);
  //Serial.print("STMFR\r\n");
  //delay(010D);
  //byte numBytesAvailable = OBD.available();
  // if there is something to read
  //delay(2000);
  while(OBD.available()){
     Serial.print(OBD.read());
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
