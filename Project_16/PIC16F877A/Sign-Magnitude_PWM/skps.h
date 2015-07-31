/*******************************************************************************
* This file provides the functions for the SKPS for MD10C using PIC16F877A
*
* Author: Chen Kean Tack @ Cytron Technologies Sdn. Bhd.
*******************************************************************************/


#ifndef _SKPS_H
#define _SKPS_H


/*******************************************************************************
* PUBLIC FUNCTION PROTOTYPES                                                   *
*******************************************************************************/


/*******************************************************************************
* PUBLIC FUNCTION: SKPS
*
* PARAMETERS:
* ~ data
*
* RETURN:
* ~ data received from SKPS, the status 
*
* DESCRIPTIONS:
* read button and joystick
*
*******************************************************************************/
extern unsigned char SKPS(unsigned char data);



/*******************************************************************************
* PUBLIC FUNCTION: SKPS_vibrate
*
* PARAMETERS:
* motor, value
*
* RETURN:
* ~ void
*
* DESCRIPTIONS:
* command SKPS to vibrate motor on PS2 controller.
*
*******************************************************************************/
extern void SKPS_vibrate(unsigned char motor, unsigned char value);

#endif
