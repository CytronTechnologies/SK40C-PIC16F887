#ifndef _KEYPAD_H
#define _KEYPAD_H

/*******************************************************************************
* PUBLIC FUNCTION: c_read_keypad
*
* PARAMETERS:
* ~ void
*
* RETURN:
* ~ ASCII code for the pressed key. Return 0 if no key is pressed.
*
* DESCRIPTIONS:
* Read from the keypad.
*
*******************************************************************************/
extern unsigned char keypad_read(void);

/*******************************************************************************
* PUBLIC FUNCTION: c_key_to_ASCII
*
* PARAMETERS:
* ~ unsigned char key_number
*
* RETURN:
* ~ ASCII code for the pressed key.
*
* DESCRIPTIONS:
* Convert the numeric value of key scan to proper ASCII code. Apply only for TB40A onboard 4x4 keypad
*
*******************************************************************************/
extern unsigned char ASCII_value (unsigned char key_number);

/*******************************************************************************
* PUBLIC FUNCTION: c_wait_keypad
*
* PARAMETERS:
* ~ void
*
* RETURN:
* ~ ASCII code for the pressed key.
*
* DESCRIPTIONS:
* Wait until the key is pressed and released.
*
*******************************************************************************/
extern unsigned char keypad_wait(void);

#endif
