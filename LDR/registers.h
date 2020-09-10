/*
 * registers.h
 *
 *  Created on: Aug 17, 2019
 *      Author: JESUS
 */

#ifndef REGISTERS_H_
#define REGISTERS_H_

#define DDRA (*(volatile u8 *)0x3A)
#define DDRB (*(volatile u8 *)0x37)
#define DDRC (*(volatile u8 *)0x34)
#define DDRD (*(volatile u8 *)0x31)


#define PORTA (*(volatile u8 *)0x3B)
#define PORTB (*(volatile u8 *)0x38)
#define PORTC (*(volatile u8 *)0x35)
#define PORTD (*(volatile u8 *)0x32)


#define PINA (*(volatile u8 *)0x39)
#define PINB (*(volatile u8 *)0x36)
#define PINC (*(volatile u8 *)0x33)
#define PIND (*(volatile u8 *)0x30)

#define SREG (*(volatile u8 *)0x5F)
#define GICR (*(volatile u8 *)0x5B)
#define GIFR (*(volatile u8 *)0x5A)
#define MCUCR (*(volatile u8 *)0x55)
#define MCUCSR (*(volatile u8 *)0x54)


#define ADMUX (*(volatile u8 *)0x27)
#define ADCSRA (*(volatile u8 *)0x26)
#define ADCL (*(volatile u8 *)0x24)
#define ADCH (*(volatile u8 *)0x25)
#define ADC (*(volatile u16 *)0x24)//Y2RA KOL

#define TCCR0 (*(volatile u8 *)0x53)
#define TIMSK (*(volatile u8 *)0x59)
#define OCR0 (*(volatile u8 *)0x5C)
#define TIFR (*(volatile u8 *)0x58)
#define TCCR2 (*(volatile u8 *)0x45)
#define TCNT2 (*(volatile u8 *)0x44)


#endif /* REGISTERS_H_ */
