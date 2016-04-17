/*I2C Read and Write functions*/

// Write to device using I2C
int write_I2C(int device, int reg, const uint8_t *data, int size) {
	int error;

	Wire.beginTransmission(device);
	Wire.write(reg);

	Wire.write(data, size);

	error = Wire.endTransmission(true);	
	if (error != 0)
		return error;

	return 0;
}

int read_I2C(int device, int reg, uint8_t *buffer, int size) {
	int i;

	Wire.beginTransmission(device);
	Wire.write(reg);
	Wire.endTransmission(false);

	Wire.requestFrom(device, size, true);
	i = 0;
	while (Wire.available() && i < size) {
		buffer[i++] = Wire.read();
	}

	if (i != size)
		return(-1);

	return 0;
}
