/*****************************************/
/* ADC_interface.h						 */
/*										 */
/*  Created on: Aug 5, 2020				 */
/*  Author    : PHLIMON					 */
/*  Version   : V01  					 */
/*****************************************/

/*Types*/
#include "STD_TYPES.h"

/*Dependences*/
#include "BIT_MATH.h"
#include "AVR_DIO_REG.h"
#include "AVR_ADC_REG.h"

/*Module*/
#include "DIO_interface.h"
#include "ADC_interface.h"

/* Description	: Initializing all required (Voltage Reference, Prescaler and Resolution) then Enable ADC
 * Input		: Non
 * Output		: Non
 */
void ADC_voidInitialization(void)
{
	/*Choosing Reference Voltage*/
#if Voltage_REF == ADC_AVCC
	SET_BIT(ADMUX, ADMUX_REFS0);
	CLR_BIT(ADMUX, ADMUX_REFS1);

#elif Voltage_REF == ADC_AREF
	CLR_BIT(ADMUX, ADMUX_REFS0);
	CLR_BIT(ADMUX, ADMUX_REFS1);

#elif Voltage_REF == ADC_Internal
	SET_BIT(ADMUX, ADMUX_REFS0);
	SET_BIT(ADMUX, ADMUX_REFS1);

#endif


	/*Choosing Prescaler*/
#if Prescaler == ADC_Prescaler_2
	CLR_BIT(ADCSRA, ADCSRA_ADPS0);
	CLR_BIT(ADCSRA, ADCSRA_ADPS1);
	CLR_BIT(ADCSRA, ADCSRA_ADPS2);

#elif Prescaler == ADC_Prescaler_4
	CLR_BIT(ADCSRA, ADCSRA_ADPS0);
	SET_BIT(ADCSRA, ADCSRA_ADPS1);
	CLR_BIT(ADCSRA, ADCSRA_ADPS2);

#elif Prescaler == ADC_Prescaler_8
	SET_BIT(ADCSRA, ADCSRA_ADPS0);
	SET_BIT(ADCSRA, ADCSRA_ADPS1);
	CLR_BIT(ADCSRA, ADCSRA_ADPS2);

#elif Prescaler == ADC_Prescaler_16
	CLR_BIT(ADCSRA, ADCSRA_ADPS0);
	CLR_BIT(ADCSRA, ADCSRA_ADPS1);
	SET_BIT(ADCSRA, ADCSRA_ADPS2);

#elif Prescaler == ADC_Prescaler_32
	SET_BIT(ADCSRA, ADCSRA_ADPS0);
	CLR_BIT(ADCSRA, ADCSRA_ADPS1);
	SET_BIT(ADCSRA, ADCSRA_ADPS2);

#elif Prescaler == ADC_Prescaler_64
	CLR_BIT(ADCSRA, ADCSRA_ADPS0);
	SET_BIT(ADCSRA, ADCSRA_ADPS1);
	SET_BIT(ADCSRA, ADCSRA_ADPS2);

#elif Prescaler == ADC_Prescaler_128
	SET_BIT(ADCSRA, ADCSRA_ADPS0);
	SET_BIT(ADCSRA, ADCSRA_ADPS1);
	SET_BIT(ADCSRA, ADCSRA_ADPS2);

#endif


	/*Choosing Left or Right Adjustment*/
#if Resolution == ADC_ADCL
	CLR_BIT(ADMUX, ADMUX_ADLAR);

#elif Resolution == ADC_ADCH
	SET_BIT(ADMUX, ADMUX_ADLAR);

#endif


	/*Choosing Interrupt Enable or Disable*/
#if ADC_Interrupt == ADC_Interrupt_Enable
	SET_BIT(ADCSRA, ADCSRA_ADIE);
#elif ADC_Interrupt == ADC_Interrupt_Disable
	CLR_BIT(ADCSRA, ADCSRA_ADIE);
#endif


	/*Enable or Disable ADC Peripheral*/
#if ADC_Enabling == ADC_Enable
	SET_BIT(ADCSRA, ADCSRA_ADEN);

#elif ADC_Enabling == ADC_Disable
	CLR_BIT(ADCSRA, ADCSRA_ADEN);
#endif
}

/* Description	: Get the Digital Value read by ADC
 * Input		: Channel Number, Pointer to put the Value in
 * Output		: Error State -> 0 No Error
 * 								 1 Error
 */
u8 ADC_u8GetReading(u8 Copy_u8Channel, u16 *Copy_u16DigitalValue)
{
	u8 Local_u8Error = 0, Local_u8LowValue = 0;

	if(Copy_u8Channel > 31)
	{
		Local_u8Error = 1;
	}
	else
	{
		/* the anding is for make the last 3 bits as it is with no change
		 * and make the first 5 bits with zeros
		 * then the ORing for add the value of first 3 bits according to the channel
		 */
		ADMUX &= 0xE0;
		ADMUX |= Copy_u8Channel;

		/*Start Conversion*/
		SET_BIT(ADCSRA, ADCSRA_ADSC);

		/* While we polling not Interrupting
		 * wait till the conversion be done
		 */
		while(!(GET_BIT(ADCSRA, ADCSRA_ADIF)));

		/*Set the Flag to Clear*/
		SET_BIT(ADCSRA, ADCSRA_ADIF);

		/*Getting the Value by reading LOW Register First*/
		if(ADMUX_ADLAR == ADC_ADCL)
		{
			Local_u8LowValue = ADCL;
			/*Then Adding the ADCH Value to it as ADCL from bits 0 - 8 and ADCH bits 9 - 10*/
			*Copy_u16DigitalValue = (Local_u8LowValue) | (ADCH << 8);
		}
		else
		{
			/*This mean Ignoring ADCL and GET ADCH bits 2 - 9*/
			*Copy_u16DigitalValue = ADCH;
		}
	}

	return Local_u8Error;
}
