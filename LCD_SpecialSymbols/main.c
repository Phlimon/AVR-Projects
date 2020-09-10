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
	u8 Local_u8SpecialSymb[] = {  0B00000,
								  0B11011,
								  0B11111,
								  0B01110,
								  0B00100,
								  0B00000,
								  0B00000,
								  0B00000,

								  0B01110,
								  0B01110,
								  0B10101,
								  0B01110,
								  0B00100,
								  0B00100,
								  0B01010,
								  0B10001}; //Max 20 Char
	u8 Local_u8ArraySize = sizeof(Local_u8SpecialSymb);

	DIO_u8SetPortDirection(LCD_DATA_PORT, DIO_MAX_PORT_VALUE);
	DIO_u8SetPinDirection(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_OUTPUT);
	DIO_u8SetPinDirection(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_OUTPUT);
	DIO_u8SetPinDirection(LCD_CONTROL_PORT, LCD_E_PIN, DIO_OUTPUT);

	LCD_voidInitialization();

	LCD_u8GoToXY(0,0);
	LCD_u8WriteSpecialChar(Local_u8SpecialSymb, Local_u8ArraySize);
	LCD_u8GoToXY(8, 0);
	LCD_voidWriteData(0);

	LCD_u8GoToXY(12, 1);
	LCD_voidWriteData(1);

	LCD_u8WriteINT(Local_u8ArraySize, 5, 1);
	while(1)
	{

	}
}
