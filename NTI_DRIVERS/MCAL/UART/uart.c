
#include "std_types.h"
#include "bit_math.h"
#include "uart.h"
#include "uart_reg.h"
#include "UART_confg.h"
#include "dio.h"

extern character_size x;
u8 arr_res[100]={0};
	u8 j=0;

void UART_Init(u16 baudRate)
{
	/* Set baud rate */
	UBRRL = (u8)baudRate;
	UBRRH = (u8)(baudRate>>8);

	SET_BIT(UCSRB,4);//////////en Rx
	SET_BIT(UCSRB,3);//////////en Tx
    /*
	SET_BIT(UCSRB,1);///////Rx 8bit
	SET_BIT(UCSRB,0);///////Tx  8bit
	*/
	SET_BIT(UCSRC,7);/////register selection
	
	
	///////////////////////////////character size
	UCSRC&=0b11111001;
	UCSRC|=((x&3)<<1);
	UCSRB&=0b11111001;
	UCSRC|=(x&4);
	
}
	
	
	
	

void UART_TransmitChr(u8 data)
{
	while(CHECK_BIT(UCSRA,DIO_PIN5)!=1)
	{
		
	}
	UDR=data;
	
}

u8 UART_ReceiveChr(void)
{
      if(CHECK_BIT(UCSRA,DIO_PIN7)==0)
      {
	      return UDR;
      }
	  else {
		  return 0;
	  }
}


void UART_EN_Rx (void)
{
	SET_BIT(UCSRB,DIO_PIN7);
}
void UART_DN_Rx (void)
{
	CLEAR_BIT(UCSRB,DIO_PIN7);
}
void UART_EN_Data_Register_Empty (void)
{
	SET_BIT(UCSRB,DIO_PIN5);
}
void UART_DN_Data_Register_Empty (void)
{
	CLEAR_BIT(UCSRB,DIO_PIN5);
}

u8 buffr[100];
void UART_send_string(u8 *str)
{
	u8 i=0;
	if(i==0)
	{
		while(str[i]!='/0')
		{
			buffr[i]=str[i];
			i++;
		}
		buffr[i]='/0';
		UDR=buffr[0];
	}	
}  
void UART_res_string(u8 *x)
{
	u8 i=0;
	for( i=0;arr_res[i]!='!';i++)
	{
		x[i]=arr_res[i];
		
	}
   x[i]='\0';
   j=0;
}
u8 UART_check(void)
{
	if(arr_res[j]=='!')
	{
		return 1;
	}else{
		return 0;
	}
	
	
}

void __vector_13(void) __attribute__(( signal , used ));
void __vector_13(void)
{
        arr_res[j]=UDR;
		j++;
}

void __vector_14(void) __attribute__((signal , used));
void __vector_14 (void)
{
	static u8 i=1;
	if(buffr[i]!=0)
	{
		UDR=buffr[i];
		i++;	
	}else{
		i=1;
	}
	
}










void SREG_VoidEnable (void)
{
	SET_BIT(SREG,7);
}
void SREG_VoidDisable (void)
{
	CLEAR_BIT(SREG,7);
}