

#ifndef UART_H_
#define UART_H_


#include "uart_reg.h"
#include "Std_Types.h"
#include "bit_math.h"
#include "UART_confg.h"

#define UART_BAUDRATE_1200			(0x340)
#define UART_BAUDRATE_2400			(0x1A0)
#define UART_BAUDRATE_4800			(0xCF)
#define UART_BAUDRATE_9600			(0x67)
#define UART_BAUDRATE_19200			(0x51)
#define UART_BAUDRATE_115200		(0x8)



void UART_Init(u16 baudRate);
void UART_TransmitChr(u8 data);
u8 UART_ReceiveChr(void);
void UART_EN_Rx (void);
void UART_DN_Rx (void);
void UART_EN_Data_Register_Empty (void);
void UART_DN_Data_Register_Empty (void);
void SREG_VoidEnable (void);
void SREG_VoidDisable (void);
void UART_send_string(u8 *str);
void UART_res_string(u8 *x);
u8 UART_check(void);

 
#endif  

