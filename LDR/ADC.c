/*
 * ADC.c
 *
 *  Created on: Sep 6, 2019
 *      Author: JESUS
 */
#include "std_types.h"
#include "utils.h"
#include "registers.h"
#include "ADC.h"


/*ADC_Int()
{
	set_bit(ADMUX,REFS0);
	//SELECT Vref = Vcc
	set_bit(ADCSRA,ADEN);
	//ENABLE ADC
	set_bit(ADCSRA,ADPS0);
	set_bit(ADCSRA,ADPS2);
	//SELECT presscaller=32
}*/

void ADC_Int(void)
{
	ADMUX |=(1<<6);
	//SET VREF
	ADCSRA|=(1<<7)|(1<<2)|(1<<0);
	//ENABLE ADC
	//SELECT PRESSSCALR=32
}

u16 ADC_Read(u8 ch)
{
	ADMUX &= 0b11100000;
	ADMUX |= ch;
	ADCSRA|=(1<<6);
	while(!(ADCSRA&(1<<4)));
	ADCSRA|=(1<<4);
	//reset adc flag
	return (ADC);

}







