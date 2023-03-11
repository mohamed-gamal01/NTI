/****************************************************************/
/*   Author             :    Mohamed Gamal				    */
/*	 Date 				:    25 January 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    contain the Memory mapped of		*/	
/*							 [MCUCR,MCUCSR,GICR,GIFR] Registers */
/****************************************************************/


/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/

#ifndef _ADC_PRIV_H
#define _ADC_PRIV_H


/****************************************************************/	
/** !comment : From Data Sheet :  Memory mapped of ADCSRA    	*/
/**			   Register	is  0X26						    	*/
/****************************************************************/
/**			   ADCSRA : MCU Control Register contains control	*/
/** 		   bits for interrupt sense control and general 	*/
/**            MCU functions.							    	*/
/****************************************************************/

#define ADCSRA		*((volatile u8 * ) (0X26))

/****************************************************************/	
/** !comment : From Data Sheet :  Memory mapped of MCUCSR   	*/
/**			   Register	is  0X54.								*/
/****************************************************************/
/**			   MCUCSR : MCU Control and Status Register			*/
/****************************************************************/

#define ADMUX       *((volatile u8 * ) (0X27))

/****************************************************************/	
/** !comment : From Data Sheet :  Memory mapped of GICR     	*/
/**			   Register	is  0X5B.								*/
/****************************************************************/
/**			   GICR : General Interrupt Control Register		*/
/****************************************************************/

#define ADCL        *((volatile u8 * ) (0X24))


/****************************************************************/	
/** !comment : From Data Sheet :  Memory mapped of GIFR     	*/
/**			   Register	is  0X5A.						    	*/
/****************************************************************/
/**			   GIFR : General Interrupt Flag Register			*/
/****************************************************************/

#define ADCH        *((volatile u8 * ) (0X25))
/****************************************************************/
/** !comment : From Data Sheet :  Memory mapped of GIFR     	*/
/**			   between ADCH and ADCL						    	*/
/****************************************************************/
/**			   GIFR : General Interrupt Flag Register			*/
/****************************************************************/

#define ADC_D       *((volatile u16 * ) (0X24))

/****************************************************************/
/** !comment : From Data Sheet :  Memory mapped of SFIOR    	*/
/**			                     						    	*/
/****************************************************************/

#define SFIOR       *((volatile u8 * ) (0X50))

/****************************************************************/
/** !comment : From Data Sheet :  Memory mapped of SERG     	*/
/**			   Register	is  0X5F.						    	*/
/****************************************************************/
/**			  SREG :global Interrupt Enable 			*/
/****************************************************************/


#define SREG        *((volatile u8*  ) (0x5F))

//****************************************************************/
/* Description    : This function used to interrupt ADC			*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/

void __vector_16(void)__attribute__((signal,used));


#endif	/**!comment : End of the guard [_ADC_PRIV_H]		   **/