/*
 * IMSerial.h
 *
 *  Created on: Mar 23, 2015
 *      Author: makcakoca
 */

#ifndef INCLUDE_IMSERIAL_H_
#define INCLUDE_IMSERIAL_H_

#include <termios.h>
#include <string.h>
#include <string>
#include <termios.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <cstdlib>

using namespace std;

// Callback function pointer.
typedef void(*CallbackFunctionPtr)(void*);

class IMSerial
{
public:
	IMSerial();
	IMSerial(string str_device_name, speed_t baudrate, tcflag_t data_bits,
			tcflag_t parity, tcflag_t parity_on, tcflag_t stop_bits);

	int SetBaudrate(speed_t baudrate);
	int SetDataBits(tcflag_t data_bits);
	int SetParity(tcflag_t parity, tcflag_t parity_on);
	int SetStopBits(tcflag_t stop_bits);

	speed_t GetBaudrate() const;
	tcflag_t GetDataBits() const;
	tcflag_t GetParity() const;
	tcflag_t GetStopBits() const;

	int ReadData(char * p_c_data, unsigned int u_i_size);
	int ReadDataAsync(char * p_c_data, unsigned int u_i_size);
	//int WriteData(const char * p_c_data, unsigned int u_i_size);
	int WriteData(const void * p_data, size_t size);

	bool isReadyRead() const;

private:
	int SerialOpen(std::string _str_name);
	int SerialClose();
	int SerialConfig();

	static void SignalHandlerIO(int i_status);

	std::string str_name;
	speed_t baudrate;
	tcflag_t data_bits;
	tcflag_t parity;
	tcflag_t parity_on;
	tcflag_t stop_bits;

	int i_serial_fd;

	bool b_read_data_available;

	struct sigaction signal_action_io;
	struct termios port_settings;

	static bool b_signal_received;

};



#endif /* INCLUDE_IMSERIAL_H_ */
