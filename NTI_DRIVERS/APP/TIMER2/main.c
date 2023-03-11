/*
 * timer2.c
 *
 * Created: 3/2/2023 2:20:44 PM
 * Author : CONNECT
 */ 

#include <avr/io.h>
#include "std_types.h"
#include "bit_math.h"
#include "TIMR2_int.h"
#include "dio.h"

volatile u16 counter=0;
void toggle(void);
int main(void)
{
	u8 time=2;
	TIMER2_void_SetOVCallBack(toggle);
	TIMER2_void_Init();
	SREG_VoidEnable ();
	counter=put_time(time);
	TIMER2_void_SetTimerReg(0);
	TIMER2_void_SetCompareVal(0);
	TIMER2_void_EnableOVInt();
	dio_vidConfigChannel(DIO_PORTA,DIO_PIN4,OUTPUT);
	
	
	
	
	while (1)
	{
	}
	}

	void toggle(void)
	{
		static u16 count=0;
		static u16 x;
		x=counter;
		
		if(count==x)
		{
			//dio_vidWriteChannel(DIO_PORTA,DIO_PIN4,STD_HIGH);
			FLIP_BIT(DIO_PORTA_REG,DIO_PIN4);
			count=0;
		}
		count++;
	}
