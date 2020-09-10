/*
 * KPD_program.c
 *
 *  Created on: Jun 30, 2020
 *      Author: my
 */

/*Standard Types*/
#include "STD_TYPES.h"

/*Module*/
#include "DIO_interface.h"
#include "KPD_interface.h"

/*Multi-Dimensional Array for the Key Pad Grid*/
static u8 Local_u8KeyGrid[4][4] = {
									{1 , 2 , 3 ,  '/'},
									{4 , 5 , 6 ,  '*'},
									{7 , 8, 9, '-'},
									{13, 0, '=', '+'}
									};

/* Description	: KPD Initialization
 * Input		: Non
 * Output		: Error State -> 0 No Error
 * 								 1 Error
 */
u8 KPD_u8Initialization()
{
	/*Local Variable*/
	u8 Local_u8Error = 0;

	/*Check for the KPD Port is OK*/
#if KPD_PORT < 4
	/*KeyPad Initialization*/
	DIO_u8SetPortDirection(KPD_PORT, 0x0f);

	/*Pull Up Activation for KeyPad*/
	DIO_u8SetPortValue(KPD_PORT, 0xff);

#elif
	Local_u8Error = 1;

#endif
	return Local_u8Error;
}

/* Description	: Get the Key pressed
 * Input		: Pointer for the Pressed key
 * Output		: Error State -> 0 No Error
 * 								 1 Error
 */
u8 KPD_u8GetPressedKey(u8 *Copy_u8KeyNB)
{
	/*Local Variables*/
	u8 Local_u8Error = 0;
	u8 Local_u8ColID = 0, Local_u8RowID = 0, Local_u8PinState = 0;

	/*Looping for the Column and inside each column loop on Rows*/
	for(Local_u8ColID = 0; Local_u8ColID < COL_NB; Local_u8ColID++)
	{
		/*Before set the Column as LOW make it as GND*/
		DIO_u8SetPinValue(KPD_PORT, Local_u8ColID, DIO_LOW);

		/*Loop for the Rows Check the Value from the Button if Pressed*/
		for(Local_u8RowID = 0; Local_u8RowID < ROW_NB; Local_u8RowID++)
		{
			/*We Add Four for the Row because the Rows Pins starts from Pin 4 -> 7*/
			DIO_u8GetPinValue(KPD_PORT, (Local_u8RowID + ROW_START_AFTER), &Local_u8PinState);

			/*if the Value equals LOW that means the button is pressed*/
			if(Local_u8PinState == DIO_LOW)
			{
				/*Send the Value through the pointer*/
				*Copy_u8KeyNB = Local_u8KeyGrid[Local_u8RowID][Local_u8ColID];
				Local_u8Error = 1;

				/*Blocking state do not do anything while the button is pressed*/
				while(Local_u8PinState != DIO_HIGH)
				{
					DIO_u8GetPinValue(KPD_PORT, (Local_u8RowID + ROW_START_AFTER), &Local_u8PinState);
				}
			}
		}
		/*de-activate the current column*/
		DIO_u8SetPinValue(KPD_PORT, Local_u8ColID, DIO_HIGH);
	}
	return Local_u8Error;
}
