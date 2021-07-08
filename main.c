/*
 * DIO_DRIVER.c
 *
 * Created: 7/7/2021 4:14:51 AM
 * Author : DELLL
 */ 

#include "types.h"
#include "DIO_config.h"
#include "math.h"
/* To configure the DIO pin direction before using it either as an input or an output */
/*
typedef struct
{
	uint8_t port;
	EN_pins pin;
	uint8_t dir;
}ST_DIO_config;

for port : DIO_PORTA , DIO_PORTB , DIO_PORTB , DIO_PORTD
for pin : PIN_0 , PIN_1 , PIN_2 , PIN_3, PIN_4 , PIN_5 , PIN_6 , PIN_7
for dir : INPUT , OUTPUT
*/
int main(void)
{
	//configuring the output pin
	configs.port=DIO_PORTA;
	configs.pin=PIN_0;
	configs.dir=OUTPUT;
	DIO_init(&configs);
	//Make the output pin initially high
	DIO_write_pin(DIO_PORTA,PIN_0,HIGH);
	//configuring the input pin
	configs.port=DIO_PORTC;
	configs.pin=PIN_0;
	configs.dir=INPUT;	
	DIO_init(&configs);
	//a variable to return the data we get by the DIO
	uint8_t in_data;
    
    while (1) 
    {
		//read the DIO
		DIO_read(DIO_PORTC,PIN_0,&in_data);
		if(in_data==HIGH)
		{
			DIO_toggle(DIO_PORTA,PIN_0);
		}
	}
	return 0;
}

