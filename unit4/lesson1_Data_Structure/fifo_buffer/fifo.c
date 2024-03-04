/*
 * fifo.c
 *
 *  Created on: Oct 20, 2023
 *      Author: smartypc
 */
#include "stdio.h"
#include "fifo.h"
#include "stdio.h"
FIFO_Buf_status FIFO_init(FIFO_BUF_t* fifo, element_type* buf, uint32_t length )
{
	//check buf is valid
	if (buf == NULL)
		return FIFO_NULL ;
	fifo->base = buf;
	fifo->head = fifo->base;
	fifo->tail = fifo->base;
	fifo->length = length;
	fifo->count = 0;
	return FIFO_NO_Error ;
}
FIFO_Buf_status FIFO_enqueue(FIFO_BUF_t* fifo, element_type item )
{
	//check fifo is valid
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_NULL ;
	//check fifo is full
	if (FIFO_is_full(fifo) ==FIFO_FULL)
		return FIFO_FULL ;

	*(fifo->head) = item ;
	fifo->count++;
	//check circular fifo
	if(fifo->head == (fifo->base + (fifo->length * sizeof(element_type))))
		fifo->head = fifo->base ;
	else
		fifo->head++;

	return FIFO_NO_Error;
}
FIFO_Buf_status FIFO_dequeue(FIFO_BUF_t* fifo, element_type* item )
{
	//check fifo is valid
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_NULL ;
	//check fifo is empty
	if(fifo->count==0)
		return FIFO_empty ;
	*item = *(fifo->tail) ;
	fifo->count--;
	//check circular fifo
	if(fifo->tail == (fifo->base + (fifo->length * sizeof(element_type))))
		fifo->tail = fifo->base ;
	else
		fifo->tail++;
	return FIFO_NO_Error ;
}
FIFO_Buf_status FIFO_is_full(FIFO_BUF_t* fifo)
{
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_NULL ;
	if(fifo->count == fifo->length)
		return FIFO_FULL ;

	return FIFO_NO_Error ;
}
void FIFO__print(FIFO_BUF_t* fifo)
{
	element_type* temp ;
	int i;
	if(fifo->count == 0)
	{
		printf("fifo is empty\n");
	} else {
		temp = fifo->tail ;
		printf("\n==========fifo_print============\n");
		for(i=0;i<fifo->count; i++)
		{
			printf("\t %X \n",*temp);
			temp++ ;
		}
	}
	printf("\n=====================");
}

