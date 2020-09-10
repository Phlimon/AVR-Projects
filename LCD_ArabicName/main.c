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
	u8 Local_u8SpecialSymb[] = {
								0b00010,
								0b00000,
								0b00111,
								0b00101,
								0b00111,
								0b00001,
								0b11111,
								0b00000,

								0b00000,
								0b00100,
								0b00100,
								0b00100,
								0b00100,
								0b00100,
								0b11111,
								0b00000,

								0b00000,
								0b00000,
								0b00000,
								0b00000,
								0b00100,
								0b00100,
								0b11111,
								0b01010,

								0b00000,
								0b00000,
								0b00000,
								0b00000,
								0b00000,
								0b01110,
								0b11011,
								0b01110,

								0b00000,
								0b00000,
								0b00000,
								0b11100,
								0b10100,
								0b11100,
								0b00111,
								0b11100,

								0b00000,
								0b00000,
								0b00000,
								0b00000,
								0b00100,
								0b10001,
								0b10001,
								0b11111,

								0B000000,
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

	LCD_u8WriteSpecialChar(Local_u8SpecialSymb, Local_u8ArraySize);


	LCD_u8GoToXY(15, 0);
	LCD_voidWriteData(0);

	LCD_u8GoToXY(14, 0);
	LCD_voidWriteData(1);

	LCD_u8GoToXY(13, 0);
	LCD_voidWriteData(2);

	LCD_u8GoToXY(12, 0);
	LCD_voidWriteData(3);

	LCD_u8GoToXY(11, 0);
	LCD_voidWriteData(4);

	LCD_u8GoToXY(10, 0);
	LCD_voidWriteData(5);

	LCD_u8GoToXY(9, 0);
	LCD_voidWriteData(6);

	LCD_u8GoToXY(8, 0);
	LCD_voidWriteData(7);

	LCD_u8WriteINT(Local_u8ArraySize, 5, 1);
	while(1)
	{

	}
}
