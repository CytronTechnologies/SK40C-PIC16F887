//==========================================================================
//	Author				: CYTRON TECHNOLOGIES SDN BHD
//	Project				: SK40C sample code for PIC16F887
//	Project description	: LED Chaser with Press & hold Swtich 1 to increase speed
//						  and release Swtich 1 to decrease speed.	
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
unsigned int delay_period (void);

// Global Variable
//==========================================================================
static unsigned int time = 1000;

//	main function
//==========================================================================
void main(void) 
{
	PORTA = 0;				// clear PORT
	PORTB = 0;				
	PORTC = 0;
	PORTD = 0;

	TRISA = 0b00000000;		// set PORTA as OUTPUT
	TRISB = 0b00000001; 	// set PORTB<7:1> AS OUTPUT , PORTB<0> as INPUT
	TRISC = 0b00000000;		// set PORTC as OUTPUT
	TRISD = 0b00000000;		// set PORTD as OUTPUT
	
	ANSEL = 0;				// SET PORTA as DIgital I/O	for PIC16F887
	ANSELH = 0; 			// SET PORTB as DIGITAL I/O for PIC16F887

	ex_LED1 = 1;				// off external LED1
	ex_LED2 = 1;				// off external LED2
	ex_LED3 = 1;				// off external LED3
	ex_LED4 = 1;				// off external LED4
	ex_LED5 = 1;				// off external LED5
	ex_LED6 = 1;				// off external LED6
		
while(1)
	{
			ex_LED1 = 0;						//External LED 1 ON
			delay_ms(delay_period());			//delay for a short of period (please refer speed() for detail)
			ex_LED1 = 1;						//External LED1 OFF

			ex_LED2 = 0;			
			delay_ms(delay_period());		
			ex_LED2 = 1;			

			ex_LED3 = 0;		
			delay_ms(delay_period());		
			ex_LED3 = 1;			

			ex_LED4 = 0;				
			delay_ms(delay_period());		
			ex_LED4 = 1;			

			ex_LED5 = 0;				
			delay_ms(delay_period());		
			ex_LED5 = 1;			

			ex_LED6 = 0;			
			delay_ms(delay_period());		
			ex_LED6 = 1;				
	}
}

/*******************************************************************************
* PRIVATE FUNCTION: delay_period
*
* PARAMETERS:
* ~ void
*
* RETURN:
* ~ unsigned integer
*
* DESCRIPTIONS:
* The delay period of the LED blinking.
*
*******************************************************************************/
unsigned int delay_period (void)				// Read speed function
{
if (time > 150)									// if time are more than 150
	{
	if (SW1 == 0)								// check if Switch 1 is press and hold
		{							
		time = time - 100;						// if Switch 1 is press and hold, decrease the time by 100
			if (time < 50)						// cheeck if time is less then 50, if yes then assign time = 100;
				{						
				time = 100;
				return time;					// return value to delay_period()
				}		
		return time;							// return value to delay_period()
		}							
	}
	time = time + 100;							// if Switch 1 is RELEASE , time is increase by 100	
	if (time > 1000) time = 1000;				// if time is more then 1000 then assign time = 1000	
	return time;
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