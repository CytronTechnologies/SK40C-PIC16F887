//
//	Author					: Chen Kean Tack
//	Project					: SK40C + MD10C + SKPS
//	Project description		: Interface SK40C with MD10C to control 2 DC motor with SKPS
//							  in Sign-magnitude mode using PIC16F877A
//	Compiler				: MPLAB IDE V8.85 (HI-TECH C Compiler V9.70)
//	Notes					: This sample source code is valid for 20MHz Crystal
//
//	Connection Summary:
//	RC0-connected to DIR of right motor 
//	RC1-connected to PWM of right motor
//	RC2-connected to PWM of left motor
//	RC3-connected to DIR of left motor
//==============================================================================================

//	include
//==============================================================================================
#include <htc.h> 
#include "system.h"		//include system header file for SK40C
#include "uart.h"		//include uart functions header file
#include "pwm.h"		//include pwm functions header file
#include "lcd.h"		//include lcd functions header file
#include "skps.h"		//include skps functions header file

/*******************************************************************************
* DEVICE CONFIGURATION WORDS                                                   *
*******************************************************************************/
//if Hi-Tech V9.70-V9.80 compiler is being used, open this device configuration words
__CONFIG(HS &			// High Speed Crystal.
		 WDTDIS &		// Disable Watchdog Timer.
		 PWRTEN &		// Enable Power Up Timer.
		 BORDIS &		// Disable Brown Out Reset.
		 LVPDIS);		// Disable Low Voltage Programming.

//if Hi-Tech V9.81-V9.83 compiler is being used, open this device configuration words
/*__CONFIG(FOSC_HS &	// High Speed Crystal.
		 WDTE_OFF &		// Disable Watchdog Timer.
		 PWRTE_ON &		// Enable Power Up Timer.
		 BOREN_OFF &	// Disable Brown Out Reset.
		 LVP_OFF);		// Disable Low Voltage Programming.
*/


//	function prototype
//===========================================================================================
void delay(unsigned long data);


//	main function
//===========================================================================================
void main(void)
{
	unsigned char up_v, down_v, left_v, right_v;
	
	//set I/O input output
	TRISB = 0b00000011;					//configure PORTB I/O direction
	TRISC = 0b10000000;					//configure PORTC I/O direction
	TRISD = 0b00000000;					//configure PORTD I/O direction

	//setup ADC
	ADCON1 = 0b00000110;				//set ADx pin digital I/O

	LCD_init();							// initialize LCD
	PWM_init();							// initialize PWM
	UART_init();						// initialize UART

	LED1=0;
	LED2=0;								// turn off LED

	//display startup message	
	LCD_clr_home();						// clear LCD
	LCD_goto(2);						// set the lcd cursor to location 2
	LCD_putstring("MD10C Demo");	
	LCD_goto(20);						// set the lcd cursor to second row
	LCD_putstring("SK40C PR16");
	delay(100000);	
	LCD_clr_home();						// clear LCD				
	LCD_putstring("Press Start");
	LCD_goto(20);
	LCD_putstring("To begin.");
	delay(50000);
	while(SKPS(p_start)==1) continue;
	LCD_clr_home();

	while(1)
	{	
		//read joy stick value process		
		up_v=SKPS(p_joy_ru);
		down_v=SKPS(p_joy_rd);
		left_v=SKPS(p_joy_ll);
		right_v=SKPS(p_joy_lr);

		//constant speed control motor
		if(SKPS(p_up)==0)				// check "up" button
		{
			LCD_goto(20);					 
			LCD_putstring("Move forward!   ");	
			MD10C_L_DIR=0;
			MD10C_R_DIR=0;				// set both motors in same direction
			SPEEDL=220;			
			SPEEDR=220;					// set constant speed for both motors
		}
		else if(SKPS(p_down)==0)		// check "down" button
		{	
			LCD_goto(20);					 
			LCD_putstring("Move Backward!  ");		 
			MD10C_L_DIR=1;
			MD10C_R_DIR=1;				// set both motors in same direction
			SPEEDL=220;
			SPEEDR=220;					// set constant speed for both motors
		}
		else if(SKPS(p_left)==0)		// check "left" button
		{
			LCD_goto(20);				
			LCD_putstring("Rotate to left! ");		 
			MD10C_L_DIR=1;
			MD10C_R_DIR=0;				// set both motors in different direction
			SPEEDL=220;
			SPEEDR=220;					// set constant speed for both motors
		}
		else if(SKPS(p_right)==0)		// check "right" button
		{
			LCD_goto(20);					 
			LCD_putstring("Rotate to right!");	 
			MD10C_L_DIR=0;
			MD10C_R_DIR=1;				// set both motors in different direction
			SPEEDL=220;
			SPEEDR=220;					// set constant speed for both motors
		}

		//analog control for mobility		
		else if(up_v>0)
		{
			LCD_goto(20);					
			LCD_putstring("Move Forward!   ");	
			MD10C_L_DIR=0;
			MD10C_R_DIR=0;				// set both motors in same direction
			if(left_v>0)
			{
				if(up_v>left_v)SPEEDL=up_v-left_v+140;
				else SPEEDL=140;
				SPEEDR=up_v+140;		
			}
			else if(right_v>0)
			{
				if(up_v>right_v)SPEEDR=up_v-right_v+140;
				else SPEEDR=140;
				SPEEDL=up_v+140;
			}
			else
			{
				SPEEDL=up_v+140;
				SPEEDR=up_v+140;
			}
		}
		else if(down_v>0)
		{
			LCD_goto(20);					 
			LCD_putstring("Move Backward!   ");	
			MD10C_L_DIR=1;
			MD10C_R_DIR=1;				// set both motors in same direction
			if(left_v>0)
			{
				if(down_v>left_v)SPEEDR=down_v-left_v+140;
				else SPEEDR=140;
				SPEEDL=down_v+140;		
			}
			else if(right_v>0)
			{
				if(down_v>right_v)SPEEDL=down_v-right_v+140;
				else SPEEDL=140;
				SPEEDR=down_v+140;
			}
			else
			{
				SPEEDL=down_v+140;
				SPEEDR=down_v+140;
			}
		}
		else if(left_v>0)
		{
			LCD_goto(20);					 
			LCD_putstring("Rotate to left! ");	 
			MD10C_L_DIR=1;
			MD10C_R_DIR=0;				// set both motors in different direction
			SPEEDL=left_v+120;
			SPEEDR=left_v+120;	
		}
		else if(right_v>0)
		{
			LCD_goto(20);					 	
			LCD_putstring("Rotate to right!");	 
			MD10C_L_DIR=0;
			MD10C_R_DIR=1;				// set both motors in different direction
			SPEEDL=right_v+120;
			SPEEDR=right_v+120;	
		}

		else  
		{
			LCD_goto(0);
			LCD_putstring("Motor State:    ");
			LCD_goto(20);
			LCD_putstring("Stop!           ");
			SPEEDL=0;
			SPEEDR=0;					// set duty cycle 0% for both motors
		}
	
	}while(1) continue;
}

// Simple delay function
//=============================================================================================
void delay(unsigned long data)
{
	for( ;data>0;data-=1);
}

