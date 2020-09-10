/*
 * main.c
 *
 *  Created on: May 23, 2020
 *      Author: my
 */

#ifndef F_CPU
#define F_CPU 8000000
#endif

#include <avr/io.h>
#include <avr/delay.h>

void main(void)
{
	DDRC = 255;
	DDRA = 0b10000000;

	while(1)
	{
		PORTC = 0b00111111;
		_delay_ms(1000);

		PORTC = 0b00000110;
		_delay_ms(1000);

		PORTC = 0b01011011;
		_delay_ms(1000);

		PORTC = 0b01001111;
		_delay_ms(1000);

		PORTC = 0b01100110;
		_delay_ms(1000);

		PORTC = 0b01101101;
		_delay_ms(1000);

		PORTC = 0b01111101;
		_delay_ms(1000);

		PORTC = 0b00000111;
		_delay_ms(1000);

		PORTC = 0b01111111;
		_delay_ms(1000);

		PORTC = 0b01101111;
		_delay_ms(1000);
	}
}
