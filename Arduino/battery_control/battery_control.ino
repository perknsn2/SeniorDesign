const int numReadings = 10;
int readings[numReadings];      // the readings from the analog input
int readings2[numReadings];
int index = 0;              // the index of the current reading
int total = 0;                  // the running total
int total2 = 0;
double average = 0;                // the average
double average2 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A1,OUTPUT);

  for (int i = 0; i < numReadings; i++) {
    readings[i] = 0;
    readings2[i] = 0;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  double value = analogRead(A3);            //measures battery voltage
  double value2 = analogRead(A2);            //measures battery temperature

 total = total - readings[index];
 total2 = total2 - readings2[index];  
 
  // read from the sensor:
  readings[index] = value;
  readings2[index] = value2;
  
  // add the reading to the total:
  total = total + readings[index];
  total2 = total2 + readings2[index];
  // advance to the next position in the array:
  index++;

  // if we're at the end of the array...
  if (index >= numReadings) {
    // ...wrap around to the beginning:
    index = 0;
  }

  // calculate the average:
  average = total / numReadings;
  average2 = total2/numReadings;
  double Vcc = readVcc()/1000.0;
  double battery_average = (average/1023)*5.16;           //ADC calculation based on Vcc voltage reference which is not exactly 5V
  double battery_voltage = ((127*battery_average)/100); //error
  Serial.println(battery_voltage);

  double battery_temp = (average2/1023)*5;
  


  if (battery_voltage >= 4.2) //analog monitors battery voltage 
    digitalWrite(A1,LOW);
  //else if(battery_temp < 2.25 && index == 9)
  //  analogWrite(analogpin,0);
  else
    digitalWrite(A1,HIGH);
    
  
    delay(1000);        // delay in between reads for stability

}


long readVcc() {
  long result;
  // Read 1.1V reference against AVcc
  ADMUX = _BV(REFS0) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1) ;
  delay(2); // Wait for Vref to settle
  ADCSRA |= _BV(ADSC); // Convert
  while (bit_is_set(ADCSRA,ADSC));
  result = ADCL;
  result |= ADCH<<8;
  result = 1125300L / result; // Back-calculate AVcc in mV
  return result;
}

