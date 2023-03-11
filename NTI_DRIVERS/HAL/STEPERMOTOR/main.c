/*
 * steper_motor.c
 *
 * Created: 3/2/2023 12:18:26 AM
 * Author : CONNECT
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include "STD_Types.h"
#include "Bit_Math.h"
#include "avr/delay.h"
#include "dio.h"
#include "steper_motor_confg.h"
#include "steper_motor.h"


int main(void)
{
    //steper_motor_int();
	
	
	
	
    while (1) 
    {
		
		steper_motor();
		
		
		
		
		
    }
}

