/**
* @file IMSPI.h
* @Author Me (mehmet.akcakoca@inovasyonmuhendislik.com)
* @date Mar, 2015
* @brief Elektronik Konrol Birimi(EKB) üzerinde, SPI haberleşmesini sağlayan sınıftır.
*
*
*/


#ifndef INCLUDE_IMSPI_H_
#define INCLUDE_IMSPI_H_

#include <unistd.h>
#include <stdint.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <iostream>


class IMSPI
{

public:
	IMSPI();
	IMSPI(std::string str_devspi, unsigned char u_c_spi_mode, unsigned int u_i_spi_speed,
			unsigned char u_c_spi_bits_per_word);
    ~IMSPI();
    int SpiWriteRead(unsigned char *p_u_c_data, int i_length);

private:
	unsigned char u_c_mode;
	unsigned char u_c_bits_per_word;
	unsigned int u_i_speed;
	int i_spifd;

	int SpiOpen(std::string devspi);
	int SpiClose();

};


#endif /* INCLUDE_IMSPI_H_ */
