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
#include <stdio.h>
#include <avr/io.h>
#include "BIT_MATH.h"

/*Module*/
#include "DIO_interface.h"
#include "SEG_interface.h"
#include "IR_interface.h"

int main(void)
{
	/*Local Variables*/
	u8 Local_u8IRValue = 0, Local_u8Counter = 0, Local_7SEGError = 0, Local_u8IRError = 0;

	/*Initializing the IR Sensor*/
	IR_u8Initialize();

	while(1)
	{
		/*Get the Value of IR Sensor*/
		Local_u8IRError = IR_u8GetValue(&Local_u8IRValue);

		/*If it TRUE Raise the Counter*/
		if(Local_u8IRValue == TRUE)
		{
			Local_u8Counter++;

			/*if Counter reach 100 git it Back to ZERO*/
			if(Local_u8Counter == 100)
			{
				Local_u8Counter = 0;
			}
		}

		/*Show the result on the 7SEG Displays*/
		Local_7SEGError = _7SEG_u8DoubleDigits(Local_u8Counter);

	}
	return 0;
}


























//int main(void)
//{
//	u8 Local_u8ErrorCheck = 0, Local_u8Counter = 0, Local_u8IRValue = 0;
//
//	IR_u8Intialize();
//
//	while(1)
//	{
//		Local_u8ErrorCheck = IR_u8GetValue(&Local_u8IRValue);
//
//		if(Local_u8IRValue == DIO_HIGH)
//		{
//			Local_u8Counter++;
//			_7SEG_u8DoubleDigits(Local_u8Counter);
//			Local_u8IRValue = 0;
//		}
//	}
//	return 0;
//}
