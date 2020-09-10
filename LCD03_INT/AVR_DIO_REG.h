/*
 * AVR_DIO_REG.h
 *
 *  Created on: May 24, 2020
 *      Author: my
 */

#ifndef AVR_DIO_REG_H_
#define AVR_DIO_REG_H_

/*Register with Memory Maping for Port A*/
#define PORTA (*((u8*) 0x3B))
#define DDRA  (*((u8*) 0x3A))
#define PINA  (*((u8*) 0x39))

/*Register with Memory Maping for Port B*/
#define PORTB (*((u8*) 0x38))
#define DDRB  (*((u8*) 0x37))
#define PINB  (*((u8*) 0x36))

/*Register with Memory Maping for Port C*/
#define PORTC (*((u8*) 0x35))
#define DDRC  (*((u8*) 0x34))
#define PINC  (*((u8*) 0x33))

/*Register with Memory Maping for Port D*/
#define PORTD (*((u8*) 0x32))
#define DDRD  (*((u8*) 0x31))
#define PIND  (*((u8*) 0x30))

#endif /* AVR_DIO_REG_H_ */
