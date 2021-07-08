/*
 * DIO_config.h
 *
 * Created: 7/7/2021 4:18:33 AM
 *  Author: DELLL
 */ 


#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_

#include "DIO.h"
#include "types.h"
/* Macros to define INPUT and OUTPUT */
#define INPUT 0
#define OUTPUT 1

/* The pins used for each port */
typedef enum {
	PIN_0,
	PIN_1,
	PIN_2,
	PIN_3,
	PIN_4,
	PIN_5,
	PIN_6,
	PIN_7
	}EN_pins;

/* To configure the DIO pin direction before using it either as an input or an output */
typedef struct  
{
		uint8_t port;
		EN_pins pin;
		uint8_t dir;
}ST_DIO_config;

/* The status for Error handling */
typedef enum{
	E_VALID,
	E_INVALID
	}E_stat;

/* Digital low : 0v , Digital high : 5v*/
typedef enum
{
	LOW,
	HIGH
	}states;

/* Function prototypes */
E_stat DIO_init(ST_DIO_config* configurations);
ST_DIO_config* DIO_configurations(uint8_t port1,EN_pins pin1,uint8_t dir1);
E_stat DIO_write_pin(uint8_t port,EN_pins pin,uint8_t data);
E_stat DIO_pin_direction(uint8_t port,EN_pins pin,uint8_t data);
E_stat DIO_write_port(uint8_t port,uint8_t data);
E_stat DIO_read(uint8_t port,EN_pins pin,uint8_t* data_ptr);
E_stat DIO_toggle(uint8_t port,EN_pins pin);

/* The ports used */
typedef enum{
	DIO_PORTA,
	DIO_PORTB,
	DIO_PORTC,
	DIO_PORTD
	}PORTS;

/* A structure variable to be used for the initialization */
ST_DIO_config configs;

#endif /* DIO_CONFIG_H_ */