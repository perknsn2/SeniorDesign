#define MMA8653FC_I2C_ADDRESS 0x1D   //accelerometer device address
#define MMA8653FC_CTRL_REG1 0x2A    //accelerometer active mode register 

void init_accelerometer()
{
  uint8_t data = 0x1;
  write_I2C(MMA8653FC_I2C_ADDRESS, MMA8653FC_CTRL_REG1, &data, 1);
  
}
