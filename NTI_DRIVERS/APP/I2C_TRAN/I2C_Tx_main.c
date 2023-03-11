/*
 * SPI_TRANS.c
 *
 * Created: 1/21/2022 9:33:16 PM
 * Author : Doha
 */ 

#include "Std_Types.h"
#include "Bit_Math.h"
#include "DIO_interface.h"
#include "I2C_interface.h"

int main(void)
{
	DIO_voidSetPinDirection(PORTA,PIN0,INPUT);
	DIO_voidSetPinValue(PORTA,PIN0,HIGH);
	DIO_voidSetPinDirection(PORTA,PIN1,INPUT);
	DIO_voidSetPinValue(PORTA,PIN1,HIGH);
	
	I2C_Master_voidInit();
	I2C_Error_State Error=I2C_OK;
	while (1)
	{
		Error =I2C_Master_enuSendStartCond();
		Error=I2C_Master_enuSendSlaveAddressWithWrite(0x10);
		if(Error==I2C_OK && DIO_u8GetPinValue(PORTA,PIN0)==0)
		{
			Error=I2C_Master_enuSendu8Data('H');
		}
		else if(Error==I2C_OK && DIO_u8GetPinValue(PORTA,PIN1)==0)
		{
			Error=I2C_Master_enuSendu8Data('L');
		}
	}
}


