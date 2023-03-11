/*
 * SPI.h
 *
 * Created: 3/4/2023 1:37:56 PM
 *  Author: CONNECT
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "bit_math.h"
#include "std_types.h"
#include "SPI_confg.h"

void SPI_Slave_Int (void);
void SPI_Master_Int (void);
u8 SPI_Send_Byte (u8 data);



#endif /* SPI_H_ */