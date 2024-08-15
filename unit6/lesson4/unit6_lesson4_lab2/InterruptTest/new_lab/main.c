/*
 * main.c
 *
 *  Created on: Aug 4, 2017
 *      Author: Keroles Shenouda
 *      https://www.facebook.com/groups/embedded.system.KS/
 */
//#include <avr/io.h>
//#include <avr/delay.h>
//
//#define myPORTA  (*((volatile unsigned char* const)0X3B))
//#define myDDRA   (*((volatile unsigned char* const)0X3A))
//
//int main ()
//{
//	//PA4 //PA5
//	myDDRA |= ((1<<4) | (1<<5));
//	myPORTA |=  (1<<5);
//	while(1){
//		myPORTA ^= (1<<4) ;
//		_delay_ms(1000);
//
//	}
//	return 0 ;
//}





#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

uint8_t state=0;
int main(void)
{
    /* Replace with your application code */
    DDRC |= (15<<PC0);
	PORTC&=~(15<<PC0);

	MCUCR |= (1<<ISC01);
	GICR |= (1<<INT0);
	SREG |=(1<<PC7);

	DDRD &=~(1<<PD2);
	PORTD |=(1<<PD2);

	sei();
	while (1)
    {
		if (state==1)
		{
			_delay_ms(1000);
			if (state==1)
			{
				PORTC--;
				state=0;
			}
		}
    }
}

ISR(INT0_vect)
{
	if(state==0)
	{
		state=1;
	}
	if (state==1)
	{
		PORTC++;
		state=0;
	}

}











/**


//Slave I2C TX
//#define F_CPU 8000000UL
//#define  prescaler 1  //1  4 16 	64
//#include <avr/io.h>
//#include <util/delay.h>
//void I2C_Init(unsigned long SCL_Clock){
//	TWBR = (unsigned char) (((F_CPU / SCL_Clock) - 16 ) / (2* prescaler) );
//	if (prescaler == 0 )
//		TWSR = 0 ;
//	else if (prescaler == 4 )
//		TWSR = 1 ;
//	else if (prescaler == 16 )
//		TWSR = 2 ;
//	else if (prescaler == 64 )
//		TWSR = 3 ;
//
//}
//void I2C_Start(void){
//	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTA);
//	while (((TWCR & (1<<7)) == 0)  ) ; // wait to finish
//	while ((TWSR ) != 0x08 )  ; //start condition has been transmitted
//}
//
//void I2C_Write(unsigned char cByte){
//	TWDR = cByte;
//	TWCR = (1<<TWINT)|(1<<TWEN);
//	while ((TWCR & 0x80) == 0);
//}
//
//unsigned char I2C_Read(unsigned char ack){
//	TWCR = (1<<TWINT)|(1<<TWEN)|(ack<<TWEA);
//	while ((TWCR & 0x80) == 0);
//	return TWDR;
//}
//
//void I2C_Stop(){
//	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
//}
//
//int main (void){
//	unsigned char ch;
//	DDRA = 0xFF; 		// PortA is output
//	I2C_Init(0x48) ; // initialize TWI for master mode
//	while(1){
//		_delay_ms(1000);
//		I2C_Start(); 			// transmit START condition
//		I2C_Write(0b11010000+1); 	// transmit SLA + R(1)
//		ch = I2C_Read(0); 	// read last byte send NACK
//		I2C_Stop(); 		// transmit STOP condition
//		PORTA = ch;
//	}
//	return 0 ;
//}
//
//


//I2C Slave RX
//#include <avr/io.h>
//void I2C_Set_Address(unsigned char address){
// 	 TWAR = address; }
//
//unsigned char I2C_Read(unsigned char ack){
//	unsigned char x = 0 ;
//	TWCR = (1<<TWINT)|(1<<TWEN)|(ack<<TWEA);
//	while ((TWCR & 1<<7) == 0);
//	while ((TWSR ) != 0x60 ) x =  TWSR; //own SLA + W(0) has been transmitted and ACK has been  returned
//	TWCR = (1<<TWINT)|(1<<TWEN)|(ack<<TWEA);
//	while ((TWCR & 1<<7) == 0);
//	while ((TWSR ) != 0x80 ) x =  TWSR; //Data  has been transmitted and ACK has been  returned
//
//	return TWDR;
//}
//
//int main (){
//	DDRA = 0xFF; // PORTA is output
//	I2C_Set_Address(0b11010000); // enable slave at address 01101000 and do not accept general call
//	while(1){
//		PORTA = I2C_Read(1); // receive byte and send ACK
//	}
//	return 0 ;
//}
//
































////Master I2C TX
//#undef F_CPU
//#define F_CPU 8000000UL
//#define  prescaler 1  //1  4 16 	64
//#include <avr/io.h>
//#include <util/delay.h>
//
//void I2C_Init(unsigned long SCL_Clock){
//	TWBR = (unsigned char) (((F_CPU / SCL_Clock) - 16 ) / (2* prescaler) );
//	if (prescaler == 0 )
//		TWSR = 0 ;
//	else if (prescaler == 4 )
//		TWSR = 1 ;
//	else if (prescaler == 16 )
//		TWSR = 2 ;
//	else if (prescaler == 64 )
//		TWSR = 3 ;
//
//}
//void I2C_Start(void){
//	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTA);
//	while (((TWCR & (1<<7)) == 0)  ) ; // wait to finish
//	while ((TWSR ) != 0x08 )  ; //start condition has been transmitted
//}
//void I2C_Write(unsigned char cByte){
//	TWDR = cByte;
//	TWCR = (1<<TWINT)|(1<<TWEN);
//	while ((TWCR & 0x80) == 0); //wait to finish
//}
//void I2C_Stop(){
//	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
//}
//int main ()
//{
//	unsigned char ch=0;
//	I2C_Init(0x48) ;
//	while(1){
//		_delay_ms(500);
//		I2C_Start(); // transmit START condition
//		I2C_Write(0b11010000+0); // transmit SLA + W(0)
//		while ((TWSR ) != 0x18 )  ; //SLA + W(0) has been transmitted and ACK has been  received
//		I2C_Write(ch++); // transmit data
//		while ((TWSR ) != 0x28 )  ; //Data has been transmitted and ACK has been  received
//		I2C_Stop(); // transmit STOP condition
//	}
//	return 0 ;
//}
//















































//# define F_CPU 1000000UL
//#include <avr/io.h>	//standard AVR header
//#include <util/delay.h>
//#define MOSI 5
//#define SCK  7
//#define SS   4
//void execute (unsigned char cmd, unsigned char data){
//	// initializing the packet by pulling SS low
//	PORTB &= ~(1<<SS) ;
//	SPDR = cmd; 	// start CMD transmission
//	// wait cmd transfer to finish
//	while (!(SPSR & (1<<SPIF) ) );
//	// start DATA transmission
//	SPDR = data;
//	// wait data transfer to finish
//	while (!(SPSR & (1<<SPIF) ) ) ;
//	// terminate the packet by pulling SS high
//	PORTB |= 1<<SS;}
//int main (void){
//	unsigned char counter =0 ;
//	unsigned index_dispaly =1 ;
//	// MOSI, SCK and SS are output
//	DDRB = (1<<MOSI) | (1<<SCK) | (1<<SS) ;
//	// enable SPI as master, SCk = FOsc/16
//	SPCR = (1<<SPE)  | (1<<MSTR)| (1<<SPR0);
//	execute(0x09,0xFF); // decode all displays    11111111
//	execute(0x0B,0x07); // Set Scan Limit (digit0 to digit 7)
//	execute(0x0A,0x0F); // max intensity
//	execute(0x0C,0x01); // Turn On Display
//	while(1)
//	{
//		for (index_dispaly = 1 ; index_dispaly <9 ;index_dispaly++)
//			execute(index_dispaly,counter++);
//		_delay_ms(1000);
//	}
//	return 0;
//}
//































//
//// SPI MASTER
//# define F_CPU 1000000UL	  // define crystal frequency for delay.h
//#include <avr/io.h>        // standard AVR header
//#include <util/delay.h>
//#define SS 4		// Slave Select        is Bit No.4
//#define MOSI 5 		// Master Out Slave In is Bit No.5
//#define MISO 6		// Master In Slave Out is Bit No.6
//#define SCK 7 		// Shift Clock         is Bit No.7
//
//void SPI_MasterInit(void){
//	// Set MOSI, SCK and SS as Output Pins
//	DDRB |= (1<<MOSI) | (1<<SCK) | (1<<SS) ;
//	DDRB &= ~(1<<MISO); // Set MISO as an Input Pin
//	// Enable SPI, Master mode, Shift Clock = CLK /16
//	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
//}
/////////////////// SPI MASTER TRANSMITTER PROGRAM PAGE 2/2 ////////////////
//
//unsigned char SPI_MasterTransmit(unsigned char cData){
//	SPDR = cData;			// Start transmission
//	while(!(SPSR & (1<<SPIF)));	// Wait for transmission complete
//	return SPDR;			// return the received data
//}
//int main()
//{
//	unsigned char ch = 0;		// data to send
//	DDRA = 0xFF; 			// PORTA is Output Port
//	SPI_MasterInit();		// Run as SPI Master
//	for(ch=0 ; ch<=255 ; ch++){	// infinite for loop for 0 to 255
//		_delay_ms(1000);		// Call One Sec delay
//		// send and receive data and show received at PORTA
//		PORTA = SPI_MasterTransmit(ch);
//
//	}
//	return 0;
//}
//




























////SPI Slave
//
//#define F_CPU 1000000UL  	// define crystal frequency for delay.h
//#include <avr/io.h>  		// standard AVR header
//#include <util/delay.h>
//#define SS 4			// Slave Select        is Bit No.4
//#define MOSI 5 			// Master Out Slave In is Bit No.5
//#define MISO 6			// Master In Slave Out is Bit No.6
//#define SCK 7 			// Shift Clock         is Bit No.7
//
//void SPI_SlaveInit(void){
//	DDRB |= (1<<MISO); 	// Set MISO as an Output Pin
//	// Set MOSI, SCK and SS as Input Pins
//	DDRB &= ~(1<<MOSI) & ~(1<<SCK) & ~(1<<SS) ;
//	// Enable SPI as a Slave Device
//	SPCR = (1<<SPE);
//}
//////////////////////// SPI SLAVE PROGRAM PAGE 2/2  ///////////////////////
//unsigned char SPI_SlaveReceive(unsigned char cData){
//	SPDR = cData; 				// send cData to master
//	// Wait for reception complete
//	while(!(SPSR & (1<<SPIF)));
//	// Return received data
//	return SPDR;
//}
//
//int main(){
//	unsigned char x = 255 ;
//	DDRA = 0xFF; 				// PortA is Output
//	SPI_SlaveInit();				// configure as SPI Slave
//	while(1)
//	{
//		for (x=255 ; x>0 ; x--)
//		{
//			// send value of PORTA to Master and
//			// Show Received data at PORTA
//			PORTA  = SPI_SlaveReceive(x);
//		}
//	}
//	return 0;
//}
//
//
//
//
//
//
//






























































//TX
//#undef F_CPU
//#define F_CPU 1000000ul
//#include "util/delay.h"
//#include <avr/io.h>
//#include <avr/interrupt.h>
//#include "USART/USART.h"
//
//int main(void)
//{
//	unsigned char counter =0;
//	struct USART_Config  Config ;
//	//Init ///
//	Config.CHAR_SIZE = USART_8_Bit_CHAR ;
//	Config.RECIEVE =USART_RECIEVE_ENABLE;
//	Config.TRANSMIT = USART_TRANSMIT_ENABLE;
//	Config.PARITY_MODE = USART_NO_PARITY;
//	Config.RECIEVE_INT = USART_RECIEVER_DISABLE ;
//	Config.TRANSMITER_INT = USART_TRANSMITER_DISABLE ;
//	Config.SPEED_MODE = USART_NORMAL_SPEED ;
//	Config.STOPBIT = USART_1_STOPBIT ;
//	Config.SYNCH_MODE= USART_ASYNCH ;
//
//    USART_Init(Config);
//	DDRB = 0XFF;   // for Port Direction
//	/////////////////////////////
//	while(1)
//	{
//
//		PORTB = counter ;
//		USART_Transmit((unsigned short)counter++);
//		_delay_ms(1000);
//	}
//	return 0 ;
//
//}

////RX
//#undef F_CPU
//#define F_CPU 1000000ul
//#include "util/delay.h"
//#include <avr/io.h>
//#include <avr/interrupt.h>
//
//int main(void)
//{
//	//Init ///
//	UCSRB = (1<<RXEN | 1<<TXEN) ;    // Enable USART Transmitter
//	UCSRC = (1<<UCSZ1)|(1<<UCSZ0);   // Mode3: Use 8-bit data
//	UBRRL = 51;                      // For 1 MHz Crystal and 1200 baud rate
//
//	DDRB = 0XFF;   // for Port Direction
//	/////////////////////////////
//	while(1)
//	{
//		while ( !(UCSRA & (1<<RXC)) ); 	// wait for the Receive Complete (RXC) Flag
//		PORTB = UDR;                      // Putting data into UDR, sends the data
//	}
//
//	return 0 ;
//}



//#define F_CPU 1000000ul
//#include "util/delay.h"
//#include <avr/io.h>
//#include <avr/interrupt.h>
//
//#define ADC_Converted_Data (*(volatile uint16_t *)(0x24))  //uint16_t* pointer to pint on Two Bytes L & H
//
//ISR (ADC_vect)
//{
//	PORTD = ADC_Converted_Data;		// give the low  byte to PORTD
//	PORTC = ADC_Converted_Data>>8 ;	// give the high byte to PORTB
//	ADCSRA |= (1<<6);		// start conversion
//}
//
//int main(void)
//{
//	DDRC = 0xFF;	// make Port B an output for 7Seg
//	DDRD = 0xFF;	// make Port D an output for 7Seg
//	DDRA = 0;	       // make Port A an input for ADC input
//	sei();		// enable global interrupts
//	ADCSRA = ( (0b111 << 0 )| (1<<7) | (1<<3));  // make ADC enable and select CLK/128  and interrupt enable
//	// 2.56V Vref internal, right justified,
//	// select ADC Channel 0
//	ADMUX = 0b11 << 6 ;
//	ADCSRA |= (1<<6);		// start conversion
//	while (1);
//	return 0;
//}
















/*
 * main.c
 *
 *  Created on: Aug 4, 2017
 *      Author: Keroles Shenouda
 *      https://www.facebook.com/groups/embedded.system.KS/
 */
//









//
///*
// * main.c
// *
// *  Created on: Aug 4, 2017
// *      Author: Keroles Shenouda
// *      https://www.facebook.com/groups/embedded.system.KS/
// */
////
//#define F_CPU 1000000ul
//#include "util/delay.h"
//#include <avr/io.h>
//#include <avr/interrupt.h>
//
//
//int main(void)
//{
//	DDRC = 0xFF;	// make Port B an output for 7Seg
//	DDRD = 0xFF;	// make Port D an output for 7Seg
//	DDRA = 0;	       // make Port A an input for ADC input
//
//	ADCSRA = ( (0b111 << 0 )| (1<<7) );  // make ADC enable and select CLK/128
//	// 2.56V Vref internal, right justified,
//	// select ADC Channel 0
//	ADMUX = 0b11 << 6 ;
//	while (1)
//	{
//
//		ADCSRA |= (1<<6);		// start conversion
//		// wait for conversion to finish
//		while ( (ADCSRA & (1<<4) )== 0 ) ; //ADIF – ADC Interrupt Flag 
//		PORTD = ADCL;		// give the low  byte to PORTD
//		PORTC = ADCH ;	// give the high byte to PORTB
//
//	}
//	return 0;
//
//}


//
//
//#define F_CPU 1000000ul
//#include "util/delay.h"
//#include <avr/io.h>
//#include <avr/interrupt.h>
//#include "Timer0/Timer0.h"
//
//
//ISR(INT0_vect)
//{
//	//DDRD = 0xff;
//	PORTD |= 1<<5;
//	_delay_ms(1000);
//}
//
//ISR(INT1_vect)
//{
//	//DDRD = 0xff;
//	PORTD |= 1<<6;
//	_delay_ms(1000);
//}
//
//ISR(INT2_vect)
//{
//	//DDRD = 0xff;
//	PORTD |= 1<<7 ;
//	_delay_ms(1000);
//}
//int main(void)
//{
//
//
//	/* Int0 any change*
//	   Int 1 /rising edge
//	   int2 falling edge*/
//	MCUCR |= (1<<0 |  1<<2 | 1<< 3);
//	MCUCR &= ~(1<<1);
//	MCUCSR &= ~(1<<6);
//	GICR |= (1<<5 |  1<<6 | 1<< 7);
//	sei(); // enable SREG [global interrupt enable]
//	DDRD |= (1<<5) | (1<<6) | (1<<7) ;
//    while(1)
//    {
//
//
//		PORTD &= ~((1<<5) | (1<<6) | (1<<7)) ;
//		_delay_ms(1000);
//    }
//}

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
