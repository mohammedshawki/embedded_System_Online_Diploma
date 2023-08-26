/*
 * Q5.c
 *
 *  Created on: Aug 26, 2023
 *      Author: smartypc
 */


#include "stdio.h"
int binfn(int a)
{
	int i, count=0;
	for(i=0;i<sizeof(a)*8;++i)
	{
		if(((a>>i)&1)==1)
			count++;

	}
	return count;
}
int main()
{
	int a;
	printf("Enter the number:");
	fflush(stdin); fflush(stdout);
	scanf("%d",&a);
	printf("The numbers of ones in binary number is:%d",binfn(a));
}
