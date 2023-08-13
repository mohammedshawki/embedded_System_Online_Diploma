/*

 * Ex4.c
 *
 *  Created on: Aug 7, 2023
 *      Author: smartypc
 */

#include"stdio.h"
int main()
{
	int a[10];
	int i, n, ele, loc;
	printf("Enter no of elements:");
	fflush(stdin); fflush(stdout);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter the element to be inserted: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&ele);
	printf("Enter the location:");
	fflush(stdin); fflush(stdout);
	scanf("%d",&loc);
	for(i=n;i>=loc;i--)
	{
		a[i]=a[i-1];
	}
	n++;
	a[loc-1]=ele;
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}

}
