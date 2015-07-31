/*******************************************************************************
* This file provides the functions for the SKPS using PIC16F877A
*
* Author: Chen Kean Tack @ Cytron Technologies Sdn. Bhd.
*******************************************************************************/



#include <htc.h>
#include "system.h"
#include "skps.h"
#include "uart.h"


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
unsigned char SKPS(unsigned char data)	
{
	UART_send(data);		//information on ps controller
	return UART_rec();
}	



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
void SKPS_vibrate(unsigned char motor, unsigned char value)
{
	UART_send(motor);		//send number of motor, motor 1 or motor 2 to SKPS
	UART_send(value);		//send the speed, activate or deactivate command to SKPS	
}




