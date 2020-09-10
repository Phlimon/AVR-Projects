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
	u8 Local_u8Iterator = 0;
	u8 Local_u8GO[] = "Game Over";
	u8 Local_u8FatlaDead[] = "Fatla Man is Dead ";
	u8 Local_u8GOSize = (sizeof(Local_u8GO) - 1);
	u8 Local_u8FatlaSize = (sizeof(Local_u8FatlaDead) - 1);
	u8 Local_u8String[] = {
							0b01110,	//[0]Fatla Killer
							0b01110,
							0b10100,
							0b01111,
							0b00100,
							0b00100,
							0b01110,
							0b10001,

							0b00000,	//[1]Pistol
							0b11111,
							0b11111,
							0b10100,
							0b11100,
							0b10000,
							0b10000,
							0b10000,

							0b10100,	//[2]First Bullet
							0b01011,
							0b10100,
							0b00000,
							0b00000,
							0b00000,
							0b00000,
							0b00000,

							0b00000,	//[3]Bullet
							0b00110,
							0b00000,
							0b00000,
							0b00000,
							0b00000,
							0b00000,
							0b00000,

							0b00000,	//[4]Low Half Fatla Man
							0b00000,
							0b10000,
							0b01000,
							0b01111,
							0b01000,
							0b10000,
							0b00000,

							0b00000,	//[5]High Half 2 Fatla Man
							0b00000,
							0b00100,
							0b01011,
							0b11111,
							0b01011,
							0b00100,
							0b00000,

							0b01110,	//[6]Fatla man
							0b01110,
							0b10101,
							0b01110,
							0b00100,
							0b00100,
							0b01110,
							0b10001
									};
	u8 Local_u8StringSize = (sizeof(Local_u8String) - 1);

	DIO_u8SetPortDirection(LCD_DATA_PORT, DIO_MAX_PORT_VALUE);
	DIO_u8SetPinDirection(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_OUTPUT);
	DIO_u8SetPinDirection(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_OUTPUT);
	DIO_u8SetPinDirection(LCD_CONTROL_PORT, LCD_E_PIN, DIO_OUTPUT);

	LCD_voidInitialization();

	LCD_u8WriteSpecialChar(Local_u8String, Local_u8StringSize);

	while(1)
	{
		LCD_u8GoToXY(0, 0);	//Fatla Killer
		LCD_voidWriteData(0);

		LCD_u8GoToXY(1 , 0);	//PISTOL
		LCD_voidWriteData(1);

		LCD_u8GoToXY(2, 0);		//First bullet
		LCD_voidWriteData(2);

		LCD_u8GoToXY(15, 0);	//Fatla Incieont
		LCD_voidWriteData(6);
		_delay_ms(300);

		for(Local_u8Iterator = 3; Local_u8Iterator < 14; Local_u8Iterator++)
		{
			LCD_voidClearLCD();



			LCD_u8GoToXY(0, 0);		//killer
			LCD_voidWriteData(0);

			LCD_u8GoToXY(1 , 0);	//pistol
			LCD_voidWriteData(1);

			LCD_u8GoToXY(15, 0);	//Fatla Incieont
			LCD_voidWriteData(6);

			LCD_u8GoToXY(Local_u8Iterator, 0);
			LCD_voidWriteData(3);

			_delay_ms(300);
		}

		if(Local_u8Iterator == 14)
		{
			LCD_voidClearLCD();

			LCD_u8GoToXY(0, 0); //killer
			LCD_voidWriteData(0);

			LCD_u8GoToXY(1 , 0);	//Pistol
			LCD_voidWriteData(1);

			LCD_u8GoToXY(Local_u8Iterator, 0);
			LCD_voidWriteData(2);

			LCD_u8GoToXY(15, 0);	//Fatla Incieont
			LCD_voidWriteData(6);

			_delay_ms(300);

			LCD_voidClearLCD();

			LCD_u8GoToXY(0, 0); //killer
			LCD_voidWriteData(0);

			LCD_u8GoToXY(1 , 0);	//Pistol
			LCD_voidWriteData(1);

			LCD_u8GoToXY(14, 0);
			LCD_voidWriteData(4);

			LCD_u8GoToXY(15, 0);
			LCD_voidWriteData(5);

			_delay_ms(300);

			LCD_voidClearLCD();
		}
		LCD_u8StringScroll(Local_u8FatlaDead, Local_u8FatlaSize, 300, LCD_SCROLL_TO_LEFT, 0);
		LCD_u8StringScroll(Local_u8GO, Local_u8GOSize, 300, LCD_SCROLL_TO_RIGHT, 1);
	}
}
