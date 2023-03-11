/*
 * keypad.h
 *
 * Created: 2/18/2023 11:20:15 PM
 *  Author: CONNECT
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "dio.h"
#include "dio_types.h"
#include "bit_math.h"
#include "avr/delay.h"

void keypad_int(void);
u8 keyad_getnumber(void);


#endif /* KEYPAD_H_ */