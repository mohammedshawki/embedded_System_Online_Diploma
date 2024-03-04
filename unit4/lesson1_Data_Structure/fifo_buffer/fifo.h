/*
 * fifo.h
 *
 *  Created on: Oct 20, 2023
 *      Author: smartypc
 */

#ifndef FIFO_H_
#define FIFO_H_
#include "Platform_Types.h"
//user configuration
//choose the element type (uint8_t , uint16_t , uint32_t ....)
#define element_type uint8_t
//create buffer
//width(1,2,3,4,5.....)
#define width1 5
element_type uart_buffer [width1];
//fifo data types
typedef struct{
	unsigned int length ;
	unsigned int count ;
	element_type* head;
	element_type* base;
	element_type* tail;
}FIFO_BUF_t;
//status
typedef enum{
	FIFO_NO_Error,
	FIFO_FULL,
	FIFO_empty,
	FIFO_NULL
}FIFO_Buf_status;

//APIs
FIFO_Buf_status FIFO_init(FIFO_BUF_t* fifo, element_type* buf, uint32_t length );
FIFO_Buf_status FIFO_enqueue(FIFO_BUF_t* fifo, element_type item );
FIFO_Buf_status FIFO_dequeue(FIFO_BUF_t* fifo, element_type* item );
FIFO_Buf_status FIFO_is_full(FIFO_BUF_t* fifo);
void FIFO__print(FIFO_BUF_t* fifo);

#endif /* FIFO_H_ */
