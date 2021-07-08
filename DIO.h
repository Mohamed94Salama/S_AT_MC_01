/*
 * DIO.h
 *
 * Created: 7/7/2021 4:18:18 AM
 *  Author: DELLL
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "types.h"

//PORT A REGISTERS
#define DIO_CONTROL_A	*((volatile uint8_t*)(0x3A))
#define DIO_DATA_A		*((volatile uint8_t*)(0x3B))
#define DIO_STATUS_A	*((volatile uint8_t*)(0x39))

//PORT B REGISTERS
#define DIO_CONTROL_B	*((volatile uint8_t*)(0x37))
#define DIO_DATA_B		*((volatile uint8_t*)(0x38))
#define DIO_STATUS_B	*((volatile uint8_t*)(0x36))

//PORT A REGISTERS
#define DIO_CONTROL_C	*((volatile uint8_t*)(0x34))
#define DIO_DATA_C		*((volatile uint8_t*)(0x35))
#define DIO_STATUS_C	*((volatile uint8_t*)(0x33))

//PORT A REGISTERS
#define DIO_CONTROL_D	*((volatile uint8_t*)(0x31))
#define DIO_DATA_D		*((volatile uint8_t*)(0x32))
#define DIO_STATUS_D	*((volatile uint8_t*)(0x30))


#endif /* DIO_H_ */