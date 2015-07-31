/*******************************************************************************
* This file provides the functions for the PWM module, using PIC16F887
*
* Author: Chen Kean Tack @ Cytron Technologies Sdn. Bhd.
*******************************************************************************/



#ifndef _PWM_H
#define _PWM_H



/*******************************************************************************
* PUBLIC FUNCTION PROTOTYPES                                                   *
*******************************************************************************/


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
extern void PWM_init(void);


#endif
