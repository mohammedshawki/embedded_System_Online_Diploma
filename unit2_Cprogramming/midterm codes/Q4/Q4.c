/*
 * Q4.c
 *
 *  Created on: Aug 23, 2023
 *      Author: smartypc
 */

#include "stdio.h"
int rev_fn(int x);
int main()
{
	int a, result;
	printf("the input:");
	fflush(stdin); fflush(stdout);
	scanf("%d",&a);
	result =rev_fn(a);
	printf("->output:%d",result);
}
int rev_fn(int x)
{
	int y =0, rem;
	while(x!=0)
	{
		rem= x%10;
		y=y*10+rem;
		x=x/10;
	}
	return y;
}
