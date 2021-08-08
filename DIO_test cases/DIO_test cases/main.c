/*
 * DIO_test cases.c
 *
 * Created: 8/6/2021 11:53:31 AM
 * Author : DELLL
 */ 

#include "DIO_testcases.h"


int main(void)
{
	uint8_t* x;
	UART_Init();
    DIO_Init_test();
	DIO_Write_test(0,HIGH);
	DIO_Read_test(1, &x);
	DIO_Toggle_test(0);
    while (1) 
    {
    }
}

