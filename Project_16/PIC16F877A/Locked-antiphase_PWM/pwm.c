/*******************************************************************************
* This file provides the functions for the PWM module, using PIC16F877A
*
* Author: Chen Kean Tack @ Cytron Technologies Sdn. Bhd.
*******************************************************************************/



#include <htc.h>
#include "system.h"
#include "pwm.h"



/*******************************************************************************
* PUBLIC FUNCTION: PWM_init
*
* PARAMETERS:
* ~ void
*
* RETURN:
* ~ void
*
* DESCRIPTIONS:
* Initialize the CCP1 module and CCP2 to operate in PWM mode.
*
*******************************************************************************/
void PWM_init(void)
{
	// Setup PWM
	// Setting PWM frequency = 4.88khz
	// using PIC16F887 with 20MHz Crystal

	PR2 = 0xFF;
	T2CKPS1 = 0;
	T2CKPS0 = 1;	// Timer 2 prescale = 4.
	
	SPEEDL = 0;
	SPEEDR = 0;
	TMR2ON = 1;		// Turn on Timer 2.
	
	// Configure CCP1 module to operate in PWM mode.
	CCP1M3 = 1;
	CCP1M2 = 1;		
	// Configure CCP2 module to operate in PWM mode.
	CCP2M3 = 1;
	CCP2M2 = 1;	
}	
	
