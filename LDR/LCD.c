/*
 * LCD.c

 *
 *  Created on: Aug 23, 2019
 *      Author: JESUS
 */

#include "std_types.h"
#include "utils.h"
#include "registers.h"
#include "LCD.h"
#include "LCD_cfg.h"
#include<avr/delay.h>

#include "DIO.h"
#define F_CPU 8000000

void LCD_VidWriteCommand(u8 command)
{
	//RW = 0
	DIO_VidWriteValue(controlport, rw_pin, low);
	//RS = 0
	DIO_VidWriteValue(controlport, rs_pin, low);
	//command data port
	DIO_VidSetPortValue(dataport, command);
	//E=1
	DIO_VidWriteValue(controlport, e_pin, high);
	_delay_ms(2);
	DIO_VidWriteValue(controlport,e_pin, low);

}

void LCD_VidWriteData(u8 data)
{
	//RW = 0
	DIO_VidWriteValue(controlport, rw_pin, low);
	//RS=1
	DIO_VidWriteValue(controlport,rs_pin, high);
	//command data port
	DIO_VidSetPortValue(dataport, data);
	//E=1
	DIO_VidWriteValue(controlport,e_pin, high);
	_delay_ms(2);
	DIO_VidWriteValue(controlport,e_pin, low);
}

void LCD_VidInit(void)
{

	DIO_VidSetDir(controlport, rs_pin, output);
	DIO_VidSetDir(controlport, rw_pin, output);
	DIO_VidSetDir(controlport, e_pin, output);
	DIO_VidSetPortDir(dataport, 255);
	_delay_ms(50);
	LCD_VidWriteCommand(0b00111100);
	_delay_ms(1);
	LCD_VidWriteCommand(0b00001100);
	_delay_ms(1);
	LCD_VidWriteCommand(0b00000001);
	_delay_ms(2);


}






void LCD_Gotoxy (u8 Y,u8 X)
{
	if (X>0 && X<=16)
	{
	    switch(Y)
	    {
		    case 1:
		    	LCD_VidWriteCommand(X+127);
		    break;
		    case 2:
		    	LCD_VidWriteCommand(X+191);
		    break;
		    default:
		    break;
	    }
	}
}


void LCD_vidWriteInteger(u32 m){
u32 t,t1,t2,t3;
if(m<10)
{
			LCD_VidWriteData(m+48);

}
	if(m>9&&m<100){

		t = m/10;
		t1 = m%10;
		LCD_VidWriteData((t+48));
		LCD_VidWriteData((t1+48));
	}
	if(m>=100&&m<=999){

		t = m/10;
			t1 = t%10;
			t2 = t1/10;
			t3 = t1%10;
			LCD_VidWriteData(t+48);
			LCD_VidWriteData(t2+48);
			LCD_VidWriteData(t3+48);
			;
	}
}



