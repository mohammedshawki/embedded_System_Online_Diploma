#include "uart.h"
unsigned char string_buffer[100] = "Learn-In-Depth:<mohammed shawki>" ;
void main(void)
{
	Uart_send_string(string_buffer);
}