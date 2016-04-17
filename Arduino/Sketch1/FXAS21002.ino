#define FXAS21002C_I2C_ADDRESS 0x20
#define FXAS21002C_CTRL_REG1 0x13
#define MMA8653FC_I2C_ADDRESS 0x1D   //accelerometer device address
#define MMA8653FC_CTRL_REG1 0x2A    //accelerometer active mode register 

void init_gyro()
{
	uint8_t data = 0x2;
	write_I2C(FXAS21002C_I2C_ADDRESS, FXAS21002C_CTRL_REG1, &data, 1);
}

void init_accelerometer()
{
  uint8_t data = 0x1;
  write_I2C(MMA8653FC_I2C_ADDRESS, MMA8653FC_CTRL_REG1, &data, 1);
  
}
