/*******************************************************************************
* This file provides the functions for the SKPS on PTK40A using PIC16F877A
*
* Cytron Technologies Sdn. Bhd.
*******************************************************************************/



#include <htc.h>
#include "system.h"
#include "skps.h"
#include "uart.h"



/*******************************************************************************
* PUBLIC FUNCTION: uc_skps_status
*
* PARAMETERS:
* ~ uc_data
*
* RETURN:
* ~ data received from SKPS, the status 
*
* DESCRIPTIONS:
* request SKPS button and joystick status
*
*******************************************************************************/
unsigned char uc_skps(unsigned char uc_data)
{
	// send command to request PS2 status
	uart_transmit(uc_data);
	return uc_uart_receive();
}	



/*******************************************************************************
* PUBLIC FUNCTION: skps_vibrate
*
* PARAMETERS:
* uc_motor, uc_value
*
* RETURN:
* ~ void
*
* DESCRIPTIONS:
* command SKPS to vibrate motor on PS2 controller.
*
*******************************************************************************/
void skps_vibrate(unsigned char uc_motor, unsigned char uc_value)
{
	uart_transmit(uc_motor);		//send number of motor, motor 1 or motor 2 to SKPS
	uart_transmit(uc_value);		//send the speed, activate or deactivate command to SKPS	
}	


/*******************************************************************************
* PUBLIC FUNCTION: skps_reset
*
* PARAMETERS:
* ~ void
*
* RETURN:
* ~ void
*
* DESCRIPTIONS:
* reset the SKPS and later release it
*
*******************************************************************************/
void skps_reset(void)
{
	SK_RESET = 1; 			// reset the SKPS
	__delay_ms(10);		// wait for 100 ms
	SK_RESET = 0;			// release reset, SKPS back to normal operation
	__delay_ms(30);	
}	
