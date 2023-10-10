#include "uart.h"
#define UARTODR *((volatile unsigned int* const)(unsigned int*)(0x101f1000))
void Uart_send_string(unsigned char *P_tx_string)
{
	while(*P_tx_string != '\0')
	{
		UARTODR = (unsigned int)(*P_tx_string);
		P_tx_string++;
	}
}