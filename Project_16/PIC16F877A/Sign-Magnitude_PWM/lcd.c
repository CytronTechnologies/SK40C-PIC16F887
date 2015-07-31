/*******************************************************************************
* This file provides the functions for the 2x16 LCD display, in 8 bit interface
*
* Author: Chen Kean Tack @ Cytron Technologies Sdn. Bhd.
*******************************************************************************/



#include <htc.h>
#include "system.h"
#include "lcd.h"



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
void LCD_init(void)
{
//configure lcd
send_config(0b00000001);			//clear display at lcd
send_config(0b00000010);			//lcd return to home 
send_config(0b00000110);			//entry mode-cursor increase 1
send_config(0b00001100);			//display on, cursor off and cursor blink off
send_config(0b00111000);			//function set
}


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
void send_config(unsigned char data)
{
	LCD_RS=0;						//clear rs into config mode 
	LCD_data=data;
	__delay_ms(3);
	E_pulse();
}

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
void LCD_putchar(unsigned char data)
{
	LCD_RS=1;						//set rs into write mode
	LCD_data=data;						 
	__delay_ms(3);
	E_pulse();
}


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
void E_pulse(void)
{
	LCD_EN=1;
	__delay_ms(3);
	LCD_EN=0;
	__delay_ms(3);
}

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

void LCD_goto(unsigned char data)
{
 	if(data<16)
	{
	 	send_config(0x80+data);
	}
	else
	{
	 	data=data-20;
		send_config(0xc0+data);
	}
}

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
void LCD_clr_home(void)
{
 	send_config(0x01);
	send_config(0x02);
}

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
void LCD_putstring(const char *s)
{          
	unsigned char i=0;
  	while (s && *s)LCD_putchar (*s++);
}