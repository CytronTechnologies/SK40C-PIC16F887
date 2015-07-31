/*******************************************************************************
* This file provides the functions for the 2x16 LCD display, in 8 bit interface
*
* Author: Chen Kean Tack @ Cytron Technologies Sdn. Bhd.
*******************************************************************************/



#ifndef _LCD_H
#define _LCD_H



/*******************************************************************************
* PUBLIC FUNCTION PROTOTYPES                                                   *
*******************************************************************************/

/*******************************************************************************
* PUBLIC FUNCTION: LCD_init
*
* PARAMETERS:
* ~ void
*
* RETURN:
* ~ void
*
* DESCRIPTIONS:
* Initialize and clear the LCD display.
*
*******************************************************************************/
extern void LCD_init(void);


/*******************************************************************************
* PRIVATE FUNCTION: send_config
*
* PARAMETERS:
* ~ data	
*
* RETURN:
* ~ void
*
* DESCRIPTIONS:
* Send and set the output of the LCD data bus.
*
*******************************************************************************/
extern void send_config(unsigned char data);


/*******************************************************************************
* PUBLIC FUNCTION: LCD_putchar
*
* PARAMETERS:
* ~ c_data	- The character to display.
*
* RETURN:
* ~ void
*
* DESCRIPTIONS:
* Display a character on the LCD.
*
*******************************************************************************/
extern void LCD_putchar(unsigned char data);



/*******************************************************************************
* PUBLIC FUNCTION: E_pulse
*
* PARAMETERS:
* ~ void	
*
* RETURN:
* ~ void
*
* DESCRIPTIONS:
* Execute an E-clock pulse
*
*******************************************************************************/
extern void E_pulse(void);


/*******************************************************************************
* PUBLIC FUNCTION: LCD_goto
*
* PARAMETERS:
* ~ uc_position	- The position that we want to set the cursor at.
*
* RETURN:
* ~ void
*
* DESCRIPTIONS:
* Jump to the defined position of the LCD display.
*
*******************************************************************************/
extern void LCD_goto(unsigned char data);


/*******************************************************************************
* PUBLIC FUNCTION: LCD_clr_home
*
* PARAMETERS:
* ~ void
*
* RETURN:
* ~ void
*
* DESCRIPTIONS:
* Clear the LCD display and return the cursor to the home position.
*
*******************************************************************************/
extern void LCD_clr_home(void);



/*******************************************************************************
* PUBLIC FUNCTION: LCD_putstring
*
* PARAMETERS:
* ~ csz_string	- The null terminated string to display.
*
* RETURN:
* ~ void
*
* DESCRIPTIONS:
* Display a string on the LCD.
*
*******************************************************************************/
extern void LCD_putstring(const char *s);

#endif