/*
 * SPI_confg.h
 *
 * Created: 3/4/2023 1:59:36 PM
 *  Author: CONNECT
 */ 


#ifndef SPI_CONFG_H_
#define SPI_CONFG_H_

#include "dio.h"
#include "SPI_private.h"


#define port    DIO_PORTB
#define sck     DIO_PIN7
#define Miso    DIO_PIN6
#define Mosi    DIO_PIN5
#define SS      DIO_PIN4


typedef enum{
	 fequence_4       =0,
	 fequence_16      =1,
	 fequence_64      =2,
	 fequence_128     =3,
	 fequence_2       =4,
	 fequence_8       =5,
	 fequence_32      =6
	
	}prescaler;


#define Leading_Edge      falling

#define frequece          fequence_4



#endif /* SPI_CONFG_H_ */