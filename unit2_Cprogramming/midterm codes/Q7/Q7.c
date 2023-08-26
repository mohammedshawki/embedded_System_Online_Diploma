/*
 * Q7.c
 *
 *  Created on: Aug 24, 2023
 *      Author: smartypc
 */

#include "stdio.h"
int sum(int n)
{
	static int value=0;
	if(n>0&&n<=100)
	{
		value += n;
		sum(++n);
	}
	return value;
}
int main()
{
	int n=1;
	printf("the summation from 1 to 100 is: %d",sum(n));
}
