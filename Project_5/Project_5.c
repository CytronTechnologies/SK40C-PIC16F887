//==========================================================================
//	Author				: CYTRON TECHNOLOGIES SDN BHD
//	Project				: SK40C sample code for PIC16F887
//	Project description	: Analog Sensor: Tempreture sensor LM35
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

//	function prototype
//==========================================================================

//	main function
//==========================================================================
void main(void) 
{
	PORTA = 0;				// Clear Port
	PORTB = 0;	
	PORTC = 0;
	PORTD = 0;
	
	TRISA = 0b11111111;		// set PORTA as INPUT
	TRISB = 0b00000011;		// set PORTB<7:2> as OUTPUT . PORTB<1:0> as INPUT
	TRISC = 0b00000000;		// set PORTC as OUTPUT
	TRISD = 0b00000000;		// set PORTD as OUTPUT

	ANSELH = 0; 			// SET PORTB as DIGITAL I/O for PIC16F887

	lcd_initialize();		// Initialise LCD

	adc_initialize();		// Initialise ADC
	
	lcd_home();
	lcd_putstr("Cel:");		// Display C as Celsius
	lcd_goto(0x09);
	lcd_putstr("Kel:");		// Display K as Kelvil
	lcd_2ndline();
	lcd_putstr("Frh:");		// Display F as Fehrenheit
	lcd_goto(0x49);
	lcd_putstr("Rea:");		// Display R as Reaumur

while (1)
	{
	unsigned int adc_value,celsuis,kelvin,fehrenheit,reaumur = 0;
	unsigned char i;
	adc_on();
	for(i = 0 ; i < 10 ; i++)						// Take value for 10 times
		{
		adc_value = adc_value + ui_adc_read();
		}
	
	adc_value = adc_value/10;						// Devide by 10 to get the average result
	celsuis = adc_value/2;							// Devive by 2 to get Celsius
	kelvin = ((celsuis*100)+27315)/100;				// actual formula: Kelvin = Celsius + 273.15	
	fehrenheit = ((celsuis*18)/10)+32;				// 				   Fehrenheit =  Celsuis × 1.8 + 32
	reaumur = (celsuis*8)/10;						// 				   Reaumur =  Celsuis × 0.8
	lcd_goto(0x04);									// refer SK40C_tutorial User manual for detail
	lcd_bcd(3,celsuis);								// Display tempreture
	lcd_goto(0x0D);
	lcd_bcd(3,kelvin);
	lcd_goto(0x44);
	lcd_bcd(3,fehrenheit);
	lcd_goto(0x4D);
	lcd_bcd(3,reaumur);
	__delay_ms(100);
	}
}
