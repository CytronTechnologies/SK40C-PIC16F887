//==========================================================================
//	Author				: CYTRON TECHNOLOGIES SDN BHD
//	Project				: SK40C sample code for PIC16F887
//	Project description	: Analog Sensor: Range using Ultrasonic Range Finder
//						  3 mode : (1: Analog)
//								   (2: PWM   )
//								   (3: UART  )
//==========================================================================

//	include
//==========================================================================
#include <htc.h>
#include "lcd.h"
#include "adc.h"
#include "system.h"
#include "uart.h"

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
unsigned int To=0,T=0,TH=0;
unsigned char data[6] = {0};

//  Interrrupt Subroutine
//============================================================================
static void interrupt isr(void)
{
	if (T0IF)								// TMR0 is overflow
	{
		T0IF = 0; 							// clear flag bit
		To +=0x100;							// count number of TMR0 overflow ( make it to 16bit TMR)
	}
		
	if(RBIF)								// there is change bit on RB4-RB7
	{
		RBIF = 0;							//	                                 		 ____
		if (PWM_IN)							// PWM_IN(RB2) is 1 mean is rising form 0  __|         
		{
			TMR0 = 0;						// clear all counter involved, start new count for period of RB4 high
			To = 0;
		}
											//											___
		else TH = TMR0 + To;				// PWM_IN(RB2) is 0 mean is falling form 1 	   |_____  // save TH, RB4 high period
	}
}

//	main function
//==========================================================================
void main(void) 
{
unsigned char mode = 1;
	PORTA = 0;							// Clear Port
	PORTB = 0;
	PORTC = 0;
	PORTD = 0;

	
	TRISA = 0b11111111;					// set PORTA as INPUT
	TRISB = 0b00000111;					// set PORTB<7:3> as OUTPUT , PORTB<2:0> as INPUT
	TRISC = 0b10000000;
	TRISD = 0b00000000;					// set PORTD as output
	

	ANSELH = 0; 						// SET PORTB as DIGITAL I/O for PIC16F887
	WPUB = 1;							// PORTB Weak Pull Up enable

	// Interupt on change
	IOCB0 = 0;				 
	IOCB1 = 0;
	IOCB2 = 1;							// when PORTB.2 detect change will interrupt
	IOCB3 = 0;
	IOCB4 = 0;
	IOCB5 = 0;
	IOCB6 = 0;
	IOCB7 = 0;

	RBIE = 1;							// PORTB Change Interrupt Enable bit	


	// TMR 0 configuation
	T0CS = 0;						
	PSA = 0;						
	PS2 = 1;							// prescale 1:256
	PS1 = 1;						
	PS0 = 1;						
	T0IE = 1;							// TMR0 Interrupt
	TMR0 = 0;
	
	GIE = 1;							// Global Intterupt enable
	PEIE = 1;							// Peripheral Interrupt enable

	lcd_initialize();					// Initialise LCD

	adc_initialize();					// Initialise ADC

	uart_initialize();					// Initialise UART

	TX == 1;							// ON Transmit pin (refer Maxbotix EZ1 Ultrasonic datasheet)

	lcd_home();
	lcd_putstr("Dist:");
	lcd_goto(0x0B);
	lcd_putstr("inch");

while (1)
	{
	switch(mode)
		{
	case 1:			lcd_2ndline();
					lcd_putstr("Analog");
					while (SW1 == 1)
						{
						unsigned int adc_value = 0;
						unsigned int range_an = 0;  
						unsigned char j;
						adc_on();
						for(j = 0 ; j < 10 ; j++)						// take analog result for 20 times
							{
							adc_value = adc_value + ui_adc_read();		
							}
	
						adc_value = adc_value/10;						// adc_value devide by 10 to get average result
						range_an = adc_value/2;							// max vslue adc_value = 2.55/5 *1024 - 1 =  522
						lcd_goto(0x05);									// max is 254 inch... 522/254 = ~2
				 		lcd_bcd(3,range_an);							// (1 to 6 inch) is readed as 6 inch (refer to ultrasonic datasheet)
						}	
					while (SW1 == 0);
					break;

	case 2:			lcd_2ndline();
					lcd_putstr("PWM   ");
					unsigned int range_pwm;
					while(SW1 == 1)
						{
						range_pwm = TH;									// read TH from interrupt subroutine
						lcd_goto(0x05);									// each value = 256*4/20mhz = 51.2us, 1 inch = 147us  
						range_pwm = (range_pwm*100)/288;				// 147us/51.2us = 2.87
						lcd_bcd(3,range_pwm);	
						}
					while (SW1 == 0);
					break;

	case 3:	 		lcd_2ndline();
					lcd_putstr("UART   ");
					unsigned int value,k,l = 0;
					while(SW1 == 1)
						{
						
						for (l=0 ; l<6 ; l++)
							{
							uc_uart_receive();							//take value from UART subroutine
							if(RCREG == 'R') data[k=0] = RCREG;			// check if start byte 'R' is met  
							if(data[0] == 'R') data[k++] = RCREG;		// save the data in data array
							if (k>4) k = 4;								// if the data array reached max, set the index to 4
							}
							lcd_goto(0x05);
							send_lcd_data(1,data[1]);
							send_lcd_data(1,data[2]);
							send_lcd_data(1,data[3]);
						}
		}

		while (SW1 == 0);
		if (++mode > 3) 				// if SW1 is press, increase the mode number until it is max and loop back
			{
			mode = 1;
			}	
		
	}	
}

	
