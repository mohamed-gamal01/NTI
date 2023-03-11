/*
 * SPI_private.h
 *
 * Created: 3/4/2023 1:37:30 PM
 *  Author: CONNECT
 */ 


#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_


#define SPCR (*((volatile u8 *)0x2D ))
#define SPSR (*((volatile u8 *)0x2E ))
#define SPDR (*((volatile u8 *)0x2F ))

#define	rising      0
#define	falling     1

/*
#define fequence_4       0
#define fequence_16      1
#define fequence_64      2
#define fequence_128     3
#define fequence_2       4 
#define fequence_8       5 
#define fequence_32      6
*/


#endif /* SPI_PRIVATE_H_ */