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
// CD4511 I/O
/*
RC7	RC6	RC5	RC4	RC3	RC2	RC1	RC0		Binary
0	g	f	e	d	c	b	a									 	 a
0	0	1	1	1	1	1	1		0000		'0'					------
0	0	0	0	0	1	1	0		0001		'1'				   |      |
0	1	0	1	1	0	1	1		0010		'2'			     f |  g   | b
0	1	0	0	1	1	1	1		0011		'3'					------
0	1	1	0	0	1	1	0		0100		'4'				   |	  | c
0	1	1	0	1	1	0	1		0101		'5'				 e |	  |
0	1	1	1	1	1	0	1		0110		'6'					------
0	0	0	0	0	1	1	1		0111		'7'					   d
0	1	1	1	1	1	1	1		1000		'8'	
0	1	1	0	0	1	1	1		1001		'9'	

*RC7 are no need to be connected
*/

#define dis_1 		0b00000001
#define dis_2 		0b00000010
#define dis_3 		0b00000011
#define dis_4 		0b00000100
#define dis_5 		0b00000101
#define dis_6 		0b00000110
#define dis_7 		0b00000111
#define dis_8 		0b00001000
#define dis_9 		0b00001001
#define dis_0 		0b00000000

#define LE			RB2
#define BI			RB1
#define LT			RB0

#define SEG1_dis		PORTC 
#define SEG2_dis		PORTD 
		
#endif