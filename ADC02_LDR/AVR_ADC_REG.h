/*****************************************/
/* AVR_ADC_REG.h						 */
/*										 */
/*  Created on: Aug 5, 2020				 */
/*  Author    : PHLIMON					 */
/*  Version   : V01  					 */
/*****************************************/

/*Header Guard*/
#ifndef AVR_ADC_REG_H_
#define AVR_ADC_REG_H_

/*ADC Multiplexer Register*/
#define ADMUX (*((u8*) 0x27))

#define ADMUX_MUX0			0
#define ADMUX_MUX1			1
#define ADMUX_MUX2			2
#define ADMUX_MUX3			3
#define ADMUX_MUX4			4
#define ADMUX_ADLAR			5
#define ADMUX_REFS0			6
#define ADMUX_REFS1			7

/*ADC Control and Status Register*/
#define ADCSRA (*((u8*) 0X26))

#define ADCSRA_ADPS0		0
#define ADCSRA_ADPS1		1
#define ADCSRA_ADPS2		2
#define ADCSRA_ADIE			3
#define ADCSRA_ADIF			4
#define ADCSRA_ADATE		5
#define ADCSRA_ADSC			6
#define ADCSRA_ADEN			7

/*Special Function I/O Register*/
#define SFIOR (*((U8*) 0X50))

#define SFIOR_PSR10			0
#define SFIOR_PSR2			1
#define SFIOR_PUD			2
#define SFIOR_ACME			3
#define SFIOR_ADTS0			5
#define SFIOR_ADTS1			6
#define SFIOR_ADTS2			7

/*ADC High Register*/
#define ADCH (*((u8*) 0X25))

/*ADC Low Register*/
#define ADCL (*((u8*) 0X24))

#endif /* AVR_ADC_REG_H_ */
