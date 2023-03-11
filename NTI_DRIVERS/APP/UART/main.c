/*
 * UART_jimmy.c
 *
 * Created: 3/4/2023 10:55:59 PM
 * Author : CONNECT
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include "std_types.h"
#include "bit_math.h"
#include "dio.h"
#include "uart.h"

extern character_size x;

int main(void)
{
	/*
	UART_Init(UART_BAUDRATE_9600);
	dio_vidConfigChannel(DIO_PORTA,DIO_PIN1,INPUT);
	dio_vidConfigChannel(DIO_PORTA,DIO_PIN4,OUTPUT);
	dio_vidWriteChannel(DIO_PORTA,DIO_PIN4,STD_HIGH);
	while (1)
	{
		UART_TransmitChr('a');
		_delay_ms(50);

	}
	*/
	
	
	
	
	
	
	
	
	
	
	u8 str[100];
	
	UART_Init(UART_BAUDRATE_9600);
	UART_EN_Rx();
	UART_EN_Data_Register_Empty();
	SREG_VoidEnable();
    UART_send_string("ahmed");
	
    while (1) 
    {
		if(1==UART_check())
		{
			UART_res_string(str);
			
		}
		
    }
	
	
	
}

