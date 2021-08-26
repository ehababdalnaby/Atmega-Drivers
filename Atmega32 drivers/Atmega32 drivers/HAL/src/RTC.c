/*
 * RTC.c
 *
 * Created: 8/26/2021 5:56:22 PM
 *  Author: Mahmoud-PC
 */ 

void Write_RTC()
{
	
	
}

void Read_RTC(u8* Seconds,u8* Minutes,u8* Hours,u8* Day,u8* Date,u8* Month,u8* Year);
{
	I2C_start();
	I2C_Write(RTC_WRITE_ADDRESS,SCMTSLA_Ack_Code);
	I2C_Write(RTC_SECONDS_ADDRESS,SCMTSLA_Ack_Code);
	I2C_Stop();
	I2C_start();
	I2C_Write(RTC_READ_ADDRESS,SCMTSLA_Ack_Code);
	I2C_Read(&Seconds,ReceiveData_NAck_code);
	I2C_Read(&Minutes,ReceiveData_NAck_code);
	I2C_Read(&Hours,ReceiveData_NAck_code);
	I2C_Read(&Day,ReceiveData_NAck_code);
	I2C_Read(&Date,ReceiveData_NAck_code);
	I2C_Read(&Month,ReceiveData_NAck_code);
	I2C_Read(&Year,ReceiveData_NAck_code);
	I2C_Stop();
}