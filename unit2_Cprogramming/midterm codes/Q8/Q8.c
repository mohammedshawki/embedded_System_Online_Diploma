/*

 * Q8.c
 *
 *  Created on: Aug 24, 2023
 *      Author: smartypc
 */

#include "stdio.h"
void rev(int a[], int n);
int main()
{
	int a[20], n, i;
	printf("Enter the number of element:");
	fflush(stdin); fflush(stdout);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("The element number %d:",i+1);
		fflush(stdin); fflush(stdout);
		scanf("%d",&a[i]);
	}
	rev(a, n);
}
void rev(int a[], int n)
{
	int b[20], i;
	printf("reversed array: ");
	for(i=0;i<n;i++)
	{
		b[i]= a[n-i-1];
		printf("%d\t",b[i]);
	}

}


