/*
 * main.c
 *
 *  Created on: Jul 3, 2020
 *      Author: my
 */

/*Standard Types*/
#include "STD_TYPES.h"

/*Module*/
#include "DIO_interface.h"
#include "KPD_interface.h"
#include "LCD_interface.h"

u8 main(void)
{
	u8 Local_u8KeyNB = 0, Local_u8OldKeyNB = 0;

	LCD_voidInitialization();

	KPD_u8Initialization();

	DIO_u8SetPinDirection(DIO_PORT_0, DIO_PIN_0, DIO_OUTPUT);


	while(1)
	{
		KPD_u8GetPressedKey(&Local_u8KeyNB);
		if(Local_u8KeyNB != Local_u8OldKeyNB)
		{
			LCD_voidClearLCD();
		}
		Local_u8OldKeyNB = Local_u8KeyNB;



//		switch(Local_u8KeyNB)
//		{
//			case '+':
//				LCD_u8GoToXY(0, 0);
//				LCD_voidWriteData('+');
//				DIO_u8SetPinValue(DIO_PORT_0, DIO_PIN_0, DIO_HIGH);
//				break;
//			case '-':
//				LCD_u8GoToXY(0, 0);
//				LCD_voidWriteData('-');
//				DIO_u8SetPinValue(DIO_PORT_0, DIO_PIN_0, DIO_LOW);
//				break;
//			case '/':
//				LCD_u8GoToXY(0, 0);
//				LCD_voidWriteData('/');
//				break;
//			case '*':
//				LCD_u8GoToXY(0, 0);
//				LCD_voidWriteData('*');
//				break;
//			case '=':
//				LCD_u8GoToXY(0, 0);
//				LCD_voidWriteData('=');
//				break;
//		}

		if(Local_u8KeyNB == '+')
		{
			LCD_u8GoToXY(0, 0);
			LCD_voidWriteData('+');
		}
		else if(Local_u8KeyNB == '-')
		{
			LCD_u8GoToXY(0, 0);
			LCD_voidWriteData('-');
		}
		else if(Local_u8KeyNB == '*')
		{
			LCD_u8GoToXY(0, 0);
			LCD_voidWriteData('*');
		}
		else if(Local_u8KeyNB == '/')
		{
			LCD_u8GoToXY(0, 0);
			LCD_voidWriteData('/');
		}
		else if(Local_u8KeyNB == '=')
		{
			LCD_u8GoToXY(0, 0);
			LCD_voidWriteData('=');
		}
		else
		{
				LCD_u8WriteINT(Local_u8KeyNB, 0, 0);
		}
	}

	return 0;
}

