/*
 * Q6.c
 *
 *  Created on: Aug 18, 2023
 *      Author: smartypc
 */


#include "stdio.h"
int main()
{
	int n, c, k;
	printf("Enter an integer(decimal):");
	fflush(stdin); fflush(stdout);
	scanf("%d",&n);
	printf("%d binary system is ", n);
	for(c=31;c>=0;c--)
	{
		k = n >> c;
		if(k & 1)
			printf("1");
		else
			printf("0");
	}
	printf("\n");
	k = n>> 3;
	if(k&1)
		printf("4th least significant bit is 1");
	else
		printf("4th least significant bit is 0");

}
