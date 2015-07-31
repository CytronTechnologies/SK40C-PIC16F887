//==========================================================================
//	Author				: CYTRON TECHNOLOGIES SDN BHD
//	Project				: SK40C sample code for PIC16F887
//	Project description		: Blink LED1 and LED2 like police car
//
//==========================================================================

//	include
//==========================================================================
#include <htc.h>
#include "system.h"

//	Configuration
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

//	main function
//==========================================================================
void main(void) 
{
	PORTA = 0;				// Clear PORT
	PORTB = 0;
	PORTC = 0;
	PORTD = 0;
	
	TRISA = 0b00000000;		// set PORTA AS output
	TRISB = 0b00000000; 	// set PORTB AS output
	TRISC = 0b00000000;		// set PORTC AS output
	TRISD = 0b00000000;		// set PORTD AS output
	
	ANSEL = 0;				// set PORTA as Digital I/O for PIC16F887
	ANSELH = 0;				// set PORTB as Digital I/O for PIC16F887

	LED1 = 0;				// off LED1
	LED2 = 0;				// off LED2
		
while(1)
	{		
	LED1 = 1;				// High LED1
	delay_ms(100);			// Delay for 100ms
	LED1 = 0;				// Low LED1

	LED2 = 1;				// High LED2
	delay_ms(100);			// Delay for 100ms
	LED2 = 0;				// Low LED2
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
	while (ui_value-- > 0) 
	{
		__delay_ms(1);		// macro from HI-TECH compiler which will generate 1ms delay base on value of _XTAL_FREQ in system.h
	}	
}