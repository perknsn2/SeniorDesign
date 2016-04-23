/*
 Name:    Sketch1.ino
 Created: 4/13/2016 9:36:12 PM
 Author:  Caleb
*/

#include <Wire.h>

#define MMA8653FC_I2C_ADDRESS 0x1D
#define FXAS21002C_I2C_ADDRESS 0x20

#define X_MSB 0x01
#define X_LSB 0x02
#define Y_MSB 0x03
#define Y_LSB 0x04
#define Z_MSB 0x05
#define Z_LSB 0x06
#define MMA8653FC_WHO_AM_I 0x0D
#define FXAS21002C_WHO_AM_I 0x0C
#define FXAS21002C_CTRL_REG1 0x13
#define MMA8653FC_CTRL_REG1 0x2A

#define CTRL_REG1 0x01
int n;
  uint8_t data;
  uint8_t buffer2[6];
  uint8_t buffer1[6];
  int x;
  int y;
  int z;
  double accel_x;
  double accel_y;
  double accel_z;
  double gyro_z;
  
// the setup function runs once when you press reset or power the board
void setup() {
  // put your setup code here, to run once:
  Wire.begin();   //Initialize wire library

  Serial.begin(9600);
  Serial.println("Hello lets begin");

  pinMode(10,OUTPUT);
  
  
  init_gyro();
  init_accelerometer();
}

// the loop function runs over and over again until power down or reset
void loop() {

  
  digitalWrite(10,HIGH);
  delay(1000);
  digitalWrite(10,LOW);
  
  n = read_I2C(FXAS21002C_I2C_ADDRESS, FXAS21002C_WHO_AM_I, &data, 1);    
  Serial.print("Gyro Device ID: ");
  Serial.println(data, HEX);
  read_I2C(FXAS21002C_I2C_ADDRESS, X_MSB, buffer2, 6);
  x = (buffer2[4]<<8) | buffer2[5];
  gyro_z = (double(x)/32768)*2000;
  Serial.print("Z-axis angular velocity: ");
  Serial.print(gyro_z);
  Serial.println("dps");

  
  n = read_I2C(MMA8653FC_I2C_ADDRESS,MMA8653FC_WHO_AM_I,&data,1);
  Serial.print("Accelerometer Device ID: ");
  Serial.println(data, HEX);  
  read_I2C(MMA8653FC_I2C_ADDRESS, X_MSB, buffer1, 6);
  x =((buffer1[0]<<8) | buffer1[1]) >> 6;
  accel_x = (double(x)/512)*2;
  y =((buffer1[2]<<8) | buffer1[3]) >> 6;
  accel_y = (double(y)/512)*2;  
  Serial.print("X-axis acceleration: ");
  Serial.print(accel_x);
  Serial.println("g");
  Serial.print("Y-axis acceleration: ");
  Serial.print(accel_y);
  Serial.println("g");
  //z = (((buffer1[4]<<8) | buffer1[5]) >> 6);
  //accel_z = double(z)/512;
  //Serial.println(accel_z);
  delay(500);
}

