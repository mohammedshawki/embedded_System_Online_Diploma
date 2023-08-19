/*
 * Q5.c
 *
 *  Created on: Aug 19, 2023
 *      Author: smartypc
 */


#include "stdio.h"
int clrfn(int n, int bit)
{
		return n &= ~(1<<bit);

}
int main()
{
	int n, bit;
	printf("input number:");
	fflush(stdin); fflush(stdout);
	scanf("%d",&n);
	printf("bit bosition:");
	fflush(stdin); fflush(stdout);
	scanf("%d",&bit);
	printf("Result = %d", clrfn(n,bit));
}
