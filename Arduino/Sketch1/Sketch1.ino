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

// the setup function runs once when you press reset or power the board
void setup() {
  // put your setup code here, to run once:
  Wire.begin();   //Initialize wire library

  Serial.begin(9600);
  Serial.println("Hello lets begin");

  init_gyro();
  init_accelerometer();
}

// the loop function runs over and over again until power down or reset
void loop() {
  Serial.println("hello");

  int n;
  uint8_t data;

  n = read_I2C(FXAS21002C_I2C_ADDRESS, FXAS21002C_WHO_AM_I, &data, 1);    
  Serial.print("Gyro Device ID: ");
  Serial.println(data, HEX);

  

  n = read_I2C(MMA8653FC_I2C_ADDRESS,MMA8653FC_WHO_AM_I,&data,1);
  Serial.print("Accelerometer Device ID: ");
  Serial.println(data, HEX);

  uint8_t buffer[4];
  uint16_t x;
  uint16_t y;
  double accel_x;
  double accel_y;
  read_I2C(MMA8653FC_I2C_ADDRESS, X_MSB, buffer, 4);
  x =((buffer[0]<<8) | buffer[1]) >> 6;
  accel_x = (double(x)/511)*1.996;
  y =((buffer[2]<<8) | buffer[3]) >> 6;
  accel_y = (double(y)/511)*1.996;  
  Serial.print("X-axis acceleration: ");
  Serial.print(accel_x);
  Serial.println("g");
  Serial.print("Y-axis acceleration: ");
  Serial.print(accel_y);
  Serial.println("g");
  
  delay(500);
}

