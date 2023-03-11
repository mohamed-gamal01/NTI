/************************************************************/
/* 	Author 	 	 : Ahmed Atia Atia                          */
/* 	Date   		 : 2 May 2019	                            */
/* 	Version 	 : 1V 									    */
/* 	Description	 : prog.c for ADC		                    */
/************************************************************/


/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/

#include "STD_Types.h"
#include "Bit_Math.h"


/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "ADC_interrupt_int.h"
#include "ADC_interrupt_config.h"
#include "ADC_interrupt_private.h" 
#include "avr/delay.h"


 #define NULL 0

/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/


/****************************************************************/
/* Description    :  This function used to initialize ADC 	    */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/

void ADC_voidInit (void)
{
	//////////// AVCC with external capacitor at AREF pin
 	SET_BIT(ADMUX,6);
 	CLEAR_BIT(ADMUX,7);
 	//////////////////////////from left to write
 	CLEAR_BIT(ADMUX,5);
 	
 	//////////////////////EN
 	SET_BIT( ADCSRA,7);
	 
 	
 	/////////////////// TRIGGER
 	CLEAR_BIT(ADCSRA,5);
 	////////////////////////ADC Interrupt Enable
 	SET_BIT(ADCSRA,3);
 	
 	
 	SET_BIT(ADCSRA,0);
 	SET_BIT(ADCSRA,1);
 	SET_BIT(ADCSRA,2);
	
}


/****************************************************************/
/* Description    : This function used to Enable ADC			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidEnable()
{
	
	SET_BIT( ADCSRA , 7 );
	
}

/****************************************************************/
/* Description    : This function used to Enable ADC Interrput	*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidInterrputEnable()
{

	
	SET_BIT( ADCSRA , 3 );
	
}


/****************************************************************/
/* Description    : This function used to Disable ADC			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidDisable()
{
	
	CLEAR_BIT( ADCSRA , 7 );
	
}


/****************************************************************/
/* Description    : This function used to Start converting		*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidStartConversion()
{
	
	SET_BIT( ADCSRA , 6 );
	
}


/****************************************************************/
/* Description    : This function used to Set lach Interrupt	*/
/*									 happens.					*/ 
/*																*/
/*					Inputs : Sense Mode				  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidAutoTrigger()
{
	

	
/****************************************************************/	
/** !comment : From Data Sheet : Starting conversion on positive*/
/*			   edge when ADATE = 1						    	*/
/****************************************************************/

	
	/** Enable ADC Auto Trigger	 							   **/
	/** ADATE = 1 =====> 	SET_BIT( ADATE , 5 ); 			   **/

    SET_BIT( ADCSRA , 5 );
	

		/*  ( if / else if ) condition for Macros */
	#if ADC_AUTO_TRIGGER_SOURCE == FREE_RUNNING_MODE 
	CLEAR_BIT( SFIOR , 0 );
	CLEAR_BIT( SFIOR , 1 );
	CLEAR_BIT( SFIOR , 2 );
	
	#elif ADC_AUTO_TRIGGER_SOURCE == ANALOG_COMPARATOR
	SET_BIT( SFIOR , 0 );
	CLEAR_BIT( SFIOR , 1 );
	CLEAR_BIT( SFIOR , 2 );
	
	#elif ADC_AUTO_TRIGGER_SOURCE == EXTERNAL_INTERRPUT_REQUEST_0
	CLEAR_BIT( SFIOR , 0 );
	SET_BIT( SFIOR , 1 );
	CLEAR_BIT( SFIOR , 2 );
	
	
	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_0_COMPARE_MATCH
	SET_BIT( SFIOR , 0 );
	SET_BIT( SFIOR , 1 );
	CLEAR_BIT( SFIOR , 2 );

	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_0_OVERFLOW
	CLEAR_BIT( SFIOR , 0 );
	CLEAR_BIT( SFIOR , 1 );
	SET_BIT( SFIOR , 2 );
	
	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_COMPARE_MATCH_B
	SET_BIT( SFIOR , 0 );
	CLEAR_BIT( SFIOR , 1 );
	SET_BIT( SFIOR , 2 );

	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_1_OVERFLOW
	CLEAR_BIT( SFIOR , 0 );
	SET_BIT( SFIOR , 1 );
	SET_BIT( SFIOR , 2 );

	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_1_CAPTURE_EVENT
	SET_BIT( SFIOR , 0 );
	SET_BIT( SFIOR , 1 );
	SET_BIT( SFIOR , 2 );	
	
	#endif
	/* End ( if ) condition for Macros */
	
}


/****************************************************************/
/* Description    : This function used to Read ADC and 			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : u16 Digital Converting melli Volt	*/
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

u16 ADC_u16ReadADCInMV(u8 num_channel)
{
	ADMUX=ADMUX&0b11100000;
	ADMUX=ADMUX|num_channel;
	
	SET_BIT(ADCSRA,6);
	while(CHECK_BIT(ADCSRA,4)==0)
	{
		
	}
	
	SET_BIT(ADCSRA,4);

	
	return ADC_D;
	
}


void SREG_VoidEnable (void)
{
	SET_BIT(SREG,7);
}
void SREG_VoidDisable (void)
{
	CLEAR_BIT(SREG,7);
}


pf y;
void ADC_CallBack(pf x)
{
	if(x !=NULL)
	{
		y = x;
	}
	
}

void __vector_16(void)
{
	y();
}

/***********************************************************************************************/
/************************************* END OF PROGRAM ******************************************/
/***********************************************************************************************/