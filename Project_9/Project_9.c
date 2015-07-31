//==========================================================================
//	Author				: CYTRON TECHNOLOGIES SDN BHD
//	Project				: SK40C sample code for PIC16F887
//	Project description	: Analog Sensor: Light detection using LDR
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

//	main function
//==========================================================================
void main(void) 
{
	PORTA = 0;										// clear PORT
	PORTB = 0;		
	PORTC = 0;								
	PORTD = 0;										
	
	TRISA = 0b11111111;								// set PORTA as INPUT
	TRISB = 0b00000011; 							// set PORTB<7:2> AS OUTPUT , PORTB<1:0> as INPUT
	TRISC = 0b00000000;								// set PORTC as output
	TRISD = 0b00000000;								// set PORTD as output

	ANSELH = 0; 									// SET PORTB as DIGITAL I/O for PIC16F887

	lcd_initialize();								// Initialise LCD

	adc_initialize();								// Initialise ADC
	
	lcd_home();
	lcd_putstr("ADC :");							// Put "ADC:" on LDC screen
	lcd_2ndline();
	lcd_putstr("VOLT: .  V");						// Put "VOLT:" on LDC screen

while (1)											// Loop forever
	{
	unsigned int adc_value = 0;
	unsigned int volt_value = 0;
	unsigned char i;

	adc_on();										// ON ADC
	for(i = 0 ; i < 10 ; i++)
		{
		adc_value = adc_value + ui_adc_read();		// take the value for 10 times
		}
	
	adc_value = adc_value/10;						// Devide the final value by 10 to get the average result
	lcd_goto(0x05);
	lcd_bcd(4,adc_value);							// display on LCD with 4 digit number maximun.
	volt_value = (adc_value*50)/102.4;				// if adc_value = 1022.
	lcd_goto(0x45);									// volt_value = (1022*50)/1024 = 499
	lcd_bcd(1,volt_value/100);						// volt_value  = 499/100 = 4 (1st number)
	lcd_goto(0x47);										
	lcd_bcd(1,(volt_value%100)/10); 				// (volt_value = 499%100 = 99). 99/10 = 9(2nd number)
	lcd_bcd(1,volt_value%10);						// (volt_value = 499%100 = 99). 99%10 = 9(last number)		
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
