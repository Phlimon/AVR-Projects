/*
 * 7SEG_ptogram.c
 *
 *  Created on    : May 25, 2020
 *  Program Driver: 7 Segment Driver
 *      Author    : my
 */

/*Standard Types*/
#include "STD_TYPES.h"

/*Module*/
#include "DIO_interface.h"
#include "SEG_interface.h"

/*Array for the All Symbols, Numbers and Characters 7 Segment can perform*/
u8 static u8Symbols[28] = {0b00111111,		//0
						   0b00000110, 		//1
						   0b01011011, 		//2
						   0b01001111, 		//3
						   0b01100110, 		//4
						   0b01101101, 		//5
						   0b01111101, 		//6
						   0b00000111, 		//7
						   0b01111111, 		//8
						   0b01101111,		//9
						   0b01110111,		//A		10
						   0b01111111,		//B		11
						   0b00111001,		//C		12
						   0b00111111,		//D		13
						   0b01111001,		//E		14
						   0b01110001,		//F		15
						   0b00111101,		//G		16
						   0b01110110,		//H		17
						   0b00110000,		//I		18
						   0b00001110,		//j		19
						   0b00111000,		//L		20
						   0b00111111,		//O		21
						   0b01110011,		//P		22
						   0b01100111,		//q		23
						   0b01101101,		//S		24
						   0b01111000,		//t		25
						   0b00111110,		//U		26
						   0b01101110}; 	//y		27

/* Description	: To perform a single Symbol, Number or Character for Single Display
 * Input		: Symbol, Number or Character E.X. (1), ('A') ...
 * Output		: Error State -> 0 No Error
 * 								 1 Error
 */
u8 _7SEG_u8SingleDigit1(u8 Copy_u8Symbol)
{
	/*Local Variables*/
	u8 Local_u8Error = 0, Local_u8Iterator = 0;

	/*Check if the Received Value to perform is less than 255 the Byte*/
	if(Copy_u8Symbol <= DIO_MAX_PORT_VALUE)
	{
		/*Make the 7SEG PORT an OUTPUT*/
		DIO_u8SetPortDirection(_7SEG1_PORT, DIO_MAX_PORT_VALUE);

		/*check in the array if the value (Number 0 -> 9) exist put it as an OUTPUT VALUE on the 7SEG PORT*/
		for(Local_u8Iterator = 0; Local_u8Iterator <= 28; Local_u8Iterator++)
		{
			if(Local_u8Iterator == Copy_u8Symbol)
			{
				Local_u8Error = DIO_u8SetPortValue(_7SEG1_PORT, u8Symbols[Local_u8Iterator]);
				break;
			}

			/*if Value > 9 that is mean it is a Character or Symbol*/
			if(Local_u8Iterator > 9)
			{
				switch(Copy_u8Symbol)
				{
				case 65:	//A
					Local_u8Error = DIO_u8SetPortValue(_7SEG1_PORT, u8Symbols[10]);
					break;

				case 66:	//B
					Local_u8Error = DIO_u8SetPortValue(_7SEG1_PORT, u8Symbols[11]);
					break;

				case 67:	//C
					Local_u8Error = DIO_u8SetPortValue(_7SEG1_PORT, u8Symbols[12]);
					break;

				case 68:	//D
					Local_u8Error = DIO_u8SetPortValue(_7SEG1_PORT, u8Symbols[13]);
					break;

				case 69:	//E
					Local_u8Error = DIO_u8SetPortValue(_7SEG1_PORT, u8Symbols[14]);
					break;

				case 70:	//F
					Local_u8Error = DIO_u8SetPortValue(_7SEG1_PORT, u8Symbols[15]);
					break;

				case 71:	//G
					Local_u8Error = DIO_u8SetPortValue(_7SEG1_PORT, u8Symbols[16]);
					break;

				case 72:	//H
					Local_u8Error = DIO_u8SetPortValue(_7SEG1_PORT, u8Symbols[17]);
					break;

				case 73:	//I
					Local_u8Error = DIO_u8SetPortValue(_7SEG1_PORT, u8Symbols[18]);
					break;

				case 74:	//J
					Local_u8Error = DIO_u8SetPortValue(_7SEG1_PORT, u8Symbols[19]);
					break;

				case 76:	//L
					Local_u8Error = DIO_u8SetPortValue(_7SEG1_PORT, u8Symbols[20]);
					break;

				case 79:	//O
					Local_u8Error = DIO_u8SetPortValue(_7SEG1_PORT, u8Symbols[21]);
					break;

				case 80:	//P
					Local_u8Error = DIO_u8SetPortValue(_7SEG1_PORT, u8Symbols[22]);
					break;

				case 113:	//q
					Local_u8Error = DIO_u8SetPortValue(_7SEG1_PORT, u8Symbols[23]);
					break;

				case 83:	//S
					Local_u8Error = DIO_u8SetPortValue(_7SEG1_PORT, u8Symbols[24]);
					break;

				case 116:	//t
					Local_u8Error = DIO_u8SetPortValue(_7SEG1_PORT, u8Symbols[25]);
					break;

				case 85:	//U
					Local_u8Error = DIO_u8SetPortValue(_7SEG1_PORT, u8Symbols[26]);
					break;

				case 121:	//y
					Local_u8Error = DIO_u8SetPortValue(_7SEG1_PORT, u8Symbols[27]);
					break;

				default:	//7SEG Can not Perform so it make an Error
					Local_u8Error = 1;
					break;
				}
			}
		}
	}

	/*if Iteration Reach 29 without found a match value will make an Error*/
	if(Local_u8Iterator == 29)
	{
		Local_u8Error = 1;
	}
	return Local_u8Error;
}

/* Description	: To perform a single Symbol, Number or Character for another Single Display
 * Input		: Symbol, Number or Character E.X. (1), ('A') ...
 * Output		: Error State -> 0 No Error
 * 								 1 Error
 */
u8 _7SEG_u8SingleDigit2(u8 Copy_u8Symbol)
{
	/*Local Variables*/
	u8 Local_u8Error = 0, Local_u8Iterator = 0;

	/*Check if the Received Value to perform is less than 255 the Byte*/
	if(Copy_u8Symbol <= DIO_MAX_PORT_VALUE)
	{
		/*Make the 7SEG PORT an OUTPUT*/
		DIO_u8SetPortDirection(_7SEG2_PORT, DIO_MAX_PORT_VALUE);

		/*check in the array if the value (Number 0 -> 9) exist put it as an OUTPUT VALUE on the 7SEG PORT*/
		for(Local_u8Iterator = 0; Local_u8Iterator <= 28; Local_u8Iterator++)
		{
			if(Local_u8Iterator == Copy_u8Symbol)
			{
				Local_u8Error = DIO_u8SetPortValue(_7SEG2_PORT, u8Symbols[Local_u8Iterator]);
				break;
			}

			/*if Value > 9 that is mean it is a Character or Symbol*/
			if(Local_u8Iterator > 9)
			{
				switch(Copy_u8Symbol)
				{
				case 65:	//A
					Local_u8Error = DIO_u8SetPortValue(_7SEG2_PORT, u8Symbols[10]);
					break;

				case 66:	//B
					Local_u8Error = DIO_u8SetPortValue(_7SEG2_PORT, u8Symbols[11]);
					break;

				case 67:	//C
					Local_u8Error = DIO_u8SetPortValue(_7SEG2_PORT, u8Symbols[12]);
					break;

				case 68:	//D
					Local_u8Error = DIO_u8SetPortValue(_7SEG2_PORT, u8Symbols[13]);
					break;

				case 69:	//E
					Local_u8Error = DIO_u8SetPortValue(_7SEG2_PORT, u8Symbols[14]);
					break;

				case 70:	//F
					Local_u8Error = DIO_u8SetPortValue(_7SEG2_PORT, u8Symbols[15]);
					break;

				case 71:	//G
					Local_u8Error = DIO_u8SetPortValue(_7SEG2_PORT, u8Symbols[16]);
					break;

				case 72:	//H
					Local_u8Error = DIO_u8SetPortValue(_7SEG2_PORT, u8Symbols[17]);
					break;

				case 73:	//I
					Local_u8Error = DIO_u8SetPortValue(_7SEG2_PORT, u8Symbols[18]);
					break;

				case 74:	//J
					Local_u8Error = DIO_u8SetPortValue(_7SEG2_PORT, u8Symbols[19]);
					break;

				case 76:	//L
					Local_u8Error = DIO_u8SetPortValue(_7SEG2_PORT, u8Symbols[20]);
					break;

				case 79:	//O
					Local_u8Error = DIO_u8SetPortValue(_7SEG2_PORT, u8Symbols[21]);
					break;

				case 80:	//P
					Local_u8Error = DIO_u8SetPortValue(_7SEG2_PORT, u8Symbols[22]);
					break;

				case 113:	//q
					Local_u8Error = DIO_u8SetPortValue(_7SEG2_PORT, u8Symbols[23]);
					break;

				case 83:	//S
					Local_u8Error = DIO_u8SetPortValue(_7SEG2_PORT, u8Symbols[24]);
					break;

				case 116:	//t
					Local_u8Error = DIO_u8SetPortValue(_7SEG2_PORT, u8Symbols[25]);
					break;

				case 85:	//U
					Local_u8Error = DIO_u8SetPortValue(_7SEG2_PORT, u8Symbols[26]);
					break;

				case 121:	//y
					Local_u8Error = DIO_u8SetPortValue(_7SEG2_PORT, u8Symbols[27]);
					break;

				default:	//7SEG Can not Perform so it make an Error
					Local_u8Error = 1;
					break;
				}
			}
		}
	}

	/*if Iteration Reach 29 without found a match value will make an Error*/
	if(Local_u8Iterator == 29)
	{
		Local_u8Error = 1;
	}
	return Local_u8Error;
}

/* Description	: To perform a number consists of TWO Digits
 * Input		: Number E.X. (05), (99) ...
 * Output		: Error State -> 0 No Error
 * 								 1 Error
 */
u8 _7SEG_u8DoubleDigits(u8 Copy_u8Symbol)
{
	/*Local Variables*/
	u8 Local_u8Error = 0, Local_u8Tens = 0, Local_u8Ones = 0;
	u8 Local_u8Iteration = 0;

	/*if Received Variable > 99 make an Error*/
	if(Copy_u8Symbol > 99)
	{
		Local_u8Error = 1;
	}

	else
	{
		/*Make the 2 7SEG PORTs as an OUTPUT*/
		DIO_u8SetPortDirection(_7SEG1_PORT, DIO_MAX_PORT_VALUE);
		DIO_u8SetPortDirection(_7SEG2_PORT, DIO_MAX_PORT_VALUE);

		/*Get the Tens by divide the Value by 10*/
		Local_u8Tens = Copy_u8Symbol / 10;

		/*Check the Tens Value in the Array*/
		for(Local_u8Iteration = 0; Local_u8Iteration <= 9; Local_u8Iteration++)
		{
			/*if Value Exist put it as a PORT Value*/
			if(Local_u8Iteration == Local_u8Tens)
			{
				DIO_u8SetPortValue(_7SEG2_PORT, u8Symbols[Local_u8Iteration]);
				break;
			}
		}

		/*Get the Ones by the Modulus by 10*/
		Local_u8Ones = Copy_u8Symbol % 10;

		/*Check the Tens Value in the Array*/
		for(Local_u8Iteration = 0; Local_u8Iteration < 28; Local_u8Iteration++)
		{
			/*if Value Exist put it as a PORT Value*/
			if(Local_u8Iteration == Local_u8Ones)
			{
				DIO_u8SetPortValue(_7SEG1_PORT, u8Symbols[Local_u8Iteration]);
				break;
			}
		}
	}

	return Local_u8Error;
}
