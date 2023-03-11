/*
 * timer_PWM.c
 *
 * Created: 2/26/2023 1:59:43 PM
 * Author : CONNECT
 */ 

#include <avr/io.h>
#include <avr/io.h>
#define F_CPU 16000000UL
#include "avr/delay.h"
#include "std_types.h"
#include "bit_math.h"
#include "TIMR0_PWM_int.h"
#include "dio.h"


int main(void)
{
		TIMER0_void_Init();
		dio_vidConfigChannel(DIO_PORTB,DIO_PIN3,OUTPUT);
		
		
   
    while (1) 
    {
		for(u8 i=0;i<255;i++)
		{
			TIMER0_void_SetCompareVal(i);
			_delay_ms(10);
			
		}
		
    }
}

