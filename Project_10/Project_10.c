//==========================================================================
//	Author				: CYTRON TECHNOLOGIES SDN BHD
//	Project				: SK40C sample code for PIC16F887
//	Project description	: Driving DC brush motor with MD10C
//						  2 mode: (1: Sign-Magnitude PWM)
//								  (2: Locked-Antiphase PWM)
//==========================================================================

//	include
//==========================================================================
#include <htc.h>
#include "lcd.h"
#include "system.h"
#include "pwm.h"

//   Configuration
//==========================================================================
__CONFIG(HS &			// External Crystal at High Speed
		 WDTDIS &		// Disable Watchdog Timer.
		 PWRTEN &		// Enable Power Up Timer.
		 BORDIS &		// Disable Brown Out Reset.
		 MCLREN &		// MCLR function is enabled
		 LVPDIS);		// Disable Low Voltage Programming.

//	function prototype
//==========================================================================
void delay_ms(unsigned int ui_value);
void sign_magnitude_pwm(void);
void locked_antip_pwm(void);
void wait_sw1(void);

//	main function
//==========================================================================
void main(void) 
{	
	PORTA = 0;					
	PORTB = 0;							// Clear Port
	PORTC = 0;
	PORTD = 0;

	TRISA = 0b00000000;					// set PORTA as OUTPUT
	TRISB = 0b00000111;					// set PORTB<7:3> as OUTPUT , PORTB<2:0> as INPUT
	TRISC = 0b00000000;					// set PORTC as OUTPUT
	TRISD = 0b00000000;					// set PORTD as OUTPUT
	
	ANSEL = 0;							// Set PORTA as Digital I/O
	ANSELH = 0; 						// SET PORTB as DIGITAL I/O for PIC16F887

	lcd_initialize();					// Initialise LCD
	pwm_initialize();					// Initialise PWM1
	
unsigned char mode = 1;

while (1)
	{
	switch (mode)
		{					
		case 1: while (SW1 == 1)
					{
					lcd_clear();
					lcd_putstr("Sign-Magnitude\nPWM");
					wait_sw1();
					if(SW1 == 0) break;

					lcd_clear(); 
					lcd_putstr("DIR to RA0\nPWM to RC1");
					wait_sw1();
					if(SW1 == 0) break;

					lcd_clear(); 
					lcd_putstr("Press SW1 when\nReady");
					wait_sw1();
					}
				while (SW1 == 0);
				sign_magnitude_pwm();
				pwm_set_duty_cycle(0);
				break;		
				
		case 2:	DIR = 0;
				while (SW1 == 1)
					{
					lcd_clear();
					lcd_putstr("Locked-Antiphase\nPWM");
					wait_sw1();
					if(SW1 == 0) break;

					lcd_clear(); 
					lcd_putstr("DIR to RC1\nPWM to RA0");
					wait_sw1();
					if(SW1 == 0) break;

					lcd_clear(); 
					lcd_putstr("Press SW1 when\nReady");
					wait_sw1();
					}
				while (SW1 == 0);
				locked_antip_pwm();
				pwm_set_duty_cycle(0);
				DIR = 0;
				break;
		}

	if (++mode > 2) 				// if SW1 is press, increase the mode number until it is max and loop back
		{
		mode = 1;
		}
	}		
}

/*******************************************************************************
* PRIVATE FUNCTION: sign_magnitude_pwm
*
* PARAMETERS:
* ~ void
*
* RETURN:
* ~ void
*
* DESCRIPTIONS:
* MD10C Sign-Magnitude PWM mode
*
*******************************************************************************/
void sign_magnitude_pwm (void)
{
unsigned int speed;	
lcd_clear();
lcd_home();
lcd_putstr("DIR:");
lcd_goto(0x07);
lcd_putstr("PWM:");
lcd_2ndline();
lcd_putstr("Sign-Mag PWM    ");
		
		lcd_goto(0x04);
		lcd_putstr("1");
		DIR = 1;
		for (speed=350 ; speed<1024 ; speed++)
			{
			delay_ms(10);
			pwm_set_duty_cycle(speed);
			lcd_goto(0xB);
			lcd_bcd(4,speed);
			}

		lcd_goto(0x04);
		lcd_putstr("0");
		DIR = 0;
		for (; speed>350 ; speed--)
			{
			delay_ms(10);
			pwm_set_duty_cycle(speed);
			lcd_goto(0xB);
			lcd_bcd(4,speed);
			}		
}
		
/*******************************************************************************
* PRIVATE FUNCTION: locked_antip_pwm
*
* PARAMETERS:
* ~ void
*
* RETURN:
* ~ void
*
* DESCRIPTIONS:
* MD10C Locked Anti-Phase PWM mode
*
*******************************************************************************/
void locked_antip_pwm (void)
{										
unsigned int speed;	
lcd_clear();
lcd_home();
lcd_putstr("DIR:");
lcd_goto(0x07);
lcd_putstr("PWM:");
lcd_2ndline();
lcd_putstr("Locked-Antip PWM");
		

		lcd_goto(0x04);
		lcd_putstr("1");
		DIR = 1;
		for (speed=1024 ; speed>0 ; speed--)
			{
			delay_ms(10);
			pwm_set_duty_cycle(speed);
			lcd_goto(0xB);
			lcd_bcd(4,speed);
			}
}
	

/*******************************************************************************
* PRIVATE FUNCTION: delay_ms
*
* PARAMETERS:
* ~ ui_value	- The period for the delay in miliseconds.
*
* RETURN:
* ~ void
*
* DESCRIPTIONS:
* Delay in miliseconds.
*
*******************************************************************************/
void delay_ms(unsigned int ui_value)
{
	while (ui_value-- > 0) {
		__delay_ms(1);		// macro from HI-TECH compiler which will generate 1ms delay base on value of _XTAL_FREQ in system.h
	}	
}

/*******************************************************************************
* PRIVATE FUNCTION: wait_sw1
*
* PARAMETERS:
* ~ void
*
* RETURN:
* ~ void
*
* DESCRIPTIONS:
* wait for switch 1 to be press while have delay
*
*******************************************************************************/
void wait_sw1(void)
{
	unsigned char i;
	for (i = 0; i < 200; i++) 
		{
			if (SW1 == 0)
			{
				return;
			}	
			delay_ms(10);
		}
}