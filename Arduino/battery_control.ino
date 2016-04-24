int analogpin = 1;              //pin that controls NMOS
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
  pinMode(analogpin,OUTPUT);

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
  double battery_average = (average/1024)*5; 
  double battery_voltage = (2*battery_average); //error
  Serial.println(battery_average);

  double battery_temp = (average2/1024)*5;
  


  if (battery_voltage >= 4) //analog monitors battery voltage 
    analogWrite(analogpin,0);
  else if(battery_temp < 2.25 && index == 9)
    analogWrite(analogpin,0);
  else
    analogWrite(analogpin,255);
    
  
    delay(1000);        // delay in between reads for stability

}
