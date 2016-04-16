#include <Wire.h>
uint8_t x,y;
int n;

#define MMA8653FC_I2C_ADDRESS 0x1D   //accelerometer device address
#define FXAS21002C_I2C_ADDRESS 0x20  //gyro device address
#define MMA8653FC_CTRL_REG1 0x2A    //accelerometer active mode register 
#define FXAS21002C_CTRL_REG1 0x13   //gyro active mode register
#define MMA8653FC_WHO_AM_I  0x0D //accelerometer device ID
#define FXAS21002C_WHO_AM_I 0x0C //gyro device ID
#define MMA8653FC_XYZ_DATA_CFG 0x0E //FS[1:0]accelerometer dynamic range register
#define FXAS21002C_CTRL_REG0 0x0D   //FS[1:0]gyro dynamic range register 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello let's begin");
  Wire.begin();
 /* ACCELEROMETER CHECK*/
  Wire.beginTransmission(MMA8653FC_I2C_ADDRESS);  
  Wire.write(MMA8653FC_WHO_AM_I);
  n = Wire.endTransmission(false);
  Serial.print("n: ");
  Serial.println(n);
    
  Wire.requestFrom(MMA8653FC_I2C_ADDRESS,1,true);

  while(Wire.available())
  {
    x = Wire.read();   
   }
   Serial.print("Accelerometer Device ID: ");
   Serial.println(x,HEX);

/*GYRO CHECK*/
  Wire.beginTransmission(FXAS21002C_I2C_ADDRESS);  
  Wire.write(FXAS21002C_WHO_AM_I);
  n = Wire.endTransmission(false);
  Serial.print("n: ");
  Serial.println(n);
    
  Wire.requestFrom(FXAS21002C_I2C_ADDRESS,1,true);

  while(Wire.available())
  {
    y = Wire.read();   
   }
   Serial.print("Gyro Device ID: ");
   Serial.println(y,HEX);

  /*SET BOTH THE GYRO AND ACCELEROMETER IN ACTIVE MODE*/
  Wire.beginTransmission(MMA8653FC_I2C_ADDRESS);
  Wire.write(MMA8653FC_CTRL_REG1);
  Wire.write(0x01);  //bit 0 is the active bit for the accelerometer
  Wire.endTransmission(false);

  Wire.beginTransmission(FXAS21002C_I2C_ADDRESS);
  Wire.write(FXAS21002C_CTRL_REG1);
  Wire.write(0x02);  //bit 1 is the active bit for the gyro
  Wire.endTransmission(false);
  
   Serial.println("SETUP CODE WORKS");

}


void loop() {
  // put your main code here, to run repeatedly:
    
}
