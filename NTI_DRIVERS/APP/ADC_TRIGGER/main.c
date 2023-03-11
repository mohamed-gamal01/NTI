/*
 * NTI_FIRST.c
 *
 * Created: 2/17/2023 11:44:16 AM
 * Author : CONNECT
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#include "dio.h"
#include "LCD.h"
#include "ADC_int.h"




void toggle(void);
int main(void)
{
	u16 x;

	
	lcd_int();
	ADC_voidInit();
   SREG_VoidEnable();
	dio_vidConfigChannel(DIO_PORTA,DIO_PIN1,INPUT);
    dio_vidConfigChannel(DIO_PORTA,DIO_PIN4,OUTPUT);
	dio_vidWriteChannel(DIO_PORTA,DIO_PIN1,STD_HIGH);
	
	while(1)
	{

      ADC_voidCallBack(toggle);
	
		
		
	}
	
	return 0;
}
void toggle(void)
{
	u8 static x;
	
	

	x=dio_dioLevelReadChannel(DIO_PORTA,DIO_PIN1);
	
	if(x==0)
	{
		
		FLIP_BIT(DIO_PORTA_REG,DIO_PIN4);
		_delay_ms(1000);
		
	}
	
	
}