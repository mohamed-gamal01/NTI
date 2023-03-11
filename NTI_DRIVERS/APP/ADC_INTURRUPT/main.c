/*/*
 * NTI_FIRST.c
 *
 * Created: 2/17/2023 11:44:16 AM
 * Author : CONNECT
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "dio.h"
#include "ADC_interrupt_int.h"



void toggle(void);
int main(void)
{
	u16 x;

	
	ADC_CallBack(toggle);
	ADC_voidInit();
	SREG_VoidEnable();
    dio_vidConfigChannel(DIO_PORTA,DIO_PIN4,OUTPUT);
	
	
	while(1)
	{
			ADC_voidStartConversion();
			_delay_ms(1000);
	}
	
	return 0;
}

void toggle(void)
{

		FLIP_BIT(DIO_PORTA_REG,DIO_PIN4);
		_delay_ms(1000);
	
}