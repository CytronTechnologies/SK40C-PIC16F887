//==========================================================================
//	Author				: CYTRON TECHNOLOGIES SDN BHD
//	Project				: SK40C sample code for PIC16F887
//	Project description	: Digital Input : Push Button	
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

// Global Variable
//==========================================================================

//	main function
//==========================================================================
void main(void) 
{
	PORTA = 0;				// clear PORT
	PORTB = 0;				
	PORTC = 0;
	PORTD = 0;

	TRISA = 0b00000000;		// set PORTA as OUTPUT
	TRISB = 0b00000111; 	// set PORTB<7:3> AS OUTPUT , PORTB<2:0> as INPUT
	TRISC = 0b00000000;		// set PORTC as OUTPUT
	TRISD = 0b00000000;		// set PORTD as OUTPUT
	
	ANSEL = 0;
	ANSELH = 0; 			// SET PORTB as DIGITAL I/O for PIC16F887

	LED1 = 0;				// off LED1 on SK40C
	LED2 = 0;				// off LED2 on SK40C

while(1)
	{
	while (SW1 == 0)			// If Switch 1 is press.. Blink LED1 and loop until SW1 = 1
		{
		LED1 = 1;			
		delay_ms(80);		
		LED1 = 0;
		delay_ms(80);				
		}

	while (SW2 == 0)			// IF Switch 2 is press.. Blink LED2 and loop until SW2 = 1
		{
		LED2 = 1;			
		delay_ms(80);		
		LED2 = 0;
		delay_ms(80);	
		}

	while (SW3 ==0)			// IF Switch 2 is press.. Blink LED1 & LED2 and loop until SW3 = 1
		{
		LED1 = 1;
		LED2 = 1;
		delay_ms(80);
		LED1 = 0;
		LED2 = 0;
		delay_ms(80);
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
	while (ui_value-- > 0) 
	{
		__delay_ms(1);		// macro from HI-TECH compiler which will generate 1ms delay base on value of _XTAL_FREQ in system.h
	}	
}