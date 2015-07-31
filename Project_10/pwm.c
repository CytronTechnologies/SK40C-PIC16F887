/*******************************************************************************
* This file provides the functions for the PWM module using PIC16F887 using timer2 and
* CCP2CON as pwm
*
* Cytron Technologies Sdn. Bhd.
*******************************************************************************/



#include <htc.h>
#include "system.h"
#include "pwm.h"



/*******************************************************************************
* PUBLIC FUNCTION: pwm_initialize
*
* PARAMETERS:
* ~ void
*
* RETURN:
* ~ void
*
* DESCRIPTIONS:
* Initialize the CCP2 module to operate in PWM mode.
*
*******************************************************************************/
void pwm_initialize(void)
{
	// Setting PWM frequency = 4.88khz, using PIC16F887 with 20MHz Crystal
	PR2 = 0xFF;

	T2CKPS1 = 0;
	T2CKPS0 = 1;	// Timer 2 prescale = 4.
	
	TMR2ON = 1;		// Turn on Timer 2.

	CCP2M3 = 1;
	CCP2M2 = 1;		// Configure CCP2 module to operate in PWM mode.
	CCP2M1 = 0;
	CCP2M0 = 0;	

	CCPR2L = 0x00;	
}	



/*******************************************************************************
* PUBLIC FUNCTION: pwm_set_duty_cycle
*
* PARAMETERS:
* ~ ui_duty_cycle	- The duty cycle of the PWM, 10 bits.
*
* RETURN:
* ~ void
*
* DESCRIPTIONS:
* Set the duty cycle of the PWM.
*
*******************************************************************************/
void pwm_set_duty_cycle(unsigned int ui_duty_cycle)
{
	CCP2CON = (CCP2CON & 0b00001111) | (0b00110000 & ((unsigned char)(ui_duty_cycle << 4)));
	CCPR2L = ui_duty_cycle >> 2;
}	

	
