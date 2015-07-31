//==========================================================================
//	Author				: CYTRON TECHNOLOGIES SDN BHD
//	Project				: SK40C sample code for PIC16F887
//	Project description	: "Hello World" with Parallel LCD 16x2	
//==========================================================================

//	include
//==========================================================================
#include <htc.h>
#include "lcd.h"
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

//	main function
//==========================================================================
void main(void) 
{
	PORTA = 0;						// clear PORT
	PORTB = 0;	
	PORTC = 0;					
	PORTD = 0;

	TRISA = 0b00000000;				// set PORTA as OUTPUT
	TRISB = 0b00000011; 			// set PORTB<7:2> AS OUTPUT , PORTB<1:0> as INPUT
	TRISC = 0b00000000;				// set PORTC as OUTPUT
	TRISD = 0B00000000;				// set PORTD as OUTPUT

	ANSEL = 0;						// SET PORTA as DIGITAL I/O for PIC16F887
	ANSELH = 0; 					// SET PORTB as DIGITAL I/O for PIC16F887

	lcd_initialize();				// Initialise LCD.. Please refer lcd.c file for detail
									
while(1)
	{
	lcd_home();						// LCD return cursur to home position which is 0x00.
	lcd_putstr("Hello World");		//LCD display (Please refer lcd.c for detail)
	}
}
