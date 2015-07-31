//==========================================================================
//	Author				: CYTRON TECHNOLOGIES SDN BHD
//	Project				: SK40C sample code for PIC16F887
//	Project description	: Analog Sensor: Potentiometer & PS2 Joystick & display on LCD	
//==========================================================================

//	include
//==========================================================================
#include <htc.h>
#include "lcd.h"
#include "adc.h"
#include "system.h"

//	global variable
//===========================================================================
void delay_ms(unsigned int ui_value);

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
	TRISC = 0b00000000;
	TRISD = 0b00000000;								// set PORTD as output

	ANS2 = 0;										// RA2 as DIGITAL I/O
	ANSELH = 0; 									// set PORTB as DIGITAL I/O for PIC16F887

	lcd_initialize();								// Initialise LCD

	adc_initialize();								// Initialise ADC

	unsigned char mode = 1;

while (1)											// Loop forever
	{
	switch(mode)
		{
	case 1:	lcd_clear();
			lcd_home();
			lcd_putstr("POTENTIALMETER");
			delay_ms(1000);
			if (SW1 == 1)
				{
				lcd_clear();
				lcd_home();
				lcd_putstr("ADC :");								// Put "ADC:" on LDC screen
				lcd_2ndline();
				lcd_putstr("VOLT: .  V");							// Put "VOLT:   V" on LDC screen
				while (SW1 == 1)
					{
					unsigned int adc_value = 0;
					unsigned int volt_value = 0;
					unsigned char i;
					CHS2 = 0;										// select ADC channel AN0 	
					CHS1 = 0;					
					CHS0 = 0;

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


	case 2:	lcd_clear();
			lcd_home();
			lcd_putstr("JOYSTICK       ");
			delay_ms(1000);
			if (SW1 == 1)
				{
				lcd_clear();
				lcd_home();
				lcd_putstr("X-A:     SW:  ");							// Put "X-A:" on LDC screen
				lcd_2ndline();
				lcd_putstr("Y-A:          ");							// Put "Y-A:" on LDC screen
				while(SW1 == 1)
					{
					unsigned int adc_value_x = 0;
					unsigned int adc_value_y = 0;	
					unsigned char i;
			
					CHS2 = 0;											// select ADC channel AN1
					CHS1 = 0;					
					CHS0 = 1;
					adc_on();											// ON ADC
					for(i = 0 ; i < 10 ; i++)
						{
						adc_value_x = adc_value_x + ui_adc_read();		// take the value for 10 times
						}
			
					adc_value_x = adc_value_x/10;						// Devide the final value by 10 to get the average result
					lcd_goto(0x04);
					lcd_bcd(4,adc_value_x);								// display on LCD with 4 digit BCD number.

					CHS2 = 1;											// select ADC channel AN4
					CHS1 = 0;					
					CHS0 = 0;
					adc_on();											// ON ADC
					for(i = 0 ; i < 10 ; i++)
						{
						adc_value_y = adc_value_y + ui_adc_read();		// take the value for 10 times
						}
	
					adc_value_y = adc_value_y/10;						// Devide the final value by 10 to get the average result
					lcd_goto(0x44);
					lcd_bcd(4,adc_value_y);								// display on LCD with 4 digit BCDnumber.

					if(JY_SW == 1)										// check switch on joystick is press or not.
						{
						lcd_goto(0x0C);
						lcd_putstr("1");								// If not press, display 1
						}
					else 
						{
						lcd_goto(0x0C);
						lcd_putstr("0");								// If not press, display 0
						}
					}	
				}


	while (SW1 == 0);					// wait SW1 to release
		if (++mode > 1) 				// if SW1 is press, increase the mode number until it is max and loop back
			{
			mode = 1;
			}	
		
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
