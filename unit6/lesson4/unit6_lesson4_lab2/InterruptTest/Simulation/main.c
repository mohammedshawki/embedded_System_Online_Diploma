/*
 * main.c
 *
 *  Created on: Aug 4, 2017
 *      Author: Keroles Shenouda
 *      https://www.facebook.com/groups/embedded.system.KS/
 */

#define F_CPU 1000000ul
#include "util/delay.h"
#include <avr/io.h>
#include <avr/interrupt.h>


ISR(INT0_vect)
{
	//DDRD = 0xff;
	PORTD |= 1<<5;
	_delay_ms(1000);
}

ISR(INT1_vect)
{
	//DDRD = 0xff;
	PORTD |= 1<<6;
	_delay_ms(1000);
}

ISR(INT2_vect)
{
	//DDRD = 0xff;
	PORTD |= 1<<7 ;
	_delay_ms(1000);
}
int main(void)
{


	/* Int0 any change*
	   Int 1 /rising edge
	   int2 falling edge*/
	MCUCR |= (1<<0 |  1<<2 | 1<< 3);
	MCUCR &= ~(1<<1);
	MCUCSR &= ~(1<<6);
	GICR |= (1<<5 |  1<<6 | 1<< 7);
	sei(); // enable SREG [global interrupt enable]
	DDRD |= (1<<5) | (1<<6) | (1<<7) ;
    while(1)
    {


		PORTD &= ~((1<<5) | (1<<6) | (1<<7)) ;
		_delay_ms(1000);
    }
}



//#include "GPIO/GPIO.h"
//#include "lcd/lcd.h"
//#include "mydelay.h"
//#include "keypad/keypad.h"
//#define output 1
//#define input 0
//
//int main ()
//{
//	char key_pressed;
//	LCD_lcd_init();
//	Keypad_init();
//
//	char z[10];
//	char y,x;
//
//
//	while (1)
//	{
//
//		key_pressed = Keypad_getkey();
//		switch(key_pressed)
//		{
//		case('A'):
//	     break;//do nothing if no key is pressed
//		case('?'):
//			LCD_clear_screen();
//		 break;//do nothing if no key is pressed
//
//		case('='):
//		LCD_Send_A_Character(key_pressed);
//       itoa(x,z);
//				LCD_Send_A_Character(z);
//
//		break;
//
//		case('+'):
//
//		LCD_Send_A_Character(key_pressed);
//		y=x;
//
//				break;
//
//		default:
//
//
//
//			LCD_Send_A_Character(key_pressed);//send the key pressed to LCD
//             x=key_pressed;
//
//
//		}
//		//_delay_ms(100);
//
//	}
//
//
//	return 0 ;
//}



//	//	GPIO_voidInit();
//	//	GPIO_u8_WritePinDir(5,output,'D') ;
//	//	int toggle_led = 1;
//	//	while(1)
//	//	{
//	//		GPIO_u8_WritePinVal(5,toggle_led,'D') ;
//	//		toggle_led ^= 1 ;
//	//		DELAY_MS(1000);
//	//	}
//
//	LCD_lcd_init();
//	LCD_Send_A_String("Hello IN Embedded-System Diploma By:Eng.Keroles Shenouda :) ");
//		LCD_clear_screen();
//		LCD_Send_A_String("Numbers Examples:");
//		LCD_display_real_number(30.127);
//		LCD_Send_A_String("  ");
//		LCD_display_number(12);
//		LCD_clear_screen();
//		DELAY_MS (1000);
