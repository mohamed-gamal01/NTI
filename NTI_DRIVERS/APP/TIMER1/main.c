

#include <avr/io.h>
#include "avr/delay.h"
#include "std_types.h"
#include "bit_math.h"
#include "TIMR1_int.h"
#include "dio.h"

void toggle(void);

int main(void)
{
	TIMER1_void_SetOVCallBack(toggle);
	
	
	TIMER1_void_Init();
	SREG_VoidEnable ();
	TIMER1_void_EnableOVInt();
	dio_vidConfigChannel(DIO_PORTA,DIO_PIN4,OUTPUT);
	dio_vidWriteChannel(DIO_PORTA,DIO_PIN4,STD_HIGH);
	
	
	while(1)
	{
		
	}
	
}

void toggle(void)
{
	
		//dio_vidWriteChannel(DIO_PORTA,DIO_PIN4,STD_HIGH);
		FLIP_BIT(DIO_PORTA_REG,DIO_PIN4);
		_delay_ms(1000);
	
	
}

