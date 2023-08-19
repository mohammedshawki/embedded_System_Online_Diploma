/*
 * Q3.c
 *
 *  Created on: Aug 19, 2023
 *      Author: smartypc
 */


#include"stdio.h"
void revfn(int size,int a[],int b[])
{
		int i, j;
		for(i=size-1,j=0;i>=0;i--,j++)
			b[j]=a[i];
		printf("Result of reverse array is:\n");
		for(j=0;j<size;j++)
			printf("%d\t",b[j]);
}
int main()
{
	int a[10], b[10], i, size;
	printf("enter the size of array:");
	fflush(stdin); fflush(stdout);
	scanf("%d",&size);
	for(i=0;i<size;i++)
	{
		printf("Enter the ele %d:",i+1);
		fflush(stdin); fflush(stdout);
		scanf("%d",&a[i]);
	}
	revfn(size, a, b);
}
