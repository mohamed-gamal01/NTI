/*
 * switch.c
 *
 * Created: 2/18/2023 9:05:50 AM
 *  Author: CONNECT
 */ 

#include "switch.h"
u8 switch_1(u8 ID)
{
	
	u8 x;
	switch(ID)
	{
		case 0:x=dio_dioLevelReadChannel(DIO_PORTD,DIO_PIN7);break;
		case 1:x=dio_dioLevelReadChannel(DIO_PORTD,DIO_PIN6);break;
		case 2:x=dio_dioLevelReadChannel(DIO_PORTD,DIO_PIN5);break;
	}
	return x;
}
	