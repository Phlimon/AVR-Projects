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
	DIO_u8SetPortDirection(LCD_DATA_PORT, DIO_MAX_PORT_VALUE);
	DIO_u8SetPinDirection(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_OUTPUT);
	DIO_u8SetPinDirection(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_OUTPUT);
	DIO_u8SetPinDirection(LCD_CONTROL_PORT, LCD_E_PIN, DIO_OUTPUT);

	LCD_voidInitialization();

//	while(1)
//	{
		LCD_voidWriteData('P');
		LCD_voidWriteData('H');
		LCD_voidWriteData('L');
		LCD_voidWriteData('I');
		LCD_voidWriteData('M');
		LCD_voidWriteData('O');
		LCD_voidWriteData('N');

		LCD_u8GoToXY(0, 1);

		LCD_u8WriteString("Phlimon Fahim", 13);
}
