/*
 * SPI.c
 *
 * Created: 3/4/2023 1:36:03 PM
 * Author : CONNECT
 */ 
 #define F_CPU 16000000UL		
 #include <avr/io.h>			
 #include <util/delay.h>
 #include "SPI.h"
 #include "dio.h"
 #include "std_types.h"
 #include "bit_math.h"
 #include "SPI_confg.h"
 

#define first    DIO_PIN7
#define second    DIO_PIN6

extern const prescaler z;
u8 switch_1(u8 ID);
int main(void)
{
	u8 x,y;
	 SPI_Master_Int ();
	 
	//SPI_Slave_Int();  
//	dio_vidConfigChannel(DIO_PORTD,DIO_PIN7,INPUT);
	dio_vidConfigChannel(DIO_PORTA,DIO_PIN4,OUTPUT);
	//dio_vidConfigChannel(DIO_PORTA,DIO_PIN5,OUTPUT);
	  
    while (1) 
    {
		y=SPI_Send_Byte(0);
		if(y==2)
		{
			dio_vidWriteChannel(DIO_PORTA,DIO_PIN4,STD_HIGH);
		}
		
		/*
		x= switch_1(first);
		if(0==x)
		{
			
			dio_vidWriteChannel(DIO_PORTA,DIO_PIN4,STD_HIGH);
			
			y=SPI_Send_Byte('0');
			
			
	
		}
		
		x= switch_1(second);
		if(0==x)
		{
			dio_vidWriteChannel(DIO_PORTA,DIO_PIN5,STD_HIGH);
			_delay_ms(200);
			y=SPI_Send_Byte(2);
			
		}
		
		
		*/
		
    }
}


u8 switch_1(u8 ID)
{
	
	u8 x=5;
	x=dio_dioLevelReadChannel(DIO_PORTD,ID);
	if(x!=0)
	{
		x=5;
	}else
	{
		x=0;
	}
	
	return x;
}
