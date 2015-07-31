/*******************************************************************************
* This is the header file that describes the system properties for PTK40A
*
* Cytron Technologies Sdn. Bhd.
*******************************************************************************/
#ifndef _SYSTEM_H
#define _SYSTEM_H

//	define
//==========================================================================
#define	_XTAL_FREQ	2E6	/* Crystal frequency in 20MHz */

#define SW1 	RB0	
#define SW2	RB1							

#define LED1	RB6
#define LED2	RB7

// I/O Connections.
// Parallel 2x16 Character LCD
#define LCD_E			RB5		// E clock pin is connected to RA3	
#define LCD_RS			RB4		// RS pin is used for LCD to differentiate data is command or character, RA2

#define	LCD_DATA		PORTD	// Data port of LCD is connected to PORTD, 8 bit mode
								// DB7(LCD) = RD7(PIC)
								// DB6(LCD) = RD6(PIC)
								// DB5(LCD) = RD5(PIC)
								// DB4(LCD) = RD4(PIC)
								// DB3(LCD) = RD3(PIC)
								// DB2(LCD) = RD2(PIC)
								// DB1(LCD) = RD1(PIC)
								// DB0(LCD) = RD0(PIC)
//4x4 Keypad
#define KP_R1			RC4		// Row 1
#define KP_R2			RC5		// Row 2
#define KP_R3			RC6		// Row 3
#define KP_R4			RC7		// Row 4

#define KP_C1			RC3		// Colomn 1
#define KP_C2			RC2		// Colomn 2
#define KP_C3			RC1		// Colomn 3
#define KP_C4			RC0		// Colomn 4

// External component define here 
//=================================================================================

#endif