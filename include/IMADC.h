/*
 * IMADC.h
 *
 *  Created on: Mar 24, 2015
 *      Author: makcakoca
 */

#ifndef INCLUDE_IMADC_H_
#define INCLUDE_IMADC_H_

#include "IMSPI.h"

class IMADC
{
public:
	//! Constructor
	IMADC(IMSPI * p_imspi, int i_adc_bits);

	//! Reads single-ended Analog to Digital Converter Channel (MCP3208).
	/**
	 * \param i_channel_no is channel number to read in range of 0-7
	 * \return value of data on the channel
	 */
	int ReadChannel(int i_channel_no);

	//! Reads differential Analog to Digital Converter Channel (MCP3208).
	/**
	 * \param i_channel_plus is channel number to read in range of 0-7
	 * \param i_channel_negative
	 * \return value of data on the difference(i_channel_plus - i_channel_negative)
	 */
	int ReadChannel(int i_channel_plus, int i_channel_negative);

private:
	IMSPI * p_imspi;
	int i_adc_bits;
	int i_mask;
};

#endif /* INCLUDE_IMADC_H_ */
