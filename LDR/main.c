/*
 * main.c
 *
 *  Created on: Sep 7, 2019
 *      Author: JESUS
 */

#include "std_types.h"
#include "utils.h"
#include "utilss.h"

#include "registers.h"
#include "DIO.h"
#include "ADC.h"
#include "LCD.h"
#include"timer_zero.h"
#include "Timer1.h"

#include"LED.h"
#include<avr/delay.h>
#define F_COU 8000000

// sensor for light and temp
void main(void)
{
	ADC_Int();
	LCD_VidInit();

while(1)
{
	u16 digital2 = ADC_Read(1);//0->7 CH
	u16 ang2 = (digital2 * 5)/(1023);
	LCD_Gotoxy(2,1);
	LCD_VidWriteData('B');
	LCD_VidWriteData('r');
	LCD_VidWriteData('i');
	LCD_VidWriteData('g');
	LCD_VidWriteData('h');
	LCD_VidWriteData('t');
	LCD_VidWriteData('n');
	LCD_VidWriteData('e');
	LCD_VidWriteData('s');
	LCD_VidWriteData('s');
	LCD_VidWriteData(':');
	LCD_VidWriteData(' ');
	LCD_vidWriteInteger(ang2);


	DIO_VidSetDir(D,pin5,output);

	switch (ang2)
	{
	case 0:
		TIMER1_voidInit();
		OCR1AL=100;
		DIO_VidWriteValue(D,pin5,high);
		break;

	case 1:
		TIMER1_voidInit();
		OCR1AL=10	;
		DIO_VidWriteValue(D,pin5,high);
		break;

	case 2:
		TIMER1_voidInit();
		OCR1AL=10	;
		break;

	case 3:

		OCR1AL=0;
		TIMER1_voidInit0ff();

		DIO_VidWriteValue(D,pin5,low);
		break;

	case 4:
		//OCR1AL=0;

		//DIO_VidWriteValue(D,pin5,low);

		TIMER1_voidInit0ff();
		DIO_VidWriteValue(D,pin5,low);

		break;

	}

}
}
