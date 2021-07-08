/*
 * DIO.c
 *
 * Created: 7/7/2021 4:18:02 AM
 *  Author: DELLL
 */ 

#include "DIO.h"
#include "types.h"
#include "DIO_config.h"
#include "math.h"
/*******************************************************************************
* Parameters (in) : configurations - A pointer to a structure
* Parameters (out): None
* Return Value : Error - For error handling if the user input an invalid parameter
* Description : Configure the DIO pins direction to be input or output
********************************************************************************/
E_stat DIO_init(ST_DIO_config* configurations)
{
	E_stat Error=E_INVALID;
	if(((configurations->port <= DIO_PORTD)||(configurations->port >= DIO_PORTA))&&
	((configurations->pin <= PIN_7)||(configurations->pin >= PIN_0)))
	{
		switch(configurations->port)
		{
			case DIO_PORTA:
			{
				if(configurations->dir == OUTPUT)
				{
					SET_BIT(DIO_CONTROL_A,configurations->pin);
				}else
				{
					CLR_BIT(DIO_CONTROL_A,configurations->pin);
				}
				break;
			}
			case DIO_PORTB:
			{
				if(configurations->dir == OUTPUT)
				{
					SET_BIT(DIO_CONTROL_B,configurations->pin);
				}else
				{
					CLR_BIT(DIO_CONTROL_B,configurations->pin);
				}
				break;
			}
			case DIO_PORTC:
			{
				if(configurations->dir == OUTPUT)
				{
					SET_BIT(DIO_CONTROL_C,configurations->pin);
				}else
				{
					CLR_BIT(DIO_CONTROL_C,configurations->pin);
				}
				break;
			}
			case DIO_PORTD:
			{
				if(configurations->dir == OUTPUT)
				{
					SET_BIT(DIO_CONTROL_D,configurations->pin);
				}else
				{
					CLR_BIT(DIO_CONTROL_D,configurations->pin);
				}
				break;
			}

		}
	}
	return Error;
}

/*******************************************************************************
* Parameters (in) : port - The port to be used (A or B or C or D)
					pin - The pin we select to write
					data - To choose whether to put LOW or HIGH on the pin
* Parameters (out): None
* Return Value : Error - For error handling if the user input an invalid parameter
* Description : Output a HIGH or LOW on the pins if they are selected to be OUTPUT
********************************************************************************/

E_stat DIO_write_pin(uint8_t port,EN_pins pin,uint8_t data)
{
	E_stat Error=E_INVALID;
	if(((port <= DIO_PORTD)||(port >= DIO_PORTA))&&
	((pin <= PIN_7)||(pin >= PIN_0)))
	{
		Error = E_VALID;
		switch(port)
		{
			case DIO_PORTA:
			{
				if(data == HIGH)
				{
					SET_BIT(DIO_DATA_A,pin);					
				}else
				{
					CLR_BIT(DIO_DATA_A,pin);
				}
				break;
			}
			case DIO_PORTB:
			{
				if(data == HIGH)
				{
					SET_BIT(DIO_DATA_B,pin);
				}else
				{
					CLR_BIT(DIO_DATA_B,pin);
				}
				break;
			}
			case DIO_PORTC:
			{
				if(data == HIGH)
				{
					SET_BIT(DIO_DATA_C,pin);
				}else
				{
					CLR_BIT(DIO_DATA_C,pin);
				}
				break;
			}
			case DIO_PORTD:
			{
				if(data == HIGH)
				{
					SET_BIT(DIO_DATA_D,pin);
				}else
				{
					CLR_BIT(DIO_DATA_D,pin);
				}
				break;
			}

		}
	}
	return Error;
}


/*******************************************************************************
* Parameters (in) : port - The port to be used (A or B or C or D)
					data - To choose whether to put LOW or HIGH on the pin
* Parameters (out): None
* Return Value : Error - For error handling if the user input an invalid parameter
* Description : Output a HIGH or LOW on the ports if they are selected to be OUTPUT
********************************************************************************/
E_stat DIO_write_port(uint8_t port,uint8_t data)
{
	E_stat Error=E_INVALID;
	if(((port <= DIO_PORTD)||(port >= DIO_PORTA)))
	{
		Error = E_VALID;
		switch(port)
		{
			case DIO_PORTA:
			{
				DIO_DATA_A=data;
				break;
			}
			case DIO_PORTB:
			{
				DIO_DATA_B=data;
				break;
			}
			case DIO_PORTC:
			{
				DIO_DATA_C=data;
				break;
			}
			case DIO_PORTD:
			{
				DIO_DATA_D=data;
				break;
			}

		}
	}
	return Error;
}

/*******************************************************************************
* Parameters (in) : port - The port to be used (A or B or C or D)
					pin - The pin we select to write
					*data - A pointer to read the data
* Parameters (out): None
* Return Value : Error - For error handling if the user input an invalid parameter
* Description : Read the DIO pins if they are selected as INPUT
********************************************************************************/
E_stat DIO_read(uint8_t port,EN_pins pin,uint8_t* data_ptr)
{
	E_stat Error=E_INVALID;
	if(((port <= DIO_PORTD)||(port >= DIO_PORTA))&&
	((pin <= PIN_7)||(pin >= PIN_0)))
	{
		Error = E_VALID;
		switch(port)
		{
			case DIO_PORTA:
			{
				*data_ptr=GET_BIT(DIO_STATUS_A,pin); 
				break;
			}
			case DIO_PORTB:
			{
				*data_ptr=GET_BIT(DIO_STATUS_B,pin);
				break;
			}
			case DIO_PORTC:
			{
				*data_ptr=GET_BIT(DIO_STATUS_C,pin);
				break;
			}
			case DIO_PORTD:
			{
				*data_ptr=GET_BIT(DIO_STATUS_D,pin);
				break;
			}

		}
	}
	return Error;
}

/*******************************************************************************
* Parameters (in) : port - The port to be used (A or B or C or D)
					pin - The pin we select to write
* Parameters (out): None
* Return Value : Error - For error handling if the user input an invalid parameter
* Description : Toggle the DIO pins if they are selected as outputs
********************************************************************************/
E_stat DIO_toggle(uint8_t port,EN_pins pin)
{
	E_stat Error=E_INVALID;
	if(((port <= DIO_PORTD)||(port >= DIO_PORTA))&&
	((pin <= PIN_7)||(pin >= PIN_0)))
	{
		Error = E_VALID;
		switch(port)
		{
			case DIO_PORTA:
			{
				TOG_BIT(DIO_DATA_A,pin);
				break;
			}
			case DIO_PORTB:
			{
				TOG_BIT(DIO_DATA_B,pin);
				break;
			}
			case DIO_PORTC:
			{
				TOG_BIT(DIO_DATA_C,pin);
				break;
			}
			case DIO_PORTD:
			{
				TOG_BIT(DIO_DATA_D,pin);
				break;
			}

		}
	}
	return Error;
}
