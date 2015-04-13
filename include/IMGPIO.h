/**
* @file IMGPIO.h
* @Author Me (mehmet.akcakoca@inovasyonmuhendislik.com)
* @date Mar, 2015
* @brief Controls general GPIO's of EKB.
*
*/

#ifndef INCLUDE_IMGPIO_H_
#define INCLUDE_IMGPIO_H_


#include <string>
#include <iostream>
#include <sstream>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/poll.h>
#include <string>
#include <signal.h>

using namespace std;


//bool g_b_exit_signal = false;

// Callback function pointer.
typedef void(*CallbackFunctionPtr)(void*, int);
void CatchSignal(int i_sig);

class IMGPIO
{
public:
	//! Default constructor
	/**
	 * Constructor of IMGPIO class
	 */
	IMGPIO();
	IMGPIO(string str_pin_number);
	~IMGPIO();
    	int SetPinDirection(string str_direction);
    	int SetInterruptMode(string str_int_mode);
    	int SetPinValue(string str_value);
    	int GetPinValue(string & str_value);
    	string GetPinNumber() const;
    	void SetCallback(CallbackFunctionPtr _callback_function, void *p);

	//! Constant Değişkenler.

	static const string RISING;
	static const string FALLING;
	static const string BOTH;

	static const string OUTPUT;
	static const string INPUT;

	static const string HIGH;
	static const string LOW;

	static const string GPIO0;
	static const string GPIO1;
	static const string GPIO2;
	static const string GPIO3;
//	static const string GPIO4;
	static const string GPIO5;
	static const string GPIO6;
	static const string GPIO7;
	static const string GPIO8;
	static const string GPIO9;
	static const string GPIO10;
//	static const string GPIO11;

private:
    int ExportGpio();
	int UnexportGpio();
	int PollGpio();

	int i_value_fd;
	int i_direction_fd;
	int i_export_fd;
	int i_unexport_fd;
	int i_edge_fd;
	string str_pin_number;
	CallbackFunctionPtr callback_function;
	void *p_v_callback_pointer;
	string str_interrupt_mode;

//	bool b_exit_signal;
//	void CatchSignal(int i_sig);


};

#endif /* INCLUDE_IMGPIO_H_ */
