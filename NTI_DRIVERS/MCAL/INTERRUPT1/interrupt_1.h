/****************************************************************/
/*   Author             :    Mohamed Gamal				        */
/*	 Date 				:    25 January 2023     				*/
/*	 Version 			:    							    	*/
/*	 Description 		:   external interrupt     1            */
/*							                                	*/
/****************************************************************/



/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/

#ifndef _INTERRUPT_H
#define _INTERRUPT_H


/****************************************************************/
/** !comment : Sense Mode Definition					   		*/
/****************************************************************/

#define IOC			1
#define FALLING		4
#define RISING		7
#define LOW_LEVEL	10



/****************************************************************/
/* Description    :  This function used to initialization     */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/
void EXT1_voidInit ( void );


/****************************************************************/
/* Description    : This function used to Enable			*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/
void EXT1_voidEnable( void );


/****************************************************************/
/* Description    : This function used to Disable 		*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/
void EXT1_voidDisable( void );

typedef void (*pf) (void);
/****************************************************************/
/* Description    : This function used to communicate with the	*/
/*					function in App Layer(The Callback function)*/
/*						[ Layer Architecture Problem Solved ]	*/
/*																*/
/*					Inputs : Pointer to function that points to	*/
/*							 the first line of the function(ISR)*/
/*					Return : void								*/
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/
void EXT1_voidCallBack(pf addresscpy);


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
void EXT1_voidSetSignalch(u8 SenseCpy);


/****************************************************************/
/* Description    : This function used to Check if interrupt is */
/*					Executed or Not.							*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : flag Status [ LBTY_OK , LBTY_NOK ]	*/
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/
/*
flagStatus EXT1_enuIsExecuted( void );
*/
void SREG_VoidEnable (void);

void SREG_VoidDisable (void);


#endif	/**!comment : End of the gaurd [_INTERRUPT_H]		   **/
