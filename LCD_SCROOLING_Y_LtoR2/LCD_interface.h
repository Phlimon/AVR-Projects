/*
 * LCD_interface.h
 *
 *  Created on: May 29, 2020
 *      Author: my
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#define LCD_DATA_PORT 				DIO_PORT_1
#define LCD_CONTROL_PORT		 	DIO_PORT_2
#define LCD_RS_PIN					DIO_PIN_0
#define LCD_RW_PIN					DIO_PIN_1
#define LCD_E_PIN					DIO_PIN_2

#define MAX_U32_NB					4294967295
#define MAX_NB_BITS_SPECIAL_CHAR 	64
#define NB_OF_SPECIAL_CHAR			8
#define AC_REG_COMMAND				128
#define DDRAM_LINE1_FIRST_LOCATION	0x00
#define DDRAM_LINE2_FIRST_LOCATION	0x40
#define LCD_LINE_NB_OF_DIGITS		16

#define LCD_MAX_SCROLL_LINE			41
#define LCD_MAX_SCROLL_LINE_2		21
#define LCD_OV_LINE_1				103
#define LCD_OV_LINE_2				232

/* Description	: Send a Command to LCD through the Data PORT
 * Input		: Command
 * Output		: Non
 */
void LCD_voidWriteCommand(u8 Copy_u8Command);

/* Description	: Clear LCD
 * Input		: Non
 * Output		: Non
 */
void LCD_voidClearLCD(void);

/* Description	: Send a Data to LCD through the Data PORT
 * Input		: Data
 * Output		: Non
 */
void LCD_voidWriteData(u8 Copy_u8Data);

/* Description	: Initializing the LCD
 * Input		: Non
 * Output		: Non
 */
void LCD_voidInitialization(void);

/* Description	: Write A string to LCD
 * Input		: Array of Strings, Size of this Array
 * Output		: Error State -> 0 No Error
 * 								 1 Error
 */
u8 LCD_u8WriteString(u8 *Copy_u8String, u8 Copy_u8StrSize);

/* Description	: Put the Cursor to specific position and print in this position
 * Input		: X Position, Y Position
 * Output		: Error State -> 0 No Error
 * 								 1 Error
 */
u8 LCD_u8GoToXY(u8 Copy_u8XPos, u8 Copy_u8YPos);

/* Description	: Store in a CGRAM Memory the Special Character
 * 					(TO PRINT THE SPECIAL CHAR USE LCD_u8WriteData with Input 0 -> 7as an ASCII code as in ASCII these positions
 * 					are for non printed characters and you have only 8 special Char from 0 -> 7
 * Input		: An Array of the Special Characters we have only 8 Positions
 * Output		: Error State -> 0 No Error
 * 								 1 Error
 */
u8 LCD_u8WriteSpecialChar(u8 *Copy_u8SpecialChar);

/* Description	: Print an Integer on LCD u32 with Max number 4294967295
 * Input		: The Integer Number, X position, Y Position
 * Output		: Error State -> 0 No Error
 * 								 1 Error
 */
u8 LCD_u8WriteINT(u32 Copy_u32INT, u8 Copy_u8XPos, u8 Copy_u8YPos);

#endif /* LCD_INTERFACE_H_ */
