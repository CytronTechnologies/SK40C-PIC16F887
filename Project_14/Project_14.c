//==========================================================================
//	Author				: CYTRON TECHNOLOGIES SDN BHD
//	Project				: SK40C sample code for PIC16F887
//	Project description	: Interface with Relay (Morce Code for "CYTRON")
//												 					
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

//	main function
//==========================================================================
void main(void) 
{	
	PORTA = 0;							// Clear Port
	PORTB = 0;
	PORTC = 0;
	PORTD = 0;

	TRISA = 0b00000000;					// set PortA as OUTPUT
	TRISB = 0b00000011;					// set PORTB<1:0> as INPUT
	TRISC = 0b00000000;
	TRISD = 0b00000000;					// set PORTD as OUTPUT
		 
	ANSEL = 0;							// Set PORTA as Digital I/O	for PIC16F887
	ANSELH = 0; 						// SET PORTB as DIGITAL I/O for PIC16F887

while (1)
	{
	if (SW1 == 0) Relay1 = 1;	
	else Relay1 = 0;	
	}
}
