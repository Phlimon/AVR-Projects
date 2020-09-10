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
	u8 Local_u8Move = 0, Local_u8Move2 = 0;
	u8 Local_u8String[] = "Phlimon Fahim Lawand"; //Max 20 Char
	u8 Local_u8StringSize = (sizeof(Local_u8String) - 1);

	DIO_u8SetPortDirection(LCD_DATA_PORT, DIO_MAX_PORT_VALUE);
	DIO_u8SetPinDirection(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_OUTPUT);
	DIO_u8SetPinDirection(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_OUTPUT);
	DIO_u8SetPinDirection(LCD_CONTROL_PORT, LCD_E_PIN, DIO_OUTPUT);

	LCD_voidInitialization();

	while(1)
	{
		Local_u8Move2 = LCD_OV_LINE_1 - (Local_u8StringSize);

		for(Local_u8Move = 0; Local_u8Move <= LCD_MAX_SCROLL_LINE; Local_u8Move++)
		{
			if(Local_u8Move >= (LCD_LINE_NB_OF_DIGITS - Local_u8StringSize))
			{
				LCD_u8GoToXY(Local_u8Move, 0);
				LCD_u8WriteString(Local_u8String, Local_u8StringSize);

				LCD_u8GoToXY(Local_u8Move2, 0);
				LCD_u8WriteString(Local_u8String, Local_u8StringSize);

				LCD_u8WriteINT(Local_u8Move, 10, 1);
				LCD_u8WriteINT(Local_u8StringSize, 5, 1);

				_delay_ms(500);
				LCD_voidClearLCD();
				Local_u8Move2++;

				if(Local_u8Move2 == LCD_OV_LINE_1)
				{
					Local_u8Move2 = LCD_OV_LINE_1 - (Local_u8StringSize);
					break;
				}
			}
			else
			{
				LCD_u8GoToXY(Local_u8Move, 0);
				LCD_u8WriteString(Local_u8String, Local_u8StringSize);

				LCD_u8WriteINT(Local_u8Move, 10, 1);
				LCD_u8WriteINT(Local_u8StringSize, 5, 1);

				_delay_ms(500);
				LCD_voidClearLCD();
			}
		}
	}
}
