/*
 * LCD_program.c
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

/* Description	: Send a Command to LCD through the Data PORT
 * Input		: Command
 * Output		: Non
 */
void LCD_voidWriteCommand(u8 Copy_u8Command)
{
	/*Make Sure that the Enable PIN is LOW*/
	DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_LOW);

	/*Make Sure that the Register Select PIN is LOW as (RS -> LOW for Command) (RS -> HIGH for Data)*/
	DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_LOW);

	/*Make Sure that the Read Write PIN is LOW as (RW -> LOW for Write) (RW -> HIGH for Read)*/
	DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_LOW);

	/*Send the Command on Data Pins D0 -> D7*/
	DIO_u8SetPortValue(LCD_DATA_PORT, Copy_u8Command);

	/*Enable Sequence*/
	/*Make the Enable Pin HIGH*/
	DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_HIGH);

	/*Wait for 2 msec.*/
	_delay_ms(2);

	/*Re-Make Enable Pin as LOW*/
	DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_LOW);
}

/* Description	: Send a Data to LCD through the Data PORT
 * Input		: Data
 * Output		: Non
 */
void LCD_voidWriteData(u8 Copy_u8Data)
{
	/*Make Sure that the Enable PIN is LOW*/
	DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_LOW);

	/*Make Sure that the Register Select PIN is LOW as (RS -> LOW for Command) (RS -> HIGH for Data)*/
	DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_HIGH);

	/*Make Sure that the Read Write PIN is LOW as (RW -> LOW for Write) (RW -> HIGH for Read)*/
	DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_LOW);

	/*Send the Command on Data Pins D0 -> D7*/
	DIO_u8SetPortValue(LCD_DATA_PORT, Copy_u8Data);

	/*Enable Sequence*/
	/*Make the Enable Pin HIGH*/
	DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_HIGH);

	/*Wait for 2 msec.*/
	_delay_ms(2);

	/*Re-Make Enable Pin as LOW*/
	DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_LOW);
}

/* Description	: Initializing the LCD
 * Input		: Non
 * Output		: Non
 */
void LCD_voidInitialization(void)
{
	/*Wait after VDD rises to 4.5V*/
	_delay_ms(35);

	/*Function Set*/
	/*DB2	Font(F) -> 5*11	-> 1
	 *				-> 5*8  -> 0
	 *
	 *DB3	Number of Lines(N) -> 1 Line  -> 0
	 *						   -> 2 Lines -> 1
	 */
	LCD_voidWriteCommand(0b00111100);

	/*Wait to Process Function Set*/
	_delay_us(45);

	/*Display ON/OFF Control*/
	/*DB0	Cursor Blink(B) -> ON  -> 1
	 * 						-> OFF -> 0
	 *
	 * DB1	Cursor(C) -> ON  -> 1
	 * 				  -> OFF -> 0
	 *
	 * DB2 	Display(D) -> ON  -> 1
	 * 				   -> OFF -> 0
	 */
	LCD_voidWriteCommand(0b00001100);

	/*Delay to Process Display ON/OFF Control*/
	_delay_us(4);

	/*Clear LCD*/
	LCD_voidWriteCommand(0b00000001);

	/*Delay for Process Clearing LCD*/
	_delay_us(1600);
}

/* Description	: Clear LCD
 * Input		: Non
 * Output		: Non
 */
void LCD_voidClearLCD(void)
{
	/*Clear LCD*/
	LCD_voidWriteCommand(0b00000001);
}

/* Description	: Write A string to LCD
 * Input		: Array of Strings, Size of this Array
 * Output		: Error State -> 0 No Error
 * 								 1 Error
 */
u8 LCD_u8WriteString(u8 *Copy_u8String, u8 Copy_u8StrSize)
{
	/*Local Variables*/
	u8 Local_u8Error = 0, Local_u8LoopCtr = 0;

	/*Loop on the Array of the Strings and print it one by one*/
	for(Local_u8LoopCtr = 0; Local_u8LoopCtr < Copy_u8StrSize; Local_u8LoopCtr++)
	{
		LCD_voidWriteData(Copy_u8String[Local_u8LoopCtr]);
	}

	return Local_u8Error;
}

/* Description	: Put the Cursor to specific position and print in this position
 * Input		: X Position, Y Position
 * Output		: Error State -> 0 No Error
 * 								 1 Error
 */
u8 LCD_u8GoToXY(u8 Copy_u8XPos, u8 Copy_u8YPos)
{
	/*Local Variables*/
	u8 Local_u8Error = 0, Local_u8Address = 0;

	/*Check the the Inputs X, Y are in ranges*/
//	if(Copy_u8XPos > 15 || Copy_u8YPos > 1)
//	{
//		Local_u8Error = 1;
//	}
//
//	else
//	{
//		/*Mean you are in First Line in LCD*/
//		if(Copy_u8YPos == DIO_LOW)
//		{
//			/*Choose the X position in the First Line in LCD*/
//			/*AC Register is 7 Bits and the eight's bit will be Command = 0b1 and the 7 other Bits the Location*/
//			/*So to get the right Location we will add the First location
//			 * of the Memory and the X position we need and the Command for AC eight's Bit 0b1(128)
//			 */
//			Local_u8Address = DDRAM_LINE1_FIRST_LOCATION + Copy_u8XPos + AC_REG_COMMAND;
//		}
//
//		/*Mean you are in Second Line in LCD*/
//		else if(Copy_u8YPos == DIO_HIGH)
//		{
//			/*Choose the X position in the First Line in LCD*/
//			/*AC Register is 7 Bits and the eight's bit will be Command = 0b1 and the 7 other Bits the Location*/
//			/*So to get the right Location we will add the First location
//			 * of the Memory and the X position we need and the Command for AC eight's Bit 0b1(128)
//			 */
//			Local_u8Address = DDRAM_LINE2_FIRST_LOCATION + Copy_u8XPos + AC_REG_COMMAND;
//		}

		Local_u8Address = Copy_u8XPos + (Copy_u8YPos * DDRAM_LINE2_FIRST_LOCATION) +  AC_REG_COMMAND;

		/*Send the Command with the Needed Position*/
		LCD_voidWriteCommand(Local_u8Address);
//	}

	return Local_u8Error;
}

/* Description	: Store in a CGRAM Memory the Special Character
 * 					(TO PRINT THE SPECIAL CHAR USE LCD_u8WriteData with Input 0 -> 7as an ASCII code as in ASCII these positions
 * 					are for non printed characters and you have only 8 special Char from 0 -> 7
 * Input		: An Array of the Special Characters we have only 8 Positions
 * Output		: Error State -> 0 No Error
 * 								 1 Error
 */
u8 LCD_u8WriteSpecialChar(u8 *Copy_u8SpecialChar, u8 Copy_ArraySize)
{
	u8 Local_u8Error = 0, Local_u8LoopCtr = 0;

	if(Copy_ArraySize > MAX_NB_BITS_SPECIAL_CHAR)
	{
		Local_u8Error = 1;
	}

	else
	{
		/*Move the AC Register to Points to CGRAM command = 0b01 and the other 6 bits are the Position in CGRAM memory*/
		LCD_voidWriteCommand(0b01000000);

		/*Looping on the Array of the Special Char and Write it in CGRAM*/
		for(Local_u8LoopCtr = 0; Local_u8LoopCtr < MAX_NB_BITS_SPECIAL_CHAR; Local_u8LoopCtr++)
		{
			LCD_voidWriteData(Copy_u8SpecialChar[Local_u8LoopCtr]);
		}

		/*Back AC Register to points to the DDRAM*/
		LCD_u8GoToXY(0, 0);
	}
	return Local_u8Error;
}

/* Description	: Print an Integer on LCD u32 with Max number 4294967295
 * Input		: The Integer Number, X position, Y Position
 * Output		: Error State -> 0 No Error
 * 								 1 Error
 */
u8 LCD_u8WriteINT(u32 Copy_u32INT, u8 Copy_u8XPos, u8 Copy_u8YPos)
{
	/*Local Variables*/
	/* Local_u8LoopCtr: 	to Iterator for the loop
	 * Local_u8NOD: 		Number of Digits to make the positions of ones, tens, ...
	 * Local_u8CopyNOD: 	Copy of Number of Digits for the iteration in loop
	 * Local_u8Reminder: 	to save the Reminder (%) and check on it
	 */
	u8 Local_u8Error = 0, Local_u8LoopCtr = 0, Local_u8NOD = 0, Local_u8CopyNOD = 0, Local_u8Reminder = 0;
	u32 Local_u32Temp = 0;

	/*Checking on the Integer Number if it within the u32 range
	 * Check on the X position as we have 0 -> 15 position
	 * Check on the Y Position as we have 0 -> 1
	 */
	if(Copy_u32INT > MAX_U32_NB || Copy_u8XPos > 15 || Copy_u8YPos > 1)
	{
		Local_u8Error = 1;
	}

	/*if the Check is Okay with no problems*/
	else
	{
		/*Check if the Number is ZERO (0)*/
		if(Copy_u32INT == 0)
		{
			LCD_u8GoToXY((Copy_u8XPos), Copy_u8YPos);
			LCD_voidWriteData(48);
		}
		/*Putting the Integer Value in a temporary Variable to use in our calculation without losing it*/
		Local_u32Temp = Copy_u32INT;

		/*Loop to get the Number of Digits*/
		while(Local_u32Temp != 0)
		{
			/*Dividing the Integer number by 10 till we have a result of Division Zero*/
			Local_u32Temp /= 10;

			/*With each Division Add 1 to Number of Digits*/
			Local_u8NOD++;
		}

		/*Make a Copy from the Number of Digits to use it in looping*/
		Local_u8CopyNOD = Local_u8NOD;

		/*Re-Make a copy of the Integer Number*/
		Local_u32Temp = Copy_u32INT;

		/*Now we have the Integer number and the Number of Digits so we will loop and in each loop
		 * we will make a Reminder from ones, tens and so on till our reminder be Zero
		 * and loop to print this number with the position on LCD
		 */
		for(Local_u8LoopCtr = 0; Local_u8LoopCtr < Local_u8CopyNOD; Local_u8LoopCtr++)
		{
			/*Getting the Ones at first time and in second iteration tens and so on*/
			Local_u8Reminder = Local_u32Temp % 10;

			/*By Switch we will print the number by the ASCII Code*/
			switch(Local_u8Reminder)
			{
			/* Go to the Position and print the Value from ASCII Code
			 * and to get the Position as we have to print the Value from the right to the Left
			 * ((NOD - 1) + Position of X) by this every time in the loop NOD will decrease by one
			 * so Example 10 * 55 = i want to print from the left in Space 6 in the LCD
			 * (3 - 1) + 6 = 8 in space 8 will be 0 //ONES
			 * (2 - 1) + 6 = 7 in space 7 will be 5 //TENS
			 * (1 - 1) + 6 = 6 in Space 6 will be 5 //Hundreds
			 * and so on
			 */
			case 0:		//ZERO ASCII Code is 48
				LCD_u8GoToXY(((Local_u8NOD -= 1) + Copy_u8XPos), Copy_u8YPos);
				LCD_voidWriteData(48);
				break;

			case 1:		//ONE ASCII Code is 49
				LCD_u8GoToXY(((Local_u8NOD -= 1) + Copy_u8XPos), Copy_u8YPos);
				LCD_voidWriteData(49);
				break;

			case 2:		//TWO ASCII Code is 50
				LCD_u8GoToXY(((Local_u8NOD -= 1) + Copy_u8XPos), Copy_u8YPos);
				LCD_voidWriteData(50);
				break;

			case 3:		//THREE ASCII Code is 51
				LCD_u8GoToXY(((Local_u8NOD -= 1) + Copy_u8XPos), Copy_u8YPos);
				LCD_voidWriteData(51);
				break;

			case 4:		//FOUR ASCII Code is 52
				LCD_u8GoToXY(((Local_u8NOD -= 1) + Copy_u8XPos), Copy_u8YPos);
				LCD_voidWriteData(52);
				break;

			case 5:		//FIVE ASCII Code is 53
				LCD_u8GoToXY(((Local_u8NOD -= 1) + Copy_u8XPos), Copy_u8YPos);
				LCD_voidWriteData(53);
				break;

			case 6:		//SIX ASCII Code is 54
				LCD_u8GoToXY(((Local_u8NOD -= 1) + Copy_u8XPos), Copy_u8YPos);
				LCD_voidWriteData(54);
				break;

			case 7:		//SEVEN ASCII Code is 55
				LCD_u8GoToXY(((Local_u8NOD -= 1) + Copy_u8XPos), Copy_u8YPos);
				LCD_voidWriteData(55);
				break;

			case 8:		//EIGHT ASCII Code is 56
				LCD_u8GoToXY(((Local_u8NOD -= 1) + Copy_u8XPos), Copy_u8YPos);
				LCD_voidWriteData(56);
				break;

			case 9:		//NINE ASCII Code is 57
				LCD_u8GoToXY(((Local_u8NOD -= 1) + Copy_u8XPos), Copy_u8YPos);
				LCD_voidWriteData(57);
				break;

			default:
				Local_u8Error = 1;
				break;
			}

			/*Dividing The Temp by 10 to get the Tens, Hundreds ... in every Iteration*/
			Local_u32Temp /= 10;
		}
	}

	return Local_u8Error;
}

/* Description	: LCD Scrolling String to Left or to Right
 * Input		: The String, String size, Time in between, Left or Right, First Line or Second one
 * Output		: Error State -> 0 No Error
 * 								 1 Error
 */
u8 LCD_u8StringScroll(u8 *Copy_u8String, u8 Copy_u8StrSize, u16 Copy_u16Time, u8 Copy_u8RorL, u8 Copy_u8YPos)
{
	/*Local Variables*/
	u8 Local_u8Error = 0;
	u8 Local_u8Move = 0, Local_u8Move2 = 0, Local_u8Move3 = 0;
	u8 Copy_u8StringSize = Copy_u8StrSize;

	/* Check for String Size as the maximum is 20 Char
	 * Check for the Y Position 0 or 1
	 * Check for the Scrolling Direction Left Or Right
	 */
	if(Copy_u8StrSize > LCD_MAX_CHAR || Copy_u8YPos > 1 || Copy_u8RorL > 1)
	{
		Local_u8Error = 1;
	}

	else
	{
		/*This if Scrolling is to Right in Line 1*/
		if(Copy_u8RorL == LCD_SCROLL_TO_RIGHT && Copy_u8YPos == 0)
		{
			/*Make the Move2 = Over flow of the first lone - string size*/
			Local_u8Move2 = LCD_OV_LINE_1 - (Copy_u8StrSize);

			/*loop for the LCD MAximum Scrolling witch is 41*/
			for(Local_u8Move = 0; Local_u8Move <= LCD_MAX_SCROLL_LINE; Local_u8Move++)
			{
				/*if string bigger than 16*/
				if(Local_u8Move >= (LCD_LINE_NB_OF_DIGITS - Copy_u8StrSize))
				{
					/*first print the string in the shown position in 16*/
					LCD_u8GoToXY(Local_u8Move, Copy_u8YPos);
					LCD_u8WriteString(Copy_u8String, Copy_u8StrSize);

					/*print the string in un-shown position */
					LCD_u8GoToXY(Local_u8Move2, Copy_u8YPos);
					LCD_u8WriteString(Copy_u8String, Copy_u8StrSize);

//					LCD_u8WriteINT(Local_u8Move, 10, 1);
//					LCD_u8WriteINT(Copy_u8StrSize, 5, 1);

					/*delay with the given time*/
					_delay_ms(Copy_u16Time);

					/*Clear the LCD*/
					LCD_voidClearLCD();

					/*increment Move 2*/
					Local_u8Move2++;

					/*if Move 2 = 16 give it its initial value and break the loop*/
					if(Local_u8Move2 == LCD_OV_LINE_1)
					{
						Local_u8Move2 = LCD_OV_LINE_1 - (Copy_u8StrSize);
						break;
					}
				}

				/*else mean string < 16*/
				else
				{
					/*Print the string*/
					LCD_u8GoToXY(Local_u8Move, Copy_u8YPos);
					LCD_u8WriteString(Copy_u8String, Copy_u8StrSize);

//					LCD_u8WriteINT(Local_u8Move, 10, 1);
//					LCD_u8WriteINT(Copy_u8StrSize, 5, 1);

					/*Delay the given time*/
					_delay_ms(Copy_u16Time);

					/*Clear LCD*/
					LCD_voidClearLCD();
				}
			}
		}

		/*else mean scroll to left in Line 1*/
		else if(Copy_u8RorL == LCD_SCROLL_TO_LEFT && Copy_u8YPos == 0)
		{
			/*Move2 = over flow + string size + 1 to make space between the last and first char in string */
			Local_u8Move2 = LCD_OV_LINE_1 + (Copy_u8StrSize + 1);

			/*Move 3 = 16*/
			Local_u8Move3 = LCD_LINE_NB_OF_DIGITS;

			/*make the Move = 104 (Over Flow + 1 (First char on LCD)) and loop with --*/
			for(Local_u8Move = (LCD_OV_LINE_1 + 1); Local_u8Move <= Local_u8Move2; Local_u8Move--)
			{
				/*Print LCD with the Move as X position*/
				LCD_u8GoToXY(Local_u8Move, Copy_u8YPos);
				LCD_u8WriteString(Copy_u8String, Copy_u8StrSize);

				/*if String size less than 16*/
				if(Copy_u8StrSize < LCD_LINE_NB_OF_DIGITS)
				{
					/*print with move 3 as X position*/
					LCD_u8GoToXY(Local_u8Move3 , Copy_u8YPos);
					LCD_u8WriteString(Copy_u8String, Copy_u8StrSize);

					/*De-crement move 3*/
					Local_u8Move3--;
				}

				/*else mean string > 16*/
				else
				{
					/*print with the copy of string size as X position*/
					LCD_u8GoToXY(Copy_u8StringSize, Copy_u8YPos);
					LCD_u8WriteString(Copy_u8String, Copy_u8StrSize);

					/*de-crement the copy of the sting size*/
					Copy_u8StringSize--;
				}

//				LCD_u8WriteINT(Local_u8Move, 10, 1);
//				LCD_u8WriteINT(Copy_u8StrSize, 5, 1);
//				LCD_u8WriteINT(Copy_u8StringSize, 1, 1);

				/*Delay with the given time*/
				_delay_ms(Copy_u16Time);

				/*Clear LCD*/
				LCD_voidClearLCD();

				/*if Move 3 = 0 or Copy of string size = 0 re-intiate their value and break the loop*/
				if(Local_u8Move3 == 0 || Copy_u8StringSize == 0)
				{
					Local_u8Move3 = LCD_LINE_NB_OF_DIGITS;
					Copy_u8StringSize = Copy_u8StrSize;
					break;
				}
			}
		}

		/*This if Scrolling is to Right in Line 2*/
		else if(Copy_u8RorL == LCD_SCROLL_TO_RIGHT && Copy_u8YPos == 1)
		{
			/*Make the Move2 = Over flow of the second line - string size*/
			Local_u8Move2 = LCD_OV_LINE_2 - Copy_u8StrSize;

			/*loop for the LCD MAximum Scrolling witch is 41*/
			for(Local_u8Move = 0; Local_u8Move < LCD_MAX_SCROLL_LINE; Local_u8Move++)
			{
				/*if string bigger than 16*/
				if(Local_u8Move >= (LCD_LINE_NB_OF_DIGITS - Copy_u8StrSize))
				{
					/*first print the string in the shown position in 16*/
					LCD_u8GoToXY(Local_u8Move, Copy_u8YPos);
					LCD_u8WriteString(Copy_u8String, Copy_u8StrSize);

					/*print the string in un-shown position */
					LCD_u8GoToXY(Local_u8Move2, Copy_u8YPos);
					LCD_u8WriteString(Copy_u8String, Copy_u8StrSize);

//					LCD_u8WriteINT(Local_u8Move, 0, 0);
//					LCD_u8WriteINT(Local_u8Move2, 5, 0);
//					LCD_u8WriteINT(Copy_u8StrSize, 10, 0);

					/*delay with the given time*/
					_delay_ms(Copy_u16Time);

					/*Clear the LCD*/
					LCD_voidClearLCD();

					/*Increment Move 2*/
					Local_u8Move2++;

					/*if Move 2 = 323 the over flow of line two give it its initial value and break the loop*/
					if(Local_u8Move2 == LCD_OV_LINE_2)
					{
						Local_u8Move2 = LCD_OV_LINE_2 - Copy_u8StrSize;
						break;
					}
				}

				/*else mean string < 16*/
				else
				{
					/*Print the string*/
					LCD_u8GoToXY(Local_u8Move, Copy_u8YPos);
					LCD_u8WriteString(Copy_u8String, Copy_u8StrSize);

//					LCD_u8WriteINT(Local_u8Move, 0, 0);
//					LCD_u8WriteINT(Local_u8Move2, 5, 0);
//					LCD_u8WriteINT(Copy_u8StrSize, 10, 0);

					/*Delay the given time*/
					_delay_ms(Copy_u16Time);

					/*Clear LCD*/
					LCD_voidClearLCD();
				}
			}
		}

		/*This if Scrolling is to Left in Line 2*/
		else if(Copy_u8RorL == LCD_SCROLL_TO_LEFT && Copy_u8YPos == 1)
		{
			/*Move2 = over flow line 2 + string size + 1 to make space between the last and first char in string */
			Local_u8Move2 = LCD_OV_LINE_2 + (Copy_u8StrSize + 1);

			/*Move 3 = 16*/
			Local_u8Move3 = LCD_LINE_NB_OF_DIGITS;

			/*make the Move = 232 (Over Flow) and loop with --*/
			for(Local_u8Move = (LCD_OV_LINE_2); Local_u8Move <= Local_u8Move2; Local_u8Move--)
			{
				/*Print LCD with the Move as X position*/
				LCD_u8GoToXY(Local_u8Move, Copy_u8YPos);
				LCD_u8WriteString(Copy_u8String, Copy_u8StrSize);

				/*if String size less than 16*/
				if(Copy_u8StrSize < LCD_LINE_NB_OF_DIGITS)
				{
					/*print with move 3 as X position*/
					LCD_u8GoToXY(Local_u8Move3 , Copy_u8YPos);
					LCD_u8WriteString(Copy_u8String, Copy_u8StrSize);

					/*Decrement Move 3*/
					Local_u8Move3--;
				}

				/*else mean string > 16*/
				else
				{
					/*print with the copy of string size as X position*/
					LCD_u8GoToXY(Copy_u8StringSize, Copy_u8YPos);
					LCD_u8WriteString(Copy_u8String, Copy_u8StrSize);

					/*de-crement the copy of the sting size*/
					Copy_u8StringSize--;
				}

//				LCD_u8WriteINT(Local_u8Move, 10, 0);
//				LCD_u8WriteINT(Copy_u8StrSize, 5, 0);
//				LCD_u8WriteINT(Copy_u8StringSize, 1, 0);

				/*Delay the Given time*/
				_delay_ms(Copy_u16Time);

				/*Clear LCD*/
				LCD_voidClearLCD();

				/*if Move 3 = 0 or Copy of string size = 0 re-intiate their value and break the loop*/
				if(Local_u8Move3 == 0 || Copy_u8StringSize == 0)
				{
					Local_u8Move3 = LCD_LINE_NB_OF_DIGITS;
					Copy_u8StringSize = Copy_u8StrSize;
					break;
				}
			}
		}
	}

	/*return the Error*/
	return Local_u8Error;
}
