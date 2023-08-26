/*
 * Q1.c
 *
 *  Created on: Aug 22, 2023
 *      Author: smartypc
 */


#include "stdio.h"
int sum(int x);
int main()
{
	int n, result;
	printf("input:");
	fflush(stdin); fflush(stdout);
	scanf("%d",&n);
	result = sum(n);
	printf("->output:%d",result);
	return 0;

}
int sum(int x)
{
	int sum=0;
	while(x!=0)
	{
		sum+=x%10;
		x=x/10;
	}
	return sum;
}
