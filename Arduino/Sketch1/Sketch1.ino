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
  Serial.println("Hello");
/*
  Wire.beginTransmission(MMA8653FC_I2C_ADDRESS);
  Wire.write(MMA8653FC_CTRL_REG1);
  Wire.write(CTRL_REG1);
  Wire.endTransmission(true); 
  */
}

// the loop function runs over and over again until power down or reset
void loop() {
  Serial.println("hello");

  int n;
  uint8_t data;

  Wire.beginTransmission(FXAS21002C_I2C_ADDRESS);
  Wire.write(FXAS21002C_WHO_AM_I);
  n = Wire.endTransmission(false);

  Serial.print("n:");
  Serial.println(n);

  Wire.requestFrom(FXAS21002C_I2C_ADDRESS, 1, true);
  while (Wire.available()) {
    data = Wire.read();
  }
  Serial.println(data, HEX);
  delay(500);
}

