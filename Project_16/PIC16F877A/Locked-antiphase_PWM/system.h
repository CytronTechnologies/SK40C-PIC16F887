/*******************************************************************************
* This is the header file that describes the system properties for Project 16
*
* Author: Chen Kean Tack @ Cytron Technologies Sdn. Bhd.
*******************************************************************************/

// Oscillator Frequency.
#define	_XTAL_FREQ		20000000

// UART baud rate
#define UART_BAUD	9600

// LCD pins
#define	LCD_RS			RB4				//RS pin of the LCD display
#define	LCD_EN			RB5				//E pin of the LCD display
#define	LCD_data	PORTD			//LCD 8-bit data PORT

//	SK40C switches
#define	SW1			RB0			
#define	SW2			RB1	

//	MD10C ports	
#define MD10C_R_DIR	CCPR2L
#define SPEEDR		RC0
#define SPEEDL		RC3
#define MD10C_L_DIR	CCPR1L				

//	SK40C LED
#define	LED1		RB6			
#define	LED2		RB7			

//	SKPS protocol
#define	p_select		0
#define p_joyl			1
#define p_joyr			2
#define p_start			3
#define p_up			4
#define p_right			5
#define p_down			6
#define p_left			7
#define	p_l2			8
#define	p_r2			9
#define p_l1			10
#define p_r1			11
#define p_triangle		12
#define p_circle		13
#define p_cross			14
#define	p_square		15
#define p_joy_lx		16
#define	p_joy_ly		17
#define p_joy_rx		18
#define p_joy_ry		19
#define p_joy_lu		20
#define p_joy_ld		21
#define p_joy_ll		22
#define p_joy_lr		23
#define p_joy_ru		24
#define p_joy_rd		25
#define p_joy_rl		26
#define p_joy_rr		27
#define	p_con_status	28
#define p_motor1		29
#define p_motor2		30