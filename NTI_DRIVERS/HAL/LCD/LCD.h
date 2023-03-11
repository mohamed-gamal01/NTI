/*
 * LCD.h
 *
 * Created: 2/18/2023 1:41:57 PM
 *  Author: CONNECT
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "dio.h"
#include "dio_types.h"
#include "bit_math.h"
#include "avr/delay.h"

void lcd_int(void);
void lcd_vidWritedata(u8 value);
void lcd_vidWritecomend(u8 value);
void enable_pulse(void);

void LCD_VoidSendNumber (u16 num);
void lcd_sendCmd(u8 cmd);

typedef enum{
	HomeReturn=0x02,
	ClearLCD=0x01,
	DisplayCursor=0x0E,
	HideCursor=0x0C,
	MatrixFiveByTen=0x28
}lcd_Cmd_Type;

#define CommandPort DIO_PORTA
#define RSPIN DIO_PIN3
#define EPIN DIO_PIN2
#define DataPort DIO_PORTB
#define D4PIN DIO_PIN0
#define D5PIN DIO_PIN1
#define D6PIN DIO_PIN2
#define D7PIN DIO_PIN4


#endif /* LCD_H_ */