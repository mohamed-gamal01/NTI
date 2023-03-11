/*
 * led.c
 *
 * Created: 3/11/2023 10:47:11 AM
 *  Author: CONNECT
 */ 
#include "led.h"

void led_int(void)
{
	dio_vidConfigChannel(DIO_PORTB,DIO_PIN7,OUTPUT);
	dio_vidConfigChannel(DIO_PORTA,DIO_PIN4,OUTPUT);
	dio_vidConfigChannel(DIO_PORTA,DIO_PIN5,OUTPUT);
	dio_vidConfigChannel(DIO_PORTA,DIO_PIN6,OUTPUT);
}

void led_on(u8 ID)
{

	switch(ID)
	{
		case 0:dio_vidWriteChannel(DIO_PORTB,DIO_PIN7,STD_HIGH);break;
		case 1:dio_vidWriteChannel(DIO_PORTA,DIO_PIN4,STD_HIGH);break;
		case 2:dio_vidWriteChannel(DIO_PORTA,DIO_PIN5,STD_HIGH);break;
		case 3:dio_vidWriteChannel(DIO_PORTA,DIO_PIN6,STD_HIGH);break;
	}

}

void led_off(u8 ID)
{

	switch(ID)
	{
		case 0:dio_vidWriteChannel(DIO_PORTB,DIO_PIN7,STD_LOW);break;
		case 1:dio_vidWriteChannel(DIO_PORTA,DIO_PIN4,STD_LOW);break;
		case 2:dio_vidWriteChannel(DIO_PORTA,DIO_PIN5,STD_LOW);break;
		case 3:dio_vidWriteChannel(DIO_PORTA,DIO_PIN6,STD_LOW);break;
	}													 
	

}


void led_toggle(u8 ID)
{

	switch(ID)
	{
		case 0:dio_vidFlipChannel(DIO_PORTB,DIO_PIN7);break;
		case 1:dio_vidFlipChannel(DIO_PORTA,DIO_PIN4);break;
		case 2:dio_vidFlipChannel(DIO_PORTA,DIO_PIN5);break;
		case 3:dio_vidFlipChannel(DIO_PORTA,DIO_PIN6);break;
	}
	

}