//==========================================================================
//	Author				: CYTRON TECHNOLOGIES SDN BHD
//	Project				: SK40C sample code for PIC16F887
//	Project description	: Interface with SKPS
//==========================================================================

//	include
//==========================================================================
#include <htc.h>
#include "lcd.h"
#include "system.h"
#include "uart.h"
#include "skps.h"

//   Configuration
//==========================================================================
__CONFIG(HS &			// External Crystal at High Speed
		 WDTDIS &		// Disable Watchdog Timer.
		 PWRTEN &		// Enable Power Up Timer.
		 BORDIS &		// Disable Brown Out Reset.
		 MCLREN &		// MCLR function is enabled
		 LVPDIS);		// Disable Low Voltage Programming.

//	global variable
//===========================================================================
static unsigned int case_num = 0;

//	function prototype
//==========================================================================
void display (void);
void delay_ms(unsigned int ui_value);

//	main function
//==========================================================================
void main(void) 
{
	PORTA = 0;										// Clear Port
	PORTB = 0;
	PORTC = 0;
	PORTD = 0;

	TRISA = 0b00000000;								// set PORTA as INPUT
	TRISB = 0b00000011;								// set PORTB<7:2> as OUTPUT , PORTB<1:0> as INPUT
	TRISC = 0b10000000;								// Set PORTC<7> as INPUT , PORTC<6:0> as OUTPUT
	TRISD = 0b00000000;								// set PORTD as output
		
	ANSELH = 0; 									// SET PORTB as DIGITAL I/O for PIC16F887

	lcd_initialize();								// Initialise LCD

	uart_initialize();								// Initialise UART

while (p_con_status)								// loop forever if PS2 controller is Connected to SKPS
	{
	unsigned char no = 0;
	unsigned int data[4] = { 0 };

	for(no=0 ; no<16 ; no++)						// loop from 0 to 16 decimal
		{
		uc_skps(no);								// check the skps 
		case_num = no;								// save 'no' at 'case_num' for case swtching 
		if (RCREG == 0)								// if SKPS is detected a button pressed on PS2
			{
			display();								// display text on LCD
			no = 0;									// reset 'no' back to 0
			}
		}


	if (uc_skps(p_joy_lu) | uc_skps(p_joy_ld) | uc_skps(p_joy_ll) | uc_skps(p_joy_lr))			// if PS2 LEFT joystick is detected
		{
		case_num = 16;																			// set to case 16
		display();																				// Display case 16
		while (uc_skps(p_joy_lu) | uc_skps(p_joy_ld) | uc_skps(p_joy_ll) | uc_skps(p_joy_lr))	// loop forever if LEFT joystick still detected
			{	
			uc_skps(p_joy_lu);
			data[0] = RCREG;																	// save value at data[]
			uc_skps(p_joy_ld);
			data[1] = RCREG;
			uc_skps(p_joy_ll);
			data[2] = RCREG;
			uc_skps(p_joy_lr);
			data[3] = RCREG;
			lcd_goto(0x05);											
			lcd_bcd(3,data[0]);																	// Display data[] on LCD
			lcd_goto(0x0D);
			lcd_bcd(3,data[1]);
			lcd_goto(0x45);
			lcd_bcd(3,data[2]);
			lcd_goto(0x4D);
			lcd_bcd(3,data[3]);
			skps_vibrate (p_motor2,200);														// send command to vibrate left motor				
			}
		}
	else 
		{
		lcd_clear();																			// lcd clear
		skps_vibrate(p_motor2, 0);																// stop motor	
		}


	if (uc_skps(p_joy_ru) | uc_skps(p_joy_rd) | uc_skps(p_joy_rl) | uc_skps(p_joy_rr))			// if PS2 RIGHT joystick is detected
		{
		case_num = 17;																			// set to case 17
		display();																				// Display case 17
		while (uc_skps(p_joy_ru) | uc_skps(p_joy_rd) | uc_skps(p_joy_rl) | uc_skps(p_joy_rr))	// loop forever if RIGHT joystick still detected
			{
			uc_skps(p_joy_ru);
			data[0] = RCREG;
			uc_skps(p_joy_rd);
			data[1] = RCREG;
			uc_skps(p_joy_rl);
			data[2] = RCREG;
			uc_skps(p_joy_rr);
			data[3] = RCREG;
			lcd_goto(0x05);
			lcd_bcd(3,data[0]);
			lcd_goto(0x0D);
			lcd_bcd(3,data[1]);
			lcd_goto(0x45);
			lcd_bcd(3,data[2]);
			lcd_goto(0x4D);
			lcd_bcd(3,data[3]);
			skps_vibrate (p_motor1, 1);															// send command to vibrate right motor
			}
		}
	else 
		{
		lcd_clear();
		skps_vibrate(p_motor1, 0);																// stop motor
		}
	}
}		

/*******************************************************************************
* PRIVATE FUNCTION: display
*
* PARAMETERS:
* ~ void
*
* RETURN:
* ~ void
*
* DESCRIPTIONS:
* Display ASCII on LCD.
*
*******************************************************************************/
void display (void)
{
switch (case_num)
	{
	case 0:	lcd_home();
			lcd_putstr("p_select        ");
			break;

	case 1:	lcd_home();
			lcd_putstr("p_joyl          ");
			break;

	case 2:	lcd_home();
			lcd_putstr("p_joyr          ");
			break;

	case 3: lcd_home();
			lcd_putstr("p_start         ");
			break;

	case 4: lcd_home();
			lcd_putstr("p_up            ");
			break;

	case 5: lcd_home();
			lcd_putstr("p_right         ");
			break;

	case 6: lcd_home();
			lcd_putstr("p_down          ");
			break;

	case 7: lcd_home();
			lcd_putstr("p_left          ");
			break;

	case 8: lcd_home();
			lcd_putstr("p_l2            ");
			break;

	case 9: lcd_home();
			lcd_putstr("p_r2            ");
			break;

	case 10: lcd_home();
			lcd_putstr("p_l1            ");
			break;

	case 11: lcd_home();
			lcd_putstr("p_r1            ");
			break;

	case 12: lcd_home();
			lcd_putstr("p_triangle      ");
			break;

	case 13: lcd_home();
			lcd_putstr("p_circle        ");
			break;

	case 14: lcd_home();
			lcd_putstr("p_cross         ");
			break;

	case 15: lcd_home();
			lcd_putstr("p_square        ");
			break;

	case 16: lcd_home();
			lcd_putstr("J_LU:   J_LD:   ");
			lcd_2ndline();
			lcd_putstr("J_LL:   J_LR:   ");
			break;

	case 17: lcd_home();
			lcd_putstr("J_RU:   J_RD:   ");
			lcd_2ndline();
			lcd_putstr("J_RL:   J_RR:   ");
			break;
	}
}
 