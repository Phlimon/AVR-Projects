/*
 * DIO.C
 *
 *  Created on: Aug 17, 2019
 *      Author: JESUS
 */

#include "std_types.h"
#include "utils.h"
#include "registers.h"
#include "DIO.h"


void DIO_VidSetDir(u8 port, u8 pin, u8 dir)
{
	switch(port){

	case A:

		if(dir == input)
		{
			clr_bit(DDRA,pin);
		}
		if(dir == output)
		{
			set_bit(DDRA,pin);
		}
	break;

	case B:
			if(dir == input)
			{
				clr_bit(DDRB,pin);
			}
			if(dir == output)
			{
				set_bit(DDRB,pin);
			}
	break;

	case C:
			if(dir == input)
			{
				clr_bit(DDRC,pin);
			}
			if(dir == output)
			{
				set_bit(DDRC,pin);
			}
	break;

	case D:
			if(dir == input)

				clr_bit(DDRD,pin);

			if(dir == output)
				set_bit(DDRD,pin);

	break;
}//end of switch
}//end of function

void DIO_VidWriteValue(u8 port, u8 pin, u8 value)
{
	switch(port){
	case A:
		if(value == low)
		{
			clr_bit(PORTA,pin);
		}
		if(value == high)
		{
			set_bit(PORTA,pin);
		}
	break;

	case B:
		if(value == low)
				{
					clr_bit(PORTB,pin);
				}
				if(value == high)
				{
					set_bit(PORTB,pin);
				}
			break;
	case C:
		if(value == low)
				{
					clr_bit(PORTC,pin);
				}
				if(value == high)
				{
					set_bit(PORTC,pin);
				}
		break;
	case D:
		if(value == low)
				{
					clr_bit(PORTD,pin);
				}
				if(value == high)
				{
					set_bit(PORTD,pin);
				}
			break;
}//end of switch
}//end of fun

u8 DIO_U8ReadPin(u8 port, u8 pin)
{
	switch(port){
	case A:

		return get_bit(PINA,pin);

	break;

	case B:

			return get_bit(PINB,pin);

	break;

	case C:

			return get_bit(PINC,pin);

	break;

	case D:

	return get_bit(PIND,pin);

	break;

	default:

		return 2;
break;
}

}

void DIO_VidSetPortDir(u8 port, u8 dir)
{
	switch(port)
	{
		case A:
			DDRA = dir;
			break;
		case B:
			DDRB = dir;
			break;
		case C:
			DDRC = dir;
			break;
		case D:
			DDRD = dir;
			break;
	}
}


void DIO_VidSetPortValue(u8 port, u8 value)
{
	switch(port)
	{
		case A:
			PORTA = value;
			break;
		case B:
			PORTB= value;
			break;
		case C:
			PORTC = value;
			break;
		case D:
			PORTD = value;
			break;
	}
}

