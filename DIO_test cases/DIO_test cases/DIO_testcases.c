/*
 * DIO_testcases.c
 *
 * Created: 8/6/2021 11:59:25 AM
 *  Author: DELLL
 */ 
#include "DIO_testcases.h"
void DIO_Init_test(void)
{
	uint8_t res=DIO_Init();
	if(res==E_OK)
	{
		UART_SendString("PASS");
		UART_SendData('\r');
	}else if(res==E_ERROR)
	{
		UART_SendString("Failed");
		UART_SendData('\r');
	}
}

void DIO_Write_test(uint8_t u8GroupId, uint8_t u8Data)
{
	uint8_t res=DIO_Write(u8GroupId, u8Data);
	if(res==E_OK)
	{
		UART_SendString("PASS");
		UART_SendData('\r');
	}else if(res==E_ERROR)
	{
		UART_SendString("Failed");
		UART_SendData('\r');
	}
}

void DIO_Read_test(uint8_t u8GroupId, uint8_t* pu8Data)
{
	uint8_t res=DIO_Read(u8GroupId, pu8Data);
	if(res==E_OK)
	{
		UART_SendString("PASS");
		UART_SendData('\r');
	}else if(res==E_ERROR)
	{
		UART_SendString("Failed");
		UART_SendData('\r');
	}	
}

void DIO_Toggle_test(uint8_t u8GroupId)
{
	uint8_t res=DIO_Toggle(u8GroupId);
	if(res==E_OK)
	{
		UART_SendString("PASS");
		UART_SendData('\r');
	}else if(res==E_ERROR)
	{
		UART_SendString("Failed");
		UART_SendData('\r');
	}	
}