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
#define Buzzer			RC1

//				ms				  HZ	
#define A4		78				//440 		
#define B4b		74				//466			
#define C4		132				//261
#define C4_1	130	
#define C5		65				//523		
#define D4		117				//293	
#define D4b		124				//277				
#define E4		105				//329			
#define F4		98				//349			
#define G4		88				//392		
	
	
#endif