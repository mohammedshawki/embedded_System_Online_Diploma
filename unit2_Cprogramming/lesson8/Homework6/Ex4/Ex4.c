/*
 * Ex4.c
 *
 *  Created on: Sep 5, 2023
 *      Author: smartypc
 */
#include "stdio.h"
int main(){
	int arr[10];
	int* Parr=arr;
	int i, n;
	printf("Enter number of elements:");
	fflush(stdin); fflush(stdout);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("element -%d: ",i+1);
		fflush(stdin); fflush(stdout);
		scanf("%d",Parr+i);
	}
	Parr=&arr[n-1];
	printf("The elements of array in reverse order are:\n");
	for(i=n;i>0;i--)
	{
		printf("element -%d: %d\n",i, *Parr);
		Parr--;
	}

}


