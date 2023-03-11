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



int main(void)
{
	u16 x;

	
	lcd_int();
	ADC_voidInit();
	dio_vidConfigChannel(DIO_PORTA,DIO_PIN1,INPUT);

	
	while(1)
	{

      /////////////////////////////the 1 means channel 1
		x=ADC_u16ReadADCInMV(1);
		
		LCD_VoidSendNumber(x);
		
		_delay_ms(1000);
		
	}
	
	return 0;
}
