/*
 * lab3.c
 *
 * Created: 2/6/2023 3:33:09 PM
 * Author : Bowman
 */ 


#include "C:\Users\Bowman\Documents\Atmel Studio\7.0\MRE_lib\F_cpu_lib.h"
#include <stdio.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>
#include "C:\Users\Bowman\Documents\Atmel Studio\7.0\MRE_lib\A2D_lib.c"
#include "C:\Users\Bowman\Documents\Atmel Studio\7.0\MRE_lib\A2D_lib.h"
#include "C:\Users\Bowman\Documents\Atmel Studio\7.0\MRE_lib\LCD_lib.h"
#include "C:\Users\Bowman\Documents\Atmel Studio\7.0\MRE_lib\LCD_lib.c"
#include "C:\Users\Bowman\Documents\Atmel Studio\7.0\MRE_lib\Serial_lib2.h"
#include "C:\Users\Bowman\Documents\Atmel Studio\7.0\MRE_lib\Serial_lib2.c"




int main(void)
{

/*================Start Initialization================*/
//Define some variables that will be used
uint16_t adc_val = 0;
char lcd_str_out[20];
uint8_t serial_char_in;
char serial_char_array_out[20];
//Enable the LED on the microcontroller board for debugging
DDRC |= 1 << PINC2;
//Initialize the LCD and send a test message
LCD_init();
LCDGoToPosition(1,1);
sprintf(lcd_str_out,"LOADING...");
LCDSendString(lcd_str_out);
_delay_ms(2000);
//Initialize the ADC, USART, and interrupts
AD_init();
USART_vInit();
sei();
LCDClearScreen();
/*==================End Initialization==================*/


	while(1)
	{
		
		serial_char_in = USART_vReceiveByte();
		LCDClearScreen();
		sprintf(lcd_str_out, "%c",serial_char_in);
		LCDSendString(lcd_str_out);
		
		LCDGoToPosition(1,1);
		
//The switch statement is takes the  the user input and puts it to lower case then if it is w,s,a,d if prints the proper statement. 
		switch(tolower(serial_char_in))
		{
			case 'w': 
					sprintf(lcd_str_out, "W is for Winning!");
					LCDSendString(lcd_str_out);
				break;
				
			case 's':
					sprintf(lcd_str_out, "S is for super!");
					LCDSendString(lcd_str_out);
				break;
			case 'a':
					sprintf(lcd_str_out, "A is for Apple!");
					LCDSendString(lcd_str_out);
				break;
			case 'd':
					sprintf(lcd_str_out, "D is for Dog!");
					LCDSendString(lcd_str_out);
				break;
				
			default: 
					sprintf(lcd_str_out, "Try again!");
					LCDSendString(lcd_str_out);
				break;
		}
		
		for(uint8_t ii =0; ii<20; ii++){
			uart_putchar(serial_char_array_out[ii],&mystdout);
		}
		uart_putchar('\n',&mystdout);
	}
	
	
}
