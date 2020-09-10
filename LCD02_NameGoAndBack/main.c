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
	u8 Local_u8Move = 0;
	u8 Local_u8String[] = "Phlimon";
	u8 Local_u8StringSize = (sizeof(Local_u8String) - 1);

	DIO_u8SetPortDirection(LCD_DATA_PORT, DIO_MAX_PORT_VALUE);
	DIO_u8SetPinDirection(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_OUTPUT);
	DIO_u8SetPinDirection(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_OUTPUT);
	DIO_u8SetPinDirection(LCD_CONTROL_PORT, LCD_E_PIN, DIO_OUTPUT);

	LCD_voidInitialization();

	LCD_u8GoToXY(0, 1);

	LCD_u8WriteString(Local_u8String, sizeof(Local_u8String));

//	Local_u8RestSize

	while(1)
	{
		for(Local_u8Move = 0; Local_u8Move <= LCD_LINE_NB_OF_DIGITS - Local_u8StringSize; Local_u8Move++)
		{
			LCD_u8GoToXY(Local_u8Move, 0);

			LCD_u8WriteString(Local_u8String, Local_u8StringSize);

			_delay_ms(300);

			LCD_voidClearLCD();
		}

		for(Local_u8Move = LCD_LINE_NB_OF_DIGITS - Local_u8StringSize; Local_u8Move >= 0; Local_u8Move--)
		{
			LCD_u8GoToXY(Local_u8Move, 0);

			LCD_u8WriteString(Local_u8String, Local_u8StringSize);

			_delay_ms(300);

			LCD_voidClearLCD();
			if(Local_u8Move == 0)
			{
				break;
			}
		}
	}
}
