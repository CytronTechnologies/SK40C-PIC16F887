//==========================================================================
//	Author				: CYTRON TECHNOLOGIES SDN BHD
//	Project				: SK40C sample code for PIC16F887
//	Project description	: Piezo buzzer: Melody - Birthday Song
//==========================================================================

//	include
//==========================================================================
#include <htc.h>
#include "system.h"
#include "pwm.h"

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
void tone_out(unsigned char tone , unsigned int delay);

//	main function
//==========================================================================
void main(void) 
{	
	PORTA = 0;							// Clear Port
	PORTB = 0;							
	PORTC = 0;
	PORTD = 0;

	TRISA = 0b00000000;					// set PORTA as OUTPUT
	TRISB = 0b00000011;					// set PORTB<7:2> as OUTPUT , PORTB<1:0> as INPUT
	TRISC = 0b00000000;					// set PORTC as OUTPUT
	TRISD = 0b00000000;					// set PORTD as OUTPUT
	
	ANSEL = 0;							// SET PORTA as DIGITAL I/O for PIC16F887
	ANSELH = 0; 						// SET PORTB as DIGITAL I/O for PIC16F887

	pwm_initialize();

unsigned char wait = 0;
unsigned int birthday[] = {C4_1,C4,D4,C4,F4,E4,C4_1,C4,D4,C4,G4,F4,C4_1,C4,C5,A4,F4,E4,D4,B4b,B4b,A4,F4,G4,F4};
unsigned int delay_period[] = {1,1,2,2,2,3,1,1,2,2,2,3,1,1,2,2,2,2,3,1,1,2,2,2,3};
while (1)
	{
		for (wait=0 ; wait<25 ; wait++)				// loop for 25 times while increase "wait"
		{
		PR2 = (birthday[wait]/2);					// generate PWM period (refer data sheet for detail)
		tone_out(birthday[wait],delay_period[wait]*20000);
		}
	}	
}

/*******************************************************************************
* PRIVATE FUNCTION: tone_out
*
* PARAMETERS:
* ~ void
*
* RETURN:
* ~ unsigned char tone - pwm duty cycle
* ~ unsigned int delay - the delay of the tone 
*
* DESCRIPTIONS:
* generate the pwm duty cycle and delay the tone for period of time
*
*******************************************************************************/
void tone_out(unsigned char tone , unsigned int delay)
{
	while(delay-- > 0)
	{
		pwm_set_duty_cycle(tone);					// generate PWM pulse width
	}							
}

/*
Happy   birthday to  you
C4  C4  D4   C4  F4 E4

Happy   birthday  to you
C4  C4  D4   C4  G4 F4

Happy birthday dear xxxx
C4 C4 C5   A4  F4    E4 D4

Happy     birthday to  you $$$.
B4b B4b  A4  F4  G4 F4
*/