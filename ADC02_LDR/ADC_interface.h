/*****************************************/
/* ADC_interface.h						 */
/*										 */
/*  Created on: Aug 5, 2020				 */
/*  Author    : PHLIMON					 */
/*  Version   : V01  					 */
/*****************************************/

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

/*32 Available Channels in ADC*/
#define Channel_0		0
#define Channel_1		1
#define Channel_2		2
#define Channel_3		3
#define Channel_4		4
#define Channel_5		5
#define Channel_6		6
#define Channel_7		7
#define Channel_8		8
#define Channel_9		9
#define Channel_10		10
#define Channel_11		11
#define Channel_12		12
#define Channel_13		13
#define Channel_14		14
#define Channel_15		15
#define Channel_16		16
#define Channel_17		17
#define Channel_18		18
#define Channel_19		19
#define Channel_20		20
#define Channel_21		21
#define Channel_22		22
#define Channel_23		23
#define Channel_24		24
#define Channel_25		25
#define Channel_26		26
#define Channel_27		27
#define Channel_28		28
#define Channel_29		29
#define Channel_30		30
#define Channel_31		31

/*Choosing the ADC Voltage Reference*/
#define Voltage_REF		ADC_AVCC
#define ADC_AVCC 		0 	//5V
#define ADC_AREF		1	//Adjusted
#define ADC_Internal	2	//2.56V

/*Choosing the prescaler*/
#define Prescaler 			ADC_Prescaler_2		//Crystal Freq. / Prescaler
#define ADC_Prescaler_2		2
#define ADC_Prescaler_4  	4
#define ADC_Prescaler_8		8
#define ADC_Prescaler_16	16
#define ADC_Prescaler_32	32
#define ADC_Prescaler_64	64
#define ADC_Prescaler_128	128

/*Left Right Adjustment*/
#define Resolution			ADC_ADCH   //0 for ADCL Right Adjustment, 1 for ADCH Left Adjustment
#define ADC_ADCL 0			 		   //Reads the Low Bits 0 - 7 then 8 - 9 in second register
#define ADC_ADCH 1			  		   //Reads the high Bits 2 - 9 then 0 - 1 in second register

/*ADC Interrupt Enable or Disable*/
#define ADC_Interrupt 		ADC_Interrupt_Enable
#define ADC_Interrupt_Enable 1
#define ADC_Interrupt_Diable 0

//ADC Enable or Disable
#define ADC_Enabling 		ADC_Enable
#define ADC_Enable  1
#define ADC_Disable 0

/* Description	: Initializing all required (Voltage Reference, Prescaler and Resolution) then Enable ADC
 * Input		: Non
 * Output		: Non
 */
void ADC_voidInitialization(void);

/* Description	: Get the Digital Value read by ADC
 * Input		: Channel Number, Pointer to put the Value in
 * Output		: Error State -> 0 No Error
 * 								 1 Error
 */
u8 ADC_u8GetReading(u8 Copy_u8Channel, u16 *Copy_u16DigitalValue);

#endif /* ADC_INTERFACE_H_ */
