/*
 * main.c
 *
 *  Created on: Jun 30, 2020
 *      Author: Phlimon.fahim
 *      Need an Update to accept a Zero Number and to Accept the floats and Accept the Negative Number to make an operation on it
 */

/*Standard Types*/
#include "STD_TYPES.h"

/*Module*/
#include "DIO_interface.h"
#include "KPD_interface.h"
#include "LCD_interface.h"
#include "APP_interface.h"

void main(void)
{
	/*Local Variables*/
	u8 Local_u8KeyPressed = 0, Local_u8KeyNB = 0, Local_u8FONOD = 0/*First Operand Number of Digits*/, Local_u8Sign = 0, Local_u8SONOD = 0, Local_u8Equal = 0;
	u32 Local_u32FO = 0, Local_u32SO = 0, Local_u32Result = 0;

	/*Initializing The LCD*/
	LCD_voidInitialization();

	/*Initializing The KPD*/
	KPD_u8Initialization();

	while(1)
	{
		/*Check if there is any key pressed*/
		Local_u8KeyPressed = KPD_u8GetPressedKey(&Local_u8KeyNB);

		/*IF kEY PRESSED Equal 1 means there is a key have pressed*/
		if(Local_u8KeyPressed == 1)
		{
			/*if the key between numbers 0 - 9 and the local sign equal 0 means you are in first operand*/
			if(Local_u8KeyNB <= 9 && Local_u8Sign == 0)
			{
				/*take the value multiply with 10 and then take the next value add to it*/
				Local_u32FO = Local_u32FO * 10 + Local_u8KeyNB;

				/*then clear the LCD*/
				LCD_voidClearLCD();

				/*and put the whole new value at once*/
				LCD_u8WriteINT(Local_u32FO, 0, 0);
			}

			/*if it between 0 - 9 and local sign not equal ZERO and there is no equal sign means you are in second operand*/
			else if(Local_u8KeyNB <= 9 && Local_u8Sign != 0)
			{
				/*take the value multiply with 10 and then take the next value add to it*/
				Local_u32SO = Local_u32SO * 10 + Local_u8KeyNB;

				/*then clear the LCD*/
				LCD_voidClearLCD();

				/*put at first the first operand*/
				LCD_u8WriteINT(Local_u32FO, 0, 0);

				/*then put the sign*/
				LCD_u8GoToXY(Local_u8FONOD, 0);
				LCD_voidWriteData(Local_u8Sign);

				/*then put the second operand*/
				LCD_u8WriteINT(Local_u32SO, Local_u8FONOD + 1, 0);
			}

			/*To Take the Number Of Digits both first and second operands*/
			Local_u8FONOD = CAL_u8OperandNOD(Local_u32FO);
			Local_u8SONOD = CAL_u8OperandNOD(Local_u32SO);

			/*The Key Pressed equal "/" and the NOD of second operand = 0 means still there is no second operand
			 * and the NOD of first operand not equal to zero means there is first operand
			 * */
			if(Local_u8KeyNB == '/' && Local_u8SONOD == 0 && Local_u8FONOD != 0)
			{
				/*first clear LCD*/
				LCD_voidClearLCD();

				/*Print the first operand*/
				LCD_u8WriteINT(Local_u32FO, 0, 0);

				/*print the second operand*/
				LCD_u8GoToXY(Local_u8FONOD, 0);
				LCD_voidWriteData('/');

				/*assign '/' to sign variable*/
				Local_u8Sign = '/';
			}

			/*The Key Pressed equal "*" and the NOD of second operand = 0 means still there is no second operand
			 * and the NOD of first operand not equal to zero means there is first operand
			 * */
			else if(Local_u8KeyNB == '*' && Local_u8SONOD == 0 && Local_u8FONOD != 0)
			{
				/*first clear LCD*/
				LCD_voidClearLCD();

				/*Print the first operand*/
				LCD_u8WriteINT(Local_u32FO, 0, 0);

				/*print the second operand*/
				LCD_u8GoToXY(Local_u8FONOD, 0);
				LCD_voidWriteData('*');

				/*assign '*' to sign variable*/
				Local_u8Sign = '*';
			}

			/*The Key Pressed equal "+" and the NOD of second operand = 0 means still there is no second operand
			 * and the NOD of first operand not equal to zero means there is first operand
			 * */
			else if(Local_u8KeyNB == '+' && Local_u8SONOD == 0 && Local_u8FONOD != 0)
			{
				/*first clear LCD*/
				LCD_voidClearLCD();

				/*Print the first operand*/
				LCD_u8WriteINT(Local_u32FO, 0, 0);

				/*print the second operand*/
				LCD_u8GoToXY(Local_u8FONOD, 0);
				LCD_voidWriteData('+');

				/*assign '*' to sign variable*/
				Local_u8Sign = '+';
			}

			/*The Key Pressed equal "-" and the NOD of second operand = 0 means still there is no second operand
			 * and the NOD of first operand not equal to zero means there is first operand
			 * */
			else if(Local_u8KeyNB == '-' && Local_u8SONOD == 0 && Local_u8FONOD != 0)
			{
				/*first clear LCD*/
				LCD_voidClearLCD();

				/*Print the first operand*/
				LCD_u8WriteINT(Local_u32FO, 0, 0);

				/*print the second operand*/
				LCD_u8GoToXY(Local_u8FONOD, 0);
				LCD_voidWriteData('-');

				/*assign '*' to sign variable*/
				Local_u8Sign = '-';
			}

			/*if the 13 means Clear all calculator data*/
			if(Local_u8KeyNB == 13)
			{
				/*Clear LCD*/
				LCD_voidClearLCD();

				/*Clear First Operand Value*/
				Local_u32FO = 0;

				/*Clear Second Operand Value*/
				Local_u32SO = 0;

				/*Clear First Operand NOD Value*/
				Local_u8FONOD = 0;

				/*Clear Second Operand NOD Value*/
				Local_u8SONOD = 0;

				/*Clear the Sign Value*/
				Local_u8Sign = 0;

				/*Clear The Equal Value*/
				Local_u8Equal = 0;

				/*Clear the Result Value*/
				Local_u32Result = 0;
			}

			/*If Key Pressed Equal '=' and NOD of second Operand Not Equal zero*/
			if(Local_u8KeyNB == '=' && Local_u8SONOD != 0)
			{
				/*Set the Equal Flag*/
				Local_u8Equal = 1;

				/*Clear LCD*/
				LCD_voidClearLCD();

				/*Print first operand*/
				LCD_u8WriteINT(Local_u32FO, 0, 0);

				/*Print the Sign*/
				LCD_u8GoToXY(Local_u8FONOD, 0);
				LCD_voidWriteData(Local_u8Sign);

				/*Print Second Operand*/
				LCD_u8WriteINT(Local_u32SO, Local_u8FONOD + 1, 0);

				/*Print Equal Symbol '=;*/
				LCD_u8GoToXY((Local_u8FONOD + Local_u8SONOD + 1), 0);
				LCD_voidWriteData('=');

				/*Switch on the Sign Value to make the operation*/
				switch(Local_u8Sign)
				{
				case '/':
					Local_u32Result = Local_u32FO / Local_u32SO;
					LCD_u8WriteINT(Local_u32Result, 0, 1);
					break;

				case '*':
					Local_u32Result = Local_u32FO * Local_u32SO;
					LCD_u8WriteINT(Local_u32Result, 0, 1);
					break;

				case '-':
					/*if second operand Greater than first operand means the operation will give a minus value*/
					if(Local_u32SO > Local_u32FO)
					{
						/*make the operation */
						Local_u32Result = Local_u32SO - Local_u32FO;

						/*put the minus symbol*/
						LCD_u8GoToXY(0, 1);
						LCD_voidWriteData(Local_u8Sign);

						/*put the result*/
						LCD_u8WriteINT(Local_u32Result, 1, 1);
					}
					else
					{
						Local_u32Result = Local_u32FO - Local_u32SO;
						LCD_u8WriteINT(Local_u32Result, 0, 1);
					}
					break;

				case '+':
					Local_u32Result = Local_u32FO + Local_u32SO;
					LCD_u8WriteINT(Local_u32Result, 0, 1);
					break;
				}

				/*Make the first operand equal the first operand if you want to make an operation on the result*/
				Local_u32FO = Local_u32Result;

				/*Make the second operand equal to zero*/
				Local_u32SO = 0;

				/*second operand NOD equal to zero*/
				Local_u8SONOD = 0;

				/*clear the equal flag*/
				Local_u8Equal = 0;
			}
		}
	}
}
