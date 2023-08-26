/*
 * Q3.c
 *
 *  Created on: Aug 22, 2023
 *      Author: smartypc
 */


#include "stdio.h"
int fn(int a);
int main()
{
	int i, n1, n2, test;
	printf("Enter 2 numbers:");
	fflush(stdin); fflush(stdout);
	scanf("%d %d",&n1, &n2);
	printf("prime numbers between %d and %d are:\n",n1, n2);
	for(i=n1+1;i<n2;i++)
	{
		test= fn(i);
		if(test == 0)
			printf("%d\t",i);
	}
}
int fn(int a)
{
	int j, test=0;
	for(j=2;j<=a/2;j++)
	{
		if(a%j==0){
			test =1;
			break;
		}
	}
	return test;
}
