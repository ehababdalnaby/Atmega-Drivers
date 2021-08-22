#ifndef __SPI_H__
#define __SPI_H__

#include "includes.h"

#define SPI_PORT		PORTB
#define SPI_DDR			DDRB

#define SPI_SS			PB4
#define SPI_MOSI		PB5
#define SPI_MISO		PB6
#define SPI_SCK			PB7

typedef enum{
	SPI_MASTER, SPI_SLAVE
}SPI_Mode;

void SPI_Init(SPI_Mode spiMode);
u8 SPI_Transceive(u8 data);

#endif