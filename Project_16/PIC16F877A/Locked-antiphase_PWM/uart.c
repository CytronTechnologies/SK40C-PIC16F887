/*******************************************************************************
* This file provides the functions for the UART module using PIC16F877A
*
* Author: Chen Kean Tack @ Cytron Technologies Sdn. Bhd.
*******************************************************************************/


#include <htc.h>
#include "system.h"
#include "uart.h"


/*******************************************************************************
* PUBLIC FUNCTION: UART_init
*
* PARAMETERS:
* ~ void
*
* RETURN:
* ~ void
*
* DESCRIPTIONS:
* Initialize the UART module.
*
*******************************************************************************/
void UART_init(void)
{

	//Configure UART
	SPBRG = (_XTAL_FREQ / 16 / UART_BAUD) - 1;	// Configure the baud rate.
	BRGH=1;				//baud rate high speed option
	TXEN=1;				//enable transmission
	TX9 =0;				//8-bit transmission
	RX9 =0;				//8-bit reception	
	CREN=1;				//enable reception
	SPEN=1;				//enable serial port
}


/*******************************************************************************
* PUBLIC FUNCTION: uart_transmit
*
* PARAMETERS:
* ~ uc_data		- The data that we want to transmit.
*
* RETURN:
* ~ void
*
* DESCRIPTIONS:
* This function will transmit one byte of data using UART. This is a blocking
* function, if the transmit buffer is full, we will wait until the
* data in the buffer has been sent out before we move in the new data.
*
*******************************************************************************/
void UART_send(unsigned char data)	//function to send out a byte via uart
{	
	while(TXIF==0);			//wait for previous data to finish send out
	TXREG=data;			//send new data
}


/*******************************************************************************
* PUBLIC FUNCTION: UART_rec
*
* PARAMETERS:
* ~ void
*
* RETURN:
* ~ The data received from the UART.
*
* DESCRIPTIONS:
* This function will receive one byte of data using UART. This is a blocking
* function because if the receive buffer is empty, we will wait until the
* data is received.
*
*******************************************************************************/
unsigned char UART_rec(void)		//function to wait for a byte receive from uart
{
	unsigned char dummy;
	unsigned char byte;
	// If there is overrun error...
	if (OERR == 1) {
	// Clear the flag by disable and enable back the reception.
		CREN = 0;
		CREN = 1;
	}
	else if (FERR == 1) {
		    dummy=RCREG;    	//clear RCREG 
            SPEN=0;            //force FERR clear by clearing SPEN 
            SPEN=1;            //re-set SPEN 
	}
	else
	{
	while(RCIF==0);				//wait for data				
	byte = RCREG;			//return the data received
	}
	return byte;
}