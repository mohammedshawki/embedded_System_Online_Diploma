/*
 * Ex1.c
 *
 *  Created on: Sep 5, 2023
 *      Author: smartypc
 */

#include "stdio.h"
int main()
{
	int m=29;
	int* Pab;
	Pab=&m;
	printf("Address of m is %p\nvalue of m:%d\n",&m, m);
	printf("Address of pointer ab: %p\nvalue of ab:%d\n",Pab, *Pab);
	m = 34;
	printf("Address of pointer ab: %p\nvalue of ab:%d\n",Pab, *Pab);
	*Pab=7;
	printf("Address of m is %p\nvalue of m:%d\n",&m, m);
}

