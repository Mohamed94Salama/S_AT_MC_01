/*
 * DIO_testcases.h
 *
 * Created: 8/6/2021 11:59:46 AM
 *  Author: DELLL
 */ 


#ifndef DIO_TESTCASES_H_
#define DIO_TESTCASES_H_

#include "DIO.h"
#include "UART.h"

void DIO_Init_test(void);

void DIO_Write_test(uint8_t u8GroupId, uint8_t u8Data);

void DIO_Read_test(uint8_t u8GroupId, uint8_t* pu8Data);

void DIO_Toggle_test(uint8_t u8GroupId);

#endif /* DIO_TESTCASES_H_ */