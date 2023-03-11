/*
 * counter.c
 *
 * Created: 3/2/2023 2:08:06 PM
 * Author : CONNECT
 */ 

#include <avr/io.h>
#include "std_types.h"
#include "bit_math.h"
#include "counter_int.h"
#include "dio.h"

volatile u16 counter=0;
void toggle(void);
int main(void)
{
	TIMER0_void_SetCTCCallBack(toggle);
	TIMER0_void_Init();
	SREG_VoidEnable ();
	TIMER0_void_SetTimerReg(0);
	TIMER0_void_SetCompareVal(50);
    TIMER0_void_EnableCTCInt();
	dio_vidConfigChannel(DIO_PORTA,DIO_PIN4,OUTPUT);
	
	
	while (1)
	{
	}
	}

	void toggle(void)
	{
	
	//dio_vidWriteChannel(DIO_PORTA,DIO_PIN4,STD_HIGH);
	FLIP_BIT(DIO_PORTA_REG,DIO_PIN4);
	
	}
