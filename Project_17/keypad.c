#include <htc.h>
#include "system.h"
#include "keypad.h"

/*******************************************************************************
* PUBLIC FUNCTION: c_read_keypad
*
* PARAMETERS:
* ~ void
*
* RETURN:
* ~ numeric value for the pressed key. Return 0xFF if no key is pressed.
*
* DESCRIPTIONS:
* Read from the keypad.
*
*******************************************************************************/
unsigned char keypad_read(void)
{
	//start the scanning process
	KP_R1 = 0;		// scan keypress on 1st row: 1, 2, 3, A
	KP_R2 = 1;
	KP_R3 = 1;
	KP_R4 = 1;
	__delay_us(30);
	if (KP_C1 == 0)	return '1';		// Key '1' is pressed
	if (KP_C2 == 0) return '2';		// Key '2' is pressed
	if (KP_C3 == 0) return '3';		// Key '3' is pressed
	if (KP_C4 == 0) return 'A';		// Key 'A' is pressed, we will store as 10

	KP_R1 = 1;		// scan keypress on 2nd row: 4, 5, 6, B
	KP_R2 = 0;
	KP_R3 = 1;
	KP_R4 = 1;
	__delay_us(30);
	if (KP_C1 == 0)	return '4';		// Key '4' is pressed
	if (KP_C2 == 0) return '5';		// Key '5' is pressed
	if (KP_C3 == 0) return '6';		// Key '6' is pressed
	if (KP_C4 == 0) return 'B';		// Key 'B' is pressed, we will store as 11

	KP_R1 = 1;		// scan keypress on 3rd row: 7, 8, 9, C
	KP_R2 = 1;
	KP_R3 = 0;
	KP_R4 = 1;
	__delay_us(30);
	if (KP_C1 == 0)	return '7';		// Key '7' is pressed
	if (KP_C2 == 0) return '8';		// Key '8' is pressed
	if (KP_C3 == 0) return '9';		// Key '9' is pressed
	if (KP_C4 == 0) return 'C';		// Key 'C' is pressed, we will store as 12

	KP_R1 = 1;		// scan keypress on 4th row: *, 0, #, D
	KP_R2 = 1;
	KP_R3 = 1;
	KP_R4 = 0;
	__delay_us(30);
	if (KP_C1 == 0)	return '*';		// Key '*' is pressed, we will store as 14
	if (KP_C2 == 0) return '0';		// Key '0' is pressed
	if (KP_C3 == 0) return '#';		// Key '#' is pressed, we will store as 15
	if (KP_C4 == 0) return 'D';		// Key 'D' is pressed, we will store as 13

	return 0xFF;					// if no key press, the register is 0xFF
}

/*******************************************************************************
* PUBLIC FUNCTION: c_wait_keypad
*
* PARAMETERS:
* ~ void
*
* RETURN:
* ~ numeric value for the pressed key.
*
* DESCRIPTIONS:
* Wait until the key is pressed and released.
*
*******************************************************************************/
unsigned char keypad_wait(void)
{
	// The pressed key.
	unsigned char c_pressed_key = 0xFF;	
	
	// Wait until the key is pressed.
	do {
		c_pressed_key = keypad_read();
	}	
	while (c_pressed_key == 0xFF);
	
	// Wait until the key is released.
	while (keypad_read() != 0xFF);
	
	return c_pressed_key;
}	