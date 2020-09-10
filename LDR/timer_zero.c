/*
 * timer_zero.c
 *
 *  Created on: Sep 20, 2019
 *      Author: JESUS
 */


#include "std_types.h"
#include "utils.h"
#include "registers.h"
#include "DIO.h"
#include "timer_zero.h"


void Timer_zero_Int_pwm(void)
{
	TCCR0 = 0b01101101;
	OCR0=255;
	DIO_VidSetDir(B,3,output);

}

void Timer_zero_Int_pwm0_1(void)
{
	TCCR0 = 0b01101101;
	OCR0=255;
	DIO_VidSetDir(B,3,output);

}

void Timer_zero_Int_pwm3_4(void)
{
	DIO_VidSetDir(B,3,output);
	DIO_VidWriteValue(B,3,0);

}

void Timer_zero_Int_pwm2(void)
{
	TCCR0 = 0b01101101;
	OCR0=100;
	DIO_VidSetDir(B,3,output);

}
