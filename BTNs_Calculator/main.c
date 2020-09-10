/*
 * main.c
 *
 *  Created on: May 29, 2020
 *      Author: my
 */

/*Standard Types*/
#include "STD_TYPES.h"
#include "AVR_DIO_REG.h"
/*Module*/
#include <util/delay.h>
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "BTN_interface.h"

void main(void)
{
	/*Local Variables UP, Down, Enter Buttons and First, Second Operands and Sign and Result and a Counter*/
	u8 Local_u8BtnUP = 0, Local_u8BTNDown = 0, Local_u8BTNEnter = 0, Local_u8FirstNB = 0, Local_u8Sign = 0, Local_u8SeconedNB = 0;
	u8 Local_u8Result = 0, Local_u8EnterCounter = 0;

	u8 Local_u8IndecatorArrow[] = {
		0b11111,
		0b11011,
		0b10001,
		0b01010,
		0b11011,
		0b11011,
		0b11011,
		0b11111
	};

	u8 Local_u8SizeIndecatorArrow = sizeof(Local_u8IndecatorArrow);

	/*Initialize the LCD*/
	LCD_voidInitialization();

	LCD_u8GoToXY(0,0);
	LCD_u8WriteSpecialChar(Local_u8IndecatorArrow, Local_u8SizeIndecatorArrow);

	/*Initialize Buttons Needed*/
	BTN_u8Initialization(DIO_PORT_3, DIO_PIN_0);
	BTN_u8Initialization(DIO_PORT_3, DIO_PIN_1);
	BTN_u8Initialization(DIO_PORT_3, DIO_PIN_2);

	while(1)
	{
		/*Check if the Button Pressed or not*/
		BTN_u8Pressed(DIO_PORT_3, DIO_PIN_0, &Local_u8BtnUP);
		BTN_u8Pressed(DIO_PORT_3, DIO_PIN_1, &Local_u8BTNDown);
		BTN_u8Pressed(DIO_PORT_3, DIO_PIN_2, &Local_u8BTNEnter);

		/*Print "=" Sign*/
		LCD_u8GoToXY(3, 0);
		LCD_voidWriteData(61);

		/*If Enter Button Pressed*/
		if(Local_u8BTNEnter == DIO_LOW)
		{
			/*increase the counter*/
			Local_u8EnterCounter++;

			/*and as i have only four signs if counter reached Four*/
			if(Local_u8EnterCounter == 4)
			{
				/*Reset the Enter Counter to ZERO*/
				Local_u8EnterCounter = 0;

				/*Re-initiate the Operands*/
				Local_u8FirstNB = 0;
				Local_u8SeconedNB = 0;

				/*Clear LCD*/
				LCD_voidClearLCD();

				/*Re-initiate the button state to one as it Not presses*/
				Local_u8BTNEnter = 1;
			}
		}

		/*if Enter Button never been pressed means you are in first operand*/
		if(Local_u8EnterCounter == 0)
		{
			/*Print the Arrow in the Position*/
			LCD_u8GoToXY(4, 1);
			LCD_voidWriteData(32);
			LCD_u8GoToXY(0, 1);
			LCD_voidWriteData(0);

			/*Check for UP button if Pressed*/
			if(Local_u8BtnUP == DIO_LOW)
			{
				/*increment the counter*/
				Local_u8FirstNB++;

				/*if counter = 10 make it = 0 clear LCD and make btn initial value ONE not pressed*/
				if(Local_u8FirstNB == 10)
				{
					Local_u8FirstNB = 0;
					LCD_voidClearLCD();
					Local_u8BtnUP = 1;
				}
			}

			/*else if Down Button is pressed*/
			else if(Local_u8BTNDown == DIO_LOW)
			{
				/*De-crease the first opperand*/
				Local_u8FirstNB--;

				/*if it less than ZERO*/
				if(Local_u8FirstNB == 255)
				{
					/*re-initiate the value to ten*/
					Local_u8FirstNB = 9;

					/*Clear LCD*/
					LCD_voidClearLCD();

					/*re-initiate the value to one as not pressed*/
					Local_u8BTNDown = 1;
				}
			}
		}

		/*if Enter Button Pressed for the Second Time means you are in second operand*/
		if(Local_u8EnterCounter == 2)
		{
			/*Print the Arrow in the Position*/
			LCD_u8GoToXY(1, 1);
			LCD_voidWriteData(32);
			LCD_u8GoToXY(2, 1);
			LCD_voidWriteData(0);

			/*else if UP Button is pressed*/
			if(Local_u8BtnUP == DIO_LOW)
			{
				/*increment the counter*/
				Local_u8SeconedNB++;

				/*if counter = 10 make it = 0 clear LCD and make btn initial value ONE not pressed*/
				if(Local_u8FirstNB == 10)
				{
					Local_u8SeconedNB = 0;
					LCD_voidClearLCD();
					Local_u8BtnUP = 1;
				}
			}

			/*else if Down Button is pressed*/
			else if(Local_u8BTNDown == DIO_LOW)
			{
				/*Decrease the second operand value*/
				Local_u8SeconedNB--;

				/*if it less than zero re-initiate the value to nine*/
				if(Local_u8SeconedNB == 255)
				{
					Local_u8SeconedNB = 9;

					/*Clear LCD*/
					LCD_voidClearLCD();

					/*re-initiate the value to one as not pressed*/
					Local_u8BTNDown = 1;
				}
			}
		}

		/*if Enter Button Pressed for the First Time means you are in sign choosing*/
		else if(Local_u8EnterCounter == 1)
		{
			/*Print the Arrow in the Position*/
			LCD_u8GoToXY(0, 1);
			LCD_voidWriteData(32);
			LCD_u8GoToXY(1, 1);
			LCD_voidWriteData(0);

			if(Local_u8BtnUP == DIO_LOW)
			{
				/*increment the counter*/
				Local_u8Sign++;

				/*if counter = 4 make it = 0 clear LCD and make btn initial value ONE not pressed*/
				if(Local_u8Sign == 4)
				{
					Local_u8Sign = 0;
					LCD_voidClearLCD();
					Local_u8BtnUP = 1;
				}
			}
			else if(Local_u8BTNDown == DIO_LOW)
			{
				Local_u8Sign--;

				if(Local_u8Sign == 255)
				{
					Local_u8Sign = 3;
					LCD_voidClearLCD();
					Local_u8BTNDown = 1;
				}
			}
		}

		/*Print on LCD first Operand*/
		LCD_u8WriteINT(Local_u8FirstNB, 0, 0);

		/*LCD print the Sign by switch case on sign variable value*/
		switch(Local_u8Sign)
		{
		case 0:		//Multiplication
			LCD_u8GoToXY(1, 0);
			LCD_voidWriteData(42);
			Local_u8Result = Local_u8FirstNB * Local_u8SeconedNB;
			break;
		case 1:		//Summation
			LCD_u8GoToXY(1, 0);
			LCD_voidWriteData(43);
			Local_u8Result = Local_u8FirstNB + Local_u8SeconedNB;
			break;
		case 2:		//Subtraction
			LCD_u8GoToXY(1, 0);
			LCD_voidWriteData(47);
			Local_u8Result = Local_u8FirstNB / Local_u8SeconedNB;
			break;
		case 3:		//Dividing
			LCD_u8GoToXY(1, 0);
			LCD_voidWriteData(45);
			Local_u8Result = Local_u8FirstNB - Local_u8SeconedNB;
			break;
		}

		/*Print the Second Operand*/
		LCD_u8WriteINT(Local_u8SeconedNB, 2, 0);

		/*Print the sign equal "="*/
		LCD_u8GoToXY(3, 0);
		LCD_voidWriteCommand(61);

		/*if Enter Button pressed for the third time print the Result*/
		if(Local_u8EnterCounter == 3)
		{
			/*Print the Arrow in the Position*/
			LCD_u8GoToXY(2, 1);
			LCD_voidWriteData(32);
			LCD_u8GoToXY(4, 1);
			LCD_voidWriteData(0);

			/*Print the Result*/
			LCD_u8WriteINT(Local_u8Result, 4, 0);
		}
	}
}
