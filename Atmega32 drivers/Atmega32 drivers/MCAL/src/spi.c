#include "SPI.h"
void SPI_Init(SPI_Mode spiMode){
	switch(spiMode){
	case SPI_MASTER:
	setBit(SPI_DDR,SPI_SS);
	setBit(SPI_DDR,SPI_SCK);
	setBit(SPI_DDR,SPI_MOSI);
	clearBit(SPI_DDR,SPI_MISO);
	
		setBit(SPCR,SPR0);
		setBit(SPCR,MSTR);
		setBit(SPCR,SPE);

	break;
	case SPI_SLAVE:
	clearBit(SPI_DDR,SPI_SS);
	clearBit(SPI_DDR,SPI_SCK);
	clearBit(SPI_DDR,SPI_MOSI);
	setBit(SPI_DDR,SPI_MISO);
	
		clearBit(SPCR,MSTR);
		setBit(SPCR,SPE);

	break;
	}
}
u8 SPI_Transceive(u8 data){
		SPDR = data;
		while(!(SPSR & (1<<SPIF)));
		return SPDR;
}
