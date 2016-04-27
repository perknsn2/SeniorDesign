
void postData(bool gyro, bool accel, int velocity){
  char postData1[35] = "GET /vms/count/accel/add HTTP/1.1";
  char postData2[34] = "GET /vms/count/gyro/add HTTP/1.1";
  char postData3[20] = "Host: 54.86.75.167";
  //sprintf(postData1,"GET /vms/data/%d HTTP/1.1",velocity);

  delay(1000);
  Serial.print("AT+CIPSTART=\"TCP\",\"54.86.75.167\",80\r\n");
  delay(2000);
  Serial.print("AT+CIPSEND=");
  if(accel == true){
    Serial.print((strlen(postData1)+strlen(postData3)+6));
    Serial.print("\r\n");
    delay(2000);
    Serial.print(postData1);
    Serial.print("\r\n");
    Serial.print(postData3);
    Serial.print("\r\n\r\n");
  }
  if(gyro == true){
    Serial.print((strlen(postData2)+strlen(postData3)+6));
    Serial.print("\r\n");
    delay(2000);
    Serial.print(postData2);
    Serial.print("\r\n");
    Serial.print(postData3);
    Serial.print("\r\n\r\n");
  }
  delay(1000);
  Serial.println("AT+CIPCLOSE");
}

