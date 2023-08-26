/*
 * Q2.c
 *
 *  Created on: Aug 22, 2023
 *      Author: smartypc
 */


#include "stdio.h"
float sq_root(int x);
int main()
{
	int n;
	float result;
	printf("input:");
	fflush(stdin); fflush(stdout);
	scanf("%d",&n);
	result = sq_root(n);
	printf("->output:%0.3f",result);
}
float sq_root(int x)
{
	return sqrt(x);
}
