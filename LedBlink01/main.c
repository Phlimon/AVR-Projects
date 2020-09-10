/*
 * main.c
 *
 *  Created on: May 23, 2020
 *      Author: Phlimon
 */

#ifndef F_CPU
#define F_CPU 8000000			//Define the Crystal Value
#endif

/*Libraries*/
#include <avr/io.h>				//Define the Digital Input Output for AVR (DIO)
#include <avr/delay.h>			//This Library for AVR Delay
// #include <util/delay.h>		//This Library for same Use Delay

void main(void)
{
	DDRA = 0b00000001;			//Make PIN (0) in Port A Output

	while(1)
	{
		PORTA = 0b00000001;		//Make PIN (0) in Port A HIGH
		_delay_ms(1000);		//Delay for 1 sec.
		PORTA = 0b00000000;		//Make PIN (0) in Port A LOW
		_delay_ms(1000);		//Delay for 1 sec.
	}
}






