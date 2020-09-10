/*
 * main.c
 *
 *  Created on: May 29, 2020
 *      Author: my
 */

/*Standard Types*/
#include "STD_TYPES.h"

/*Module*/
#include <util/delay.h>
#include "DIO_interface.h"
#include "LCD_interface.h"

void main(void)
{
	u8 Local_u8Move = 0, Local_u8Move2 = 0, Local_u8Move3 = 0;
	u8 Local_u8String[] = "Phlimon 01111879762 "; //Max 20 Char
	u8 Local_u8StringSize = (sizeof(Local_u8String) - 1);
	u8 Copy_u8StringSize = Local_u8StringSize;

	DIO_u8SetPortDirection(LCD_DATA_PORT, DIO_MAX_PORT_VALUE);
	DIO_u8SetPinDirection(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_OUTPUT);
	DIO_u8SetPinDirection(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_OUTPUT);
	DIO_u8SetPinDirection(LCD_CONTROL_PORT, LCD_E_PIN, DIO_OUTPUT);

	LCD_voidInitialization();

	while(1)
	{
		Local_u8Move2 = LCD_OV_LINE_2 + (Local_u8StringSize + 1);
		Local_u8Move3 = LCD_LINE_NB_OF_DIGITS;

		for(Local_u8Move = (LCD_OV_LINE_2); Local_u8Move <= Local_u8Move2; Local_u8Move--)
		{
			LCD_u8GoToXY(Local_u8Move, 1);
			LCD_u8WriteString(Local_u8String, Local_u8StringSize);

			if(Local_u8StringSize < LCD_LINE_NB_OF_DIGITS)
			{
				LCD_u8GoToXY(Local_u8Move3 , 1);
				LCD_u8WriteString(Local_u8String, Local_u8StringSize);
				Local_u8Move3--;
			}
			else
			{
				LCD_u8GoToXY(Copy_u8StringSize, 1);
				LCD_u8WriteString(Local_u8String, Local_u8StringSize);
				Copy_u8StringSize--;
			}

			LCD_u8WriteINT(Local_u8Move, 10, 0);
			LCD_u8WriteINT(Local_u8StringSize, 5, 0);
			LCD_u8WriteINT(Copy_u8StringSize, 1, 0);

			_delay_ms(500);
			LCD_voidClearLCD();

			if(Local_u8Move3 == 0 || Copy_u8StringSize == 0)
			{
				Local_u8Move3 = LCD_LINE_NB_OF_DIGITS;
				Copy_u8StringSize = Local_u8StringSize;
				break;
			}

		}
	}
}
