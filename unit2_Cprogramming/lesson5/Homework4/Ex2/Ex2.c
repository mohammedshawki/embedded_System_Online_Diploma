/*
 * Ex2.c
 *
 *  Created on: Aug 17, 2023
 *      Author: smartypc
 */

#include "stdio.h"
int fac();
int main()
{
	int n;
	printf("Enter a positive integer:");
	fflush(stdin); fflush(stdout);
	scanf("%d",&n);
	printf("factorial of %d is %d",n, fac(n));

}
int fac(int num)
{
	int f=1;
	for(;num>0;num--)
		f*=num;
	return f;
}
