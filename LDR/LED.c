/*
 * LED.c
 *
 *  Created on: Aug 21, 2019
 *      Author: JESUS
 */
#include "std_types.h"
#include "utils.h"
#include "registers.h"
#include "LED.h"
#include"DIO.h"

void LED_VidSetBit(u8 port, u8 pin )
{

	switch(port)
	{
		case A:

		DIO_VidSetDir(A, pin, output);

		break;

		case B:

		DIO_VidSetDir(B, pin, output);

		break;

		case C:

		DIO_VidSetDir(C, pin, output);

		break;

		case D:

		DIO_VidSetDir(D, pin, output);

		break;

	}
}

void LED_VidTurnOn(u8 port, u8 pin )
{

	switch(port)
	{
		case A:

			DIO_VidWriteValue(A, pin, ON);

			break;

		case B:

			DIO_VidWriteValue(B, pin, ON);

			break;

		case C:

			DIO_VidWriteValue(C, pin, ON);

			break;

		case D:

			DIO_VidWriteValue(D, pin, ON);

			break;

	}
}

void LED_VidTurnOff(u8 port, u8 pin )
{

	switch(port)
	{
		case A:

			DIO_VidWriteValue(A, pin, OFF);

			break;

		case B:

			DIO_VidWriteValue(B, pin, OFF);

			break;

		case C:

			DIO_VidWriteValue(C, pin, OFF);

			break;

		case D:

			DIO_VidWriteValue(D, pin, OFF);

			break;

	}
}
