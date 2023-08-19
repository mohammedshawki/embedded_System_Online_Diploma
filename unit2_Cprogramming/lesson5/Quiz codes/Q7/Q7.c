/*
 * Q7.c
 *
 *  Created on: Aug 18, 2023
 *      Author: smartypc
 */


#include "stdio.h"
int fn(int a);
int main()
{
	int n, value;
	printf("Enter the number:");
	fflush(stdin); fflush(stdout);
	scanf("%d",&n);
	value = fn(n);
	printf("%d ==> %d",n, value);
}
int fn(int a)
{
	int b=3, value =1;
	if(a%b==0)
		value =0;
	return value;
}
