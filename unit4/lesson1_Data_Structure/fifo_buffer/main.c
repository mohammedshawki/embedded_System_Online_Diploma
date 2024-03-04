/*
 * main.c
 *
 *  Created on: Oct 20, 2023
 *      Author: smartypc
 */

#include "stdio.h"
#include "fifo.h"
#include "Platform_Types.h"

void main()
{
	element_type i, temp;
	FIFO_BUF_t FIFO_UART;
	if(  FIFO_init(&FIFO_UART, uart_buffer, 5)  == FIFO_NO_Error)
		printf("fifo init >>>>>>Done\n");
	for(i=0;i<7;i++)
	{
		printf("fifo enqueue (%x)\n",i);
		if (  FIFO_enqueue(&FIFO_UART, i) == FIFO_NO_Error  )
			printf("\tfifo enqueue >>>>>>Done\n");
		else
			printf("\tfifo enqueue >>>>>>failed\n");
	}
	FIFO__print(&FIFO_UART);

	if (FIFO_dequeue(&FIFO_UART, &temp) == FIFO_NO_Error  )
		printf("\nfifo dequeue (%x) >>>>>>Done\n",temp);

	if (FIFO_dequeue(&FIFO_UART, &temp) == FIFO_NO_Error  )
		printf("\nfifo dequeue (%x)>>>>>>Done\n",temp);
	FIFO__print(&FIFO_UART);
}

