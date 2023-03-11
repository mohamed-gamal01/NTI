/*
 * LCD.c
 *
 * Created: 2/18/2023 1:14:42 PM
 *  Author: CONNECT
 */ 

#include "LCD.h"


void lcd_int(void)
{
	dio_vidConfigChannel(DIO_PORTB,DIO_PIN0,OUTPUT);
	dio_vidConfigChannel(DIO_PORTB,DIO_PIN1,OUTPUT);
	dio_vidConfigChannel(DIO_PORTB,DIO_PIN2,OUTPUT);
	dio_vidConfigChannel(DIO_PORTB,DIO_PIN4,OUTPUT);
	
	dio_vidConfigChannel(DIO_PORTA,DIO_PIN3,OUTPUT);
	dio_vidConfigChannel(DIO_PORTA,DIO_PIN2,OUTPUT);
	_delay_ms(40);
	lcd_vidWritecomend(0x02);
	lcd_vidWritecomend(0x28);
	lcd_vidWritecomend(0x0e);
	lcd_vidWritecomend(0x01);
	
}

void lcd_vidWritedata(u8 value)
{
	int y=0;
	////////RS
	dio_vidWriteChannel(DIO_PORTA,DIO_PIN3,STD_HIGH);
	for(int i=4;i<7;i++)
	{
		if(1==CHECK_BIT(value,i))
		{
			
			SET_BIT(DIO_PORTB_REG,y);
		}
		else
		{
			CLEAR_BIT(DIO_PORTB_REG,y);
		 }
			 y++;	
	}
	if(1==CHECK_BIT(value,7))
	{
		
		SET_BIT(DIO_PORTB_REG,4);
		}else{
		CLEAR_BIT(DIO_PORTB_REG,4);
	}
	
	y=0;
	
	
	
	
	
	////////////////EN
	dio_vidWriteChannel(DIO_PORTA,DIO_PIN2,OUTPUT);
	_delay_ms(1);
	dio_vidWriteChannel(DIO_PORTA,DIO_PIN2,INPUT);
	_delay_ms(2);

////////////////////////////////////////////////////////////////////
for(int i=0;i<3;i++)
{
	if(1==CHECK_BIT(value,i))
	{
		
		SET_BIT(DIO_PORTB_REG,y);
		}else{
		CLEAR_BIT(DIO_PORTB_REG,y);
	}
	y++;
}
if(1==CHECK_BIT(value,3))
{
	
	SET_BIT(DIO_PORTB_REG,4);
	}else{
	CLEAR_BIT(DIO_PORTB_REG,4);
}

///////////////////////////////////////////////////////////////




	dio_vidWriteChannel(DIO_PORTA,DIO_PIN2,OUTPUT);
	_delay_ms(1);
	dio_vidWriteChannel(DIO_PORTA,DIO_PIN2,INPUT);
	_delay_ms(2);
	
	
}

/*
void lcd_sendData(u8 data)
{
	//Initializing LCD Data Port to Zero
	dio_vidWriteChannel(DIO_PORTB,DIO_PIN0,STD_LOW);
	dio_vidWriteChannel(DIO_PORTB,DIO_PIN1,STD_LOW);
	dio_vidWriteChannel(DIO_PORTB,DIO_PIN2,STD_LOW);
	dio_vidWriteChannel(DIO_PORTB,DIO_PIN4,STD_LOW);
	//Setting to LCD to data mode
	dio_vidWriteChannel(DIO_PORTA,DIO_PIN3,STD_HIGH);
	//Sending Higher nibble to Data Port
	dio_vidWriteChannel(DIO_PORTB,DIO_PIN0,(CHECK_BIT(data,4)));
	dio_vidWriteChannel(DIO_PORTB,DIO_PIN1,(CHECK_BIT(data,5)));
	dio_vidWriteChannel(DIO_PORTB,DIO_PIN2,(CHECK_BIT(data,6)));
	dio_vidWriteChannel(DIO_PORTB,DIO_PIN4,(CHECK_BIT(data,7)));
	dio_vidWriteChannel(DIO_PORTA,DIO_PIN2,STD_HIGH);
	_delay_us(1);
	dio_vidWriteChannel(DIO_PORTA,DIO_PIN2,STD_LOW);
	//Sending Lower nibble to Data Port
	dio_vidWriteChannel(DIO_PORTB,DIO_PIN0,(CHECK_BIT(data,0)));
	dio_vidWriteChannel(DIO_PORTB,DIO_PIN1,(CHECK_BIT(data,1)));
	dio_vidWriteChannel(DIO_PORTB,DIO_PIN2,(CHECK_BIT(data,2)));
	dio_vidWriteChannel(DIO_PORTB,DIO_PIN4,(CHECK_BIT(data,3)));
	dio_vidWriteChannel(DIO_PORTA,DIO_PIN2,STD_HIGH);
	_delay_us(1);
	dio_vidWriteChannel(DIO_PORTA,DIO_PIN2,STD_LOW);
	//Busy wait to allow LCD to process the command
	_delay_ms(2);
}
*/
void lcd_vidWritecomend(u8 value)
{
	int y=0;
	////////RS
	dio_vidWriteChannel(DIO_PORTA,DIO_PIN3,STD_LOW);
	for(int i=4;i<7;i++)
	{
		if(1==CHECK_BIT(value,i))
		{
			
			SET_BIT(DIO_PORTB_REG,y);
		}
		else
		{
			CLEAR_BIT(DIO_PORTB_REG,y);
		}
		y++;
	}
	if(1==CHECK_BIT(value,7))
	{
		
		SET_BIT(DIO_PORTB_REG,4);
		}else{
		CLEAR_BIT(DIO_PORTB_REG,4);
	}
	
	y=0;
	
	
	
	
	
	////////////////EN
	dio_vidWriteChannel(DIO_PORTA,DIO_PIN2,OUTPUT);
	_delay_us(1);
	dio_vidWriteChannel(DIO_PORTA,DIO_PIN2,INPUT);
	_delay_ms(2);

	////////////////////////////////////////////////////////////////////
	for(int i=0;i<3;i++)
	{
		if(1==CHECK_BIT(value,i))
		{
			
			SET_BIT(DIO_PORTB_REG,y);
			}else{
			CLEAR_BIT(DIO_PORTB_REG,y);
		}
		y++;
	}
	if(1==CHECK_BIT(value,3))
	{
		
		SET_BIT(DIO_PORTB_REG,4);
		}else{
		CLEAR_BIT(DIO_PORTB_REG,4);
	}

	///////////////////////////////////////////////////////////////




	dio_vidWriteChannel(DIO_PORTA,DIO_PIN2,OUTPUT);
	_delay_us(1);
	dio_vidWriteChannel(DIO_PORTA,DIO_PIN2,INPUT);
	_delay_ms(2);
	
	
}
	
	
lcd_sendCmd(u8 cmd)
{
	//Initializing LCD Data Port to Zero
	dio_vidWriteChannel(DataPort,D4PIN,STD_LOW);
	dio_vidWriteChannel(DataPort,D5PIN,STD_LOW);
	dio_vidWriteChannel(DataPort,D6PIN,STD_LOW);
	dio_vidWriteChannel(DataPort,D7PIN,STD_LOW);
	//Setting LCD to Command Mode
	dio_vidWriteChannel(CommandPort,RSPIN,STD_LOW);
	//Sending Higher nibble to Data Port
	dio_vidWriteChannel(DataPort,D4PIN,(CHECK_BIT(cmd,4)));
	dio_vidWriteChannel(DataPort,D5PIN,(CHECK_BIT(cmd,5)));
	dio_vidWriteChannel(DataPort,D6PIN,(CHECK_BIT(cmd,6)));
	dio_vidWriteChannel(DataPort,D7PIN,(CHECK_BIT(cmd,7)));
	dio_vidWriteChannel(CommandPort,EPIN,STD_HIGH);
	_delay_us(1);
	dio_vidWriteChannel(CommandPort,EPIN,STD_LOW);
	//Sending Lower nibble to Data Port
	dio_vidWriteChannel(DataPort,D4PIN,(CHECK_BIT(cmd,0)));
	dio_vidWriteChannel(DataPort,D5PIN,(CHECK_BIT(cmd,1)));
	dio_vidWriteChannel(DataPort,D6PIN,(CHECK_BIT(cmd,2)));
	dio_vidWriteChannel(DataPort,D7PIN,(CHECK_BIT(cmd,3)));
	dio_vidWriteChannel(CommandPort,EPIN,STD_HIGH);
	_delay_us(1);
	dio_vidWriteChannel(CommandPort,EPIN,STD_LOW);
	//Busy wait to allow LCD to process the command
	_delay_ms(2);
}



void enable_pulse(void)
{
	dio_vidWriteChannel(DIO_PORTA,DIO_PIN2,STD_HIGH);
	_delay_ms(1);
	dio_vidWriteChannel(DIO_PORTA,DIO_PIN2,STD_LOW);
}


void LCD_VoidSendNumber (u16 num)
{
	u16 rev=0;
	u16 x=0;
	while(num!=0)
	{
		rev=(rev*10)+(num%10);
		num=num/10;
	}

	while(rev!=0)
	{
		x=rev%10;
		rev=rev/10;
	lcd_vidWritedata(48+x);
	}
}