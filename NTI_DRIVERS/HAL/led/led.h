/*
 * led.h
 *
 * Created: 3/11/2023 10:47:48 AM
 *  Author: CONNECT
 */ 


#ifndef LED_H_
#define LED_H_

#include "dio.h"
#include "led_confg.h"

void led_int(void);
void led_on(u8 ID);
void led_off(u8 ID);
void led_toggle(u8 ID);


#endif /* LED_H_ */