/*
 * Q8.c
 *
 *  Created on: Aug 19, 2023
 *      Author: smartypc
 */


#include "stdio.h"
int lastfn(int arr[],int size)
{
	int num, i;
	printf("Enter the number you want to check:");
	fflush(stdin); fflush(stdout);
	scanf("%d",&num);
	for(i=size;i>0;i--){
		if(arr[i]==num)
			return i+1;
	}
			return -1;
}
int main()
{
	int arr[10], size, i;
	printf("Enter the size:");
	fflush(stdin); fflush(stdout);
	scanf("%d",&size);
	for(i=0;i<size;i++)
	{
		printf("Enter the element %d: ",i+1);
		fflush(stdin); fflush(stdout);
		scanf("%d",&arr[i]);
	}
	int last = lastfn(arr,size);
	printf("Last occurrence is %d",last);
}
