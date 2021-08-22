/*
 * ExtEEPROM.c
 *
 * Created: 8/22/2021 6:17:45 PM
 *  Author: Mohamed
 */ 
 #include "ExtEEPROM.h"

 
 void writeEEPROM(u16 location,u8 data)
 {
	 SPI_Transceive(((location>>5)& ~(0x7))|EROM_COM_WRITE);
	 SPI_Transceive(location);
	 SPI_Transceive(data);
	 _delay_us(1);
 }
 u8 readEEPROM(u16 location)
 {
	 u8 data;
	 SPI_Transceive(((location>>5)& ~(0x7))|EROM_COM_READ);
	 SPI_Transceive(location);
	 data= SPI_Transceive(0x00);
 }
 /*void writePageEEPROM(u16 address,u8* str)
 {
	 SPI_Transceive( (CLRBits((address>>5),0x7))|EROM_COM_WRITE);
	 SPI_Transceive( (u8) address);
	 SPI_Transceive(data);
	 _delay_us(1);
 }*/