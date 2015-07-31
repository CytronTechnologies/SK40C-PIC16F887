/*******************************************************************************
* This is the header file that describes the system properties for PTK40A
*
* Cytron Technologies Sdn. Bhd.
*******************************************************************************/
#ifndef _SYSTEM_H
#define _SYSTEM_H

//	define
//==========================================================================
#define	_XTAL_FREQ	20000000	/* Crystal frequency in MHz */

#define SW1 	RB0	
#define SW2		RB1							

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

// UART
#define TX		RC6
#define RX		RC7

// External component define here 
//=================================================================================
//7 segment I/O
/*
RC7	RC6	RC5	RC4	RC3	RC2	RC1	RC0
0	g	f	e	d	c	b	a						  a
0	0	1	1	1	1	1	1	'0'					------
0	0	0	0	0	1	1	0	'1'				   |      |
0	1	0	1	1	0	1	1	'2'			     f |  g   | b
0	1	0	0	1	1	1	1	'3'					------
0	1	1	0	0	1	1	0	'4'				   |	  | c
0	1	1	0	1	1	0	1	'5'				 e |	  |
0	1	1	1	1	1	0	1	'6'					------
0	0	0	0	0	1	1	1	'7'					   d
0	1	1	1	1	1	1	1	'8'	
0	1	1	0	0	1	1	1	'9'	

*RC7 are no need to be connected
*/

#define dis_1 		0b00000110
#define dis_2 		0b01011011
#define dis_3 		0b01001111
#define dis_4 		0b01100110
#define dis_5 		0b01101101
#define dis_6 		0b01111101
#define dis_7 		0b00000111
#define dis_8 		0b01111111
#define dis_9 		0b01100111
#define dis_0 		0b00111111

#define SEG1_dis		PORTC 
#define SEG2_dis		PORTD 		
#endif