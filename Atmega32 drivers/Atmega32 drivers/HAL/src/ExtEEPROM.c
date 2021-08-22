/*
 * ExtEEPROM.c
 *
 * Created: 8/22/2021 6:17:45 PM
 *  Author: Mohamed
 */ 
#include "ExtEEPROM.h"

 
 void writeEEPROM(u16 location,u8 data)
 {
	  WRITE_EN();    
	 writePin(PB4,LOW);
	 SPI_Transceive(((location>>5)& ~(0x7))|EROM_COM_WRITE);
	 SPI_Transceive((u8) location);
	 SPI_Transceive(data);
	 writePin(PB4,HIGH);
	 _delay_ms(10);
	 WRITE_DI();
 }
 u8 readEEPROM(u16 location)
 {
	 u8 data;
	 writePin(PB4,LOW);
	 _delay_ms(1);
	 SPI_Transceive(((location>>5)& ~(0x7))|EROM_COM_READ);
	 SPI_Transceive((u8)location);
	 data= SPI_Transceive(0xff);	//send garbage to recieve right data
	 _delay_ms(10);
	  writePin(PB4,HIGH);
	 return data;
 }
 
 
 void WRITE_EN(void)
 {
	 writePin(PB4,LOW);
	 SPI_Transceive(0x06);
	 writePin(PB4,HIGH);
	 _delay_ms(2);
 }
 
 
  void WRITE_DI(void)
  {
	  writePin(PB4,LOW);
	  SPI_Transceive(0x04);
	  writePin(PB4,HIGH);
	  _delay_ms(2);
  }
  
  
  
 void writePageEEPROM(u16 location,u8* str)
 {
	 u8 index=0;
	  WRITE_EN();					//write enable
	  writePin(PB4,LOW);			//CS enable
	  SPI_Transceive(((location>>5)& ~(0x7))|EROM_COM_WRITE);
	  SPI_Transceive((u8) location);
	  while(str[index]!='\0'&&(index<16))
	  {
		  SPI_Transceive(str[index]);
		  index++;
	  }
	  writePin(PB4,HIGH);  
	  _delay_ms(10);
	  WRITE_DI();//write disable
 }
 
void ReadEEPROMSTR(u16 location,u8 CharNum,u8 * ReadStr)
{
	u8 Counter = 0;
	for(;Counter<CharNum;Counter++)
	{
		ReadStr[Counter]=readEEPROM((location+Counter));
	}
}