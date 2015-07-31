//==========================================================================
//	Author				: CYTRON TECHNOLOGIES SDN BHD
//	Project				: SK40C sample code for PIC16F887
//	Project description	: UART to computer
//==========================================================================

//	include
//==========================================================================
#include <htc.h>
#include "lcd.h"
#include "system.h"
#include "uart.h"

//   Configuration
//==========================================================================
__CONFIG(HS &			// External Crystal at High Speed
		 WDTDIS &		// Disable Watchdog Timer.
		 PWRTEN &		// Enable Power Up Timer.
		 BORDIS &		// Disable Brown Out Reset.
		 MCLREN &		// MCLR function is enabled
		 LVPDIS);		// Disable Low Voltage Programming.

//	main function
//==========================================================================
void main(void) 
{
	PORTA = 0;										// Clear Port
	PORTB = 0;
	PORTC = 0;
	PORTD = 0;

	TRISA = 0b00000000;								// set PORTA as INPUT
	TRISB = 0b00000011;								// set PORTB<7:2> as OUTPUT , PORTB<1:0> as INPUT
	TRISC = 0b10000000;
	TRISD = 0b00000000;								// set PORTD as output
		
	ANSELH = 0; 									// SET PORTB as DIGITAL I/O for PIC16F887

	uart_initialize();								// Initialise UART

	lcd_initialize();								// Initialise LCD

// send signal to Hyperterminal to tell the SK40C is ready
	uart_putstr("Ready To Receive & Transmit!!");

	uart_putstr("Press Switch 1.");		
	while (SW1 == 1);
	uart_putstr("Switch 1 Pressed!!.");

	uart_putstr("Press Switch 2.");
	while (SW2 == 1);
	uart_putstr("Switch 2 Pressed!!.");

	

// receive data from HyperTerminal by pressing PC keyboard
while (1)
	{
	unsigned int data,i = 0;
	for (i=0 ; i<32 ; i++)								// LCD have 32 display spaces
		{
		if(i == 15)lcd_2ndline();						// if more then 0x0F,jump to 2nd line
		else if (i == 31)lcd_home();					// if more then 0x4F, jump to 1st line

			uc_uart_receive();							// UART receive data	
			data = RCREG;								// receive data from uart and save at data
			send_lcd_data(1,data);						// data the data to LCD display
		}
	}
}	

