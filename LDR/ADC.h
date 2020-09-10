/*
 * ADC.h
 *
 *  Created on: Sep 6, 2019
 *      Author: JESUS
 */

#ifndef ADC_H_
#define ADC_H_

#define REFS0 6
#define ADEN  7
#define ADPS0 0
#define ADPS2 2


void ADC_Int(void);

u16 ADC_Read(u8 ch);


#endif /* ADC_H_ */
