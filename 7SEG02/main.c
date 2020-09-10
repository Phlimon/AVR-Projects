/*
 * main.c
 *
 *  Created on: May 24, 2020
 *      Author: my
 */
typedef unsigned char u8;

#ifndef F_CPU
#define F_CPU 8000000
#endif

#include <avr/io.h>
#include <avr/delay.h>

void main(void)
{
	u8 _7SEG[10] = {0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110, 0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01101111};
	u8 i = 0;

	DDRC = 255;

	while(1)
	{
		for(i = 0; i < 10; i++)
		{
			PORTC = _7SEG[i];
			_delay_ms(1000);
		}
	}
}
