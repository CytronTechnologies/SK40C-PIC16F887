//==========================================================================
//	Author				: CYTRON TECHNOLOGIES SDN BHD
//	Project				: SK40C sample code for PIC16F887
//	Project description	: Analog Sensor: Range using Infrared distance sensor
//==========================================================================

//	include
//==========================================================================
#include <htc.h>
#include "lcd.h"
#include "adc.h"
#include "system.h"

//   Configuration
//==========================================================================
__CONFIG(HS &			// External Crystal at High Speed
		 WDTDIS &		// Disable Watchdog Timer.
		 PWRTEN &		// Enable Power Up Timer.
		 BORDIS &		// Disable Brown Out Reset.
		 MCLREN &		// MCLR function is enabled
		 LVPDIS);		// Disable Low Voltage Programming.

//	global variable
//===========================================================================


//	main function
//==========================================================================
void main(void) 
{
unsigned char mode = 1;
	PORTA = 0;							// Clear Port
	PORTB = 0;
	PORTC = 0;
	PORTD = 0;

	TRISA = 0b11111111;					// set PORTA as INPUT
	TRISB = 0b00000011;					// set PORTB<7:3> as OUTPUT , PORTB<2:0> as INPUT
	TRISC = 0b00000000;					// set PORTC as OUTPUT
	TRISD = 0b00000000;					// set PORTD as OUTPUT
	
	ANSELH = 0; 						// SET PORTB as DIGITAL I/O for PIC16F887

	lcd_initialize();					// Initialise LCD

	adc_initialize();					// Initialise ADC

	lcd_home();
	lcd_putstr("Dist:   cm");

while (1)
	{
	unsigned long adc_value = 0;
	unsigned long range_an = 0;
	unsigned long Vout = 0;  
	unsigned char j;
	adc_on();

	for(j = 0 ; j < 100 ; j++)						// take analog result for 20 times
		{
		adc_value = adc_value + ui_adc_read();		
		}
	adc_value = adc_value/100;						// adc_value devide by 100 to get average result
	Vout = (adc_value*500000)/1024;	
					
	if ((Vout > 43945)&&(Vout < 279785))			// read only from 0.4V = 80cm  to 2.8V = 8cm
		{											
		lcd_2ndline();								
		lcd_putstr("            ");
		range_an = (Vout - 19000)/2099;				//	Vout = 20.99*Distance + 0.19;
		lcd_goto(0x05);								
		lcd_bcd(2,1000/range_an);
		}
	else 
		{
		lcd_goto(0x05);
		lcd_putstr("   ");
		lcd_2ndline();
		lcd_putstr("OUT OF RANGE");
		}							
	}	
}
