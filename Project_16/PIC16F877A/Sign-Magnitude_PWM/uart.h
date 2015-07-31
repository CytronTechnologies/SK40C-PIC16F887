/*******************************************************************************
* This file provides the functions for the UART module using PIC16F877A
*
* Author: Chen Kean Tack @ Cytron Technologies Sdn. Bhd.
*******************************************************************************/


#ifndef _UART_H
#define _UART_H


/*******************************************************************************
* PUBLIC FUNCTION PROTOTYPES                                                   *
*******************************************************************************/

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
extern void UART_init(void);


/*******************************************************************************
* PUBLIC FUNCTION: UART_send
*
* PARAMETERS:
* ~ data		- The data that we want to send.
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
extern void UART_send(unsigned char data);


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
extern unsigned char UART_rec(void);

#endif