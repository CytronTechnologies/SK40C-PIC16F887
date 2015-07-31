//==========================================================================
//	Author				: CYTRON TECHNOLOGIES SDN BHD
//	Project				: SK40C sample code for PIC16F887
//	Project description	: 7 segment display with I/O with CD4511 decoder
					 					
//==========================================================================

//	include
//==========================================================================
#include <htc.h>
#include "system.h"

//   Configuration
//==========================================================================
__CONFIG(HS &			// External Crystal at High Speed
		 WDTDIS &		// Disable Watchdog Timer.
		 PWRTEN &		// Enable Power Up Timer.
		 BORDIS &		// Disable Brown Out Reset.
		 MCLREN &		// MCLR function is enabled
		 LVPDIS);		// Disable Low Voltage Programming.

//	function prototype
//==========================================================================
void delay_ms(unsigned int ui_value);
;
//	main function
//==========================================================================
void main(void) 
{	
	PORTA = 0;							// Clear PORT
	PORTB = 0;
	PORTC = 0;
	PORTD = 0;

	TRISA = 0b00000000;					// set PORTA as OUTPUT
	TRISB = 0b00000000;					// set PORTB as OUTPUT
	TRISC = 0b00000000;					// set PORTC as OUTPUT
	TRISD = 0b00000000;					// set PORTD as OUTPUT

	ANSEL = 0;
	ANSELH = 0; 						// SET PORTB as DIGITAL I/O for PIC16F887
	WPUB = 1;							// PORTB Weak Pull Up enable

	LT = 0;
	delay_ms(1000);	

unsigned char num = 0;
unsigned int dis1[] = {dis_0,dis_1,dis_2,dis_3,dis_4,dis_5,dis_6,dis_7,dis_8,dis_9};
unsigned int dis2[] = {dis_9,dis_8,dis_7,dis_6,dis_5,dis_4,dis_3,dis_2,dis_1,dis_0};

while (1)
	{
	LE = 0;
	BI = 1;
	LT = 1;
	for (num=0 ; num<10 ; num++)				// loop for 10 times while incresing the num.
		{
		SEG1_dis = dis1[num];					// PORTC display num in dis1[]
		SEG2_dis = dis2[num];					// PORTD display num in dis2[]
		delay_ms(1000);							// delay for 1 sec
		}
	}
}
	
/*******************************************************************************
* PRIVATE FUNCTION: delay_ms
*
* PARAMETERS:
* ~ ui_value	- The period for the delay in miliseconds.
*
* RETURN:
* ~ void
*
* DESCRIPTIONS:
* Delay in miliseconds.
*
*******************************************************************************/
void delay_ms(unsigned int ui_value)
{
	while (ui_value-- > 0) {
		__delay_ms(1);		// macro from HI-TECH compiler which will generate 1ms delay base on value of _XTAL_FREQ in system.h
	}	
}
