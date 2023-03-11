/*
 * SPI.c
 *
 * Created: 3/4/2023 1:37:01 PM
 *  Author: CONNECT
 */

#include "bit_math.h"
#include "std_types.h"
#include "SPI_private.h"
#include "SPI.h"
#include "dio.h"
#include "SPI_confg.h"



void SPI_Master_Int (void)
{
	dio_vidConfigChannel(port,sck,OUTPUT);
	dio_vidConfigChannel(port,Miso,INPUT);
	dio_vidConfigChannel(port,Mosi,OUTPUT);
	dio_vidConfigChannel(port,SS,OUTPUT);
	
	dio_vidWriteChannel(port,SS,STD_HIGH);

	//enable
	SET_BIT(SPCR,6);
	///msb ,lsb 
	CLEAR_BIT(SPCR,5);
    //	
	SET_BIT(SPCR,4);
	
	#if  Leading_Edge==rising
	   CLEAR_BIT(SPCR,3);
	#elif  Leading_Edge==falling
	    SET_BIT(SPCR,3);  
	#endif	
	/*
	SPCR&=0b11111100;
	
	SPCR|=(z&3);
	
	SPSR&=0B11111110;
	SPSR=((z&4)>>3);
	*/
	
	 #if  frequece ==fequence_4
	   CLEAR_BIT(SPCR,0);
	   CLEAR_BIT(SPCR,1);
	   CLEAR_BIT(SPSR,0);
	
	 #elif  frequece ==fequence_16
	 SET_BIT(SPCR,0);
	 CLEAR_BIT(SPCR,1);
	 CLEAR_BIT(SPSR,0);
	 #elif  frequece ==fequence_64
	 CLEAR_BIT(SPCR,0);
	 SET_BIT(SPCR,1);
	 CLEAR_BIT(SPSR,0);
	 #elif  frequece ==fequence_128
	 SET_BIT(SPCR,0);
	 SET_BIT(SPCR,1);
	 CLEAR_BIT(SPSR,0);
	 #elif  frequece ==fequence_2
	 CLEAR_BIT(SPCR,0);
	 CLEAR_BIT(SPCR,1);
	 SET_BIT(SPSR,0);
	 #elif  frequece ==fequence_8
	 SET_BIT(SPCR,0);
	 CLEAR_BIT(SPCR,1);
	 SET_BIT(SPSR,0);
	 #elif  frequece ==fequence_32
	   CLEAR_BIT(SPCR,0);
	   SET_BIT(SPCR,1);
	   SET_BIT(SPSR,0);
	  #elif  frequece ==fequence_128
	   SET_BIT(SPCR,0);
	   SET_BIT(SPCR,1);
	   SET_BIT(SPSR,0);
	  #endif
	  
	
}

void SPI_Slave_Int (void)
{
	dio_vidConfigChannel(port,sck,INPUT);
	dio_vidConfigChannel(port,Miso,OUTPUT);
	dio_vidConfigChannel(port,Mosi,INPUT);
	dio_vidConfigChannel(port,SS,INPUT);
	

	
	SET_BIT(SPCR,6);
	CLEAR_BIT(SPCR,5);
	CLEAR_BIT(SPCR,4); ////////slave

	
	/*
	SPCR&=0B11111100;
	SPCR|=(z&3);
	
	SPSR&=0B11111110;
	SPSR=((z&4)>>3);
	*/
	
	
	#if  Leading_Edge==rising
	CLEAR_BIT(SPCR,3);
	#elif  Leading_Edge==falling
	SET_BIT(SPCR,3);
	#endif
	
	#if  frequece ==fequence_4
	CLEAR_BIT(SPCR,0);
	CLEAR_BIT(SPCR,1);
	CLEAR_BIT(SPSR,0);
	
	#elif  frequece ==fequence_16
	SET_BIT(SPCR,0);
	CLEAR_BIT(SPCR,1);
	CLEAR_BIT(SPSR,0);
	
	#elif  frequece ==fequence_64
	CLEAR_BIT(SPCR,0);
	SET_BIT(SPCR,1);
	CLEAR_BIT(SPSR,0);
	
	#elif  frequece ==fequence_128
	SET_BIT(SPCR,0);
	SET_BIT(SPCR,1);
	CLEAR_BIT(SPSR,0);
	
	#elif  frequece ==fequence_2
	CLEAR_BIT(SPCR,0);
	CLEAR_BIT(SPCR,1);
	SET_BIT(SPSR,0);
	
	#elif  frequece ==fequence_8
	SET_BIT(SPCR,0);
	CLEAR_BIT(SPCR,1);
	SET_BIT(SPSR,0);
	
	#elif  frequece ==fequence_32
	CLEAR_BIT(SPCR,0);
	SET_BIT(SPCR,1);
	SET_BIT(SPSR,0);
	
	#elif  frequece ==fequence_128
	SET_BIT(SPCR,0);
	SET_BIT(SPCR,1);
	SET_BIT(SPSR,0);
	
	#endif
	
	
}


u8 SPI_Send_Byte (u8 data)
{
	dio_vidWriteChannel(port,SS,STD_LOW);
	SPDR=data;
	while(CHECK_BIT(SPSR,7)==0);
	return SPDR;
	
}