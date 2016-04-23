#define FXAS21002C_I2C_ADDRESS 0x20
#define FXAS21002C_CTRL_REG1 0x13

void init_gyro()
{
	uint8_t data = 0x2;
	write_I2C(FXAS21002C_I2C_ADDRESS, FXAS21002C_CTRL_REG1, &data, 1);
}


