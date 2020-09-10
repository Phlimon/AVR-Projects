/*
 * main.c
 *
 *  Created on: May 25, 2020
 *      Author: my
 */

/*Types*/
#include "STD_TYPES.h"

/*Dependences*/
#include <util/delay.h>

/*Module*/
#include "DIO_interface.h"
#include "SEG_interface.h"

int main(void)
{
	u8 Local_u8Iteration = 0;
	u8 Local_u8ErrorCheck = 0;

	while(1)
	{
		/*on Single Digit show Character then wait a second then show the other character*/
//		Local_u8ErrorCheck = _7SEG_u8SingleDigit2('P);
//		_delay_ms(1000);
//		Local_u8ErrorCheck = _7SEG_u8SingleDigit2('H');
//		_delay_ms(1000);

		/*2 digits Number*/
//		Local_u8ErrorCheck = _7SEG_u8DoubleDigits(90);

		/*show on the 2 7SEG 2 Chrachters at once PH*/
		Local_u8ErrorCheck = _7SEG_u8SingleDigit2('P');
		Local_u8ErrorCheck = _7SEG_u8SingleDigit1('H');
		_delay_ms(2000);

		/*Incrementing Loop on Single Digit 0 -> 9*/
//		for(Local_u8Iteration = 0; Local_u8Iteration <= 9; Local_u8Iteration++)
//		{
//			Local_u8ErrorCheck = _7SEG_u8SingleDigit1(Local_u8Iteration);
//			_delay_ms(1000);
//		}

		/*Incrementing Loop on Single Digit 0 -> 99*/
		for(Local_u8Iteration = 0; Local_u8Iteration <= 99; Local_u8Iteration++)
		{
			Local_u8ErrorCheck = _7SEG_u8DoubleDigits(Local_u8Iteration);
			_delay_ms(1000);
		}

		/*Decrementing Loop on Single Digit 99 -> 0*/
//		for(Local_u8Iteration = 99; Local_u8Iteration >= 0; Local_u8Iteration--)
//		{
//			Local_u8ErrorCheck = _7SEG_u8DoubleDigits(Local_u8Iteration);
//			_delay_ms(1000);
//			if(Local_u8Iteration == 0)
//			{
//				Local_u8Iteration = 100;
//			}
//		}

		/*Decrementing Loop on Single Digit 9 -> 0*/
//		for(Local_u8Iteration = 9; Local_u8Iteration >= 0; Local_u8Iteration--)
//		{
//			Local_u8ErrorCheck = _7SEG_u8SingleDigit1(Local_u8Iteration);
//			_delay_ms(1000);
//			if(Local_u8Iteration == 0)
//			{
//				Local_u8Iteration = 10;
//			}
//		}
	}

	return 0;
}
