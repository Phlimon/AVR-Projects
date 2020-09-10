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
#include "LCD_interface.h"
#include "IR_interface.h"

int main(void)
{
	/*Local Variables*/
	u8 Local_u8IRValue = 0, Local_7SEGError = 0, Local_u8IRError = 0;
	u32 Local_u32Counter = 0;
	u8 Local_u8String[] = "IR Sensor Read:";
	u8 Local_u8StringSize = sizeof(Local_u8String) - 1;

	/*Initializing the IR Sensor*/
	IR_u8Initialize();

	LCD_voidInitialization();

	while(1)
	{
		/*Get the Value of IR Sensor*/
		Local_u8IRError = IR_u8GetValue(&Local_u8IRValue);

		/*If it TRUE Raise the Counter*/
		if(Local_u8IRValue == TRUE)
		{
			Local_u32Counter++;

			/*if Counter reach 100 git it Back to ZERO*/
			if(Local_u32Counter == 100)
			{
				Local_u32Counter = 0;
				LCD_voidClearLCD();
			}
		}

		/*Show the result on the 7SEG Displays*/
		LCD_u8GoToXY(0, 0);
		LCD_u8WriteString(Local_u8String, Local_u8StringSize);

		LCD_u8WriteINT(Local_u32Counter, 9, 1);
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
