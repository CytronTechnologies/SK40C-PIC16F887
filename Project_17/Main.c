/* 
 * File:   Main.c
 * Author: Hatake_Chin
 *
 * Created on August 11, 2012, 11:14 AM
 */

//	include
//==========================================================================
#include <htc.h>
#include "lcd.h"
#include "system.h"
#include "keypad.h"

//   Configuration
//==========================================================================

__CONFIG(HS &			// High Speed Crystal.
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
        unsigned char key_get;
	PORTA = 0;						// clear PORT
	PORTB = 0;
	PORTC = 0;
	PORTD = 0;

	TRISA = 0b00000000;				// set PORTA as OUTPUT
	TRISB = 0b00000011; 			// set PORTB<7:2> AS OUTPUT , PORTB<1:0> as INPUT
	TRISC = 0b00001111;				// set PORTC as OUTPUT
	TRISD = 0B00000000;				// set PORTD as OUTPUT

	ANSEL = 0;						// SET PORTA as DIGITAL I/O for PIC16F887
	ANSELH = 0; 					// SET PORTB as DIGITAL I/O for PIC16F887

	lcd_initialize();				// Initialise LCD.. Please refer lcd.c file for detail

    while(1)
    {
        LED1 = 1;
        LED2 = 0;
        lcd_home();                         // LCD return cursor to home position
        lcd_putstr("   Enter Key:");		//LCD display (Please refer lcd.c for detail)
        lcd_2ndline();
        for(unsigned int i = 0; i < 17; i++)    // Enable the character be displayed by 16 times at 2nd row
        {
        key_get = keypad_wait();                // Wait until button on keypad being pressed
        lcd_putchar(key_get);                   // Display the character on lcd
        LED1 ^= 1;
        LED2 ^= 1;
        }
        lcd_clear();
    }
}