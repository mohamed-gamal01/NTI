
#ifndef UART_REG_H_
#define UART_REG_H_



#define SREG        *((volatile u8*  ) (0x5F))

 #define NULL 0

#define UDR			        (*(volatile u8* )0x2C)
#define UCSRA				(*(volatile u8* )0x2B)
#define UCSRB				(*(volatile u8* )0x2A)
#define UBRRH				(*(volatile u8* )0x40)
#define UCSRC				(*(volatile u8* )0x40)
#define UBRRL				(*(volatile u8* )0x29)


 
#endif 
