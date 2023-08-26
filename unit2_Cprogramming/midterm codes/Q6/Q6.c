/*
 * Q6.c
 *
 *  Created on: Aug 24, 2023
 *      Author: smartypc
 */


#include "stdio.h"
int sfn(int a[], int n)
{
	int i, j, flag;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			if(i==j)
				continue;
			else
				if(a[i]==a[j])
					break;
				else
					flag = i;
		}
		return a[flag];
}
int main()
{
	int n, a[10];
	printf("Enter the number of elements:");
	fflush(stdin); fflush(stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("Enter the element %d:",i+1);
		fflush(stdin); fflush(stdout);
		scanf("%d",&a[i]);
	}
	printf("the unique number is: %d",sfn(a, n));
}
