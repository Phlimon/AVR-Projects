/*
 * APP_program.c
 *
 *  Created on: Jul 3, 2020
 *      Author: my
 */

/*Standard Types*/
#include "STD_TYPES.h"

/*Module*/
#include "DIO_interface.h"
#include "APP_interface.h"

u8 CAL_u8OperandNOD(u32 Copy_Operand)
{
	u8 Local_u8NOD = 0;

	/*Loop to get the Number of Digits*/
	while(Copy_Operand != 0)
	{
		/*Dividing the Integer number by 10 till we have a result of Division Zero*/
		Copy_Operand /= 10;

		/*With each Division Add 1 to Number of Digits*/
		Local_u8NOD++;
	}

	return Local_u8NOD;
}
