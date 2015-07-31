/*******************************************************************************
* This file provides the functions for the UART module on PTK40A using PIC16F887A
*
* Cytron Technologies Sdn. Bhd.
*******************************************************************************/



#ifndef _UART_H
#define _UART_H



/*******************************************************************************
* PUBLIC FUNCTION PROTOTYPES                                                   *
*******************************************************************************/

/*******************************************************************************
* PUBLIC FUNCTION: uart_initialize
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
extern void uart_initialize(void);



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
extern void uart_transmit(unsigned char uc_data);



/*******************************************************************************
* PUBLIC FUNCTION: uc_uart_receive
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
extern unsigned char uc_uart_receive(void);



/*******************************************************************************
* PUBLIC FUNCTION: uart_putstr
*
* PARAMETERS:
* ~ csz_string	- The null terminated string to transmit.
*
* RETURN:
* ~ void
*
* DESCRIPTIONS:
* Transmit a string using the UART.
*
*******************************************************************************/
extern void uart_putstr(const char* csz_string);



#endif
