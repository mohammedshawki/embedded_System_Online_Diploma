/*
 * ex7.c
 *
 *  Created on: Aug 3, 2023
 *      Author: smartypc
 */


#include "stdio.h"
int main()
{
	int n, i, factorial=1;
	printf("Enter an integer: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		factorial*=i;
	}
	printf("factorial= %d",factorial);
	if(n<=0)
	{
		if(n==0)
			printf("factorial of 0 is 1",n);
		else
			printf("Error!!! factorial of negative number doesn't exist",n);
	}
}
