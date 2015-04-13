/*
 * IMI2C.h
 *
 *  Created on: Mar 23, 2015
 *      Author: makcakoca
 */

#ifndef INCLUDE_IMI2C_H_
#define INCLUDE_IMI2C_H_

#include <string>
#include <stdio.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <string.h>

using namespace std;

class IMI2C
{
public:
	IMI2C(); // default constructor
	IMI2C(unsigned char u_c_device_address, string str_i2c_file_name);

	//over loaded constructor
	~IMI2C(void); // destructor
	int WriteDataByte(unsigned char u_c_register_address, unsigned char u_c_data);
    // function to write byte data into a register of an I2C device

	int ReadDataByte(unsigned char u_c_register_address, unsigned char & u_c_data);
    // function to read byte data from a register of an I2C device

private:
	//private member functions
	int OpenI2C(); //open an I2C device. Called only in constructors
	int CloseI2C(); // close an I2C device. Called only in destructor

	// private member variables
	string  str_i2c_file_name; //i2c device name e.g."/dev/i2c-0" or "/dev/i2c-1"
	int i_i2cfd;  // i2c device descriptor
	unsigned char u_c_device_adress; // i2c device address
};



#endif /* INCLUDE_IMI2C_H_ */
