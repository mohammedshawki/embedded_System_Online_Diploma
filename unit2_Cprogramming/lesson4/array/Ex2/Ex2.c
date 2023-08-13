/*

 * Ex2.c
 *
 *  Created on: Aug 7, 2023
 *      Author: smartypc
 */

#include "stdio.h"
int main()
{
	float a[20], sum=0;
	int n, i;
	printf("Enter the number of data: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("%d. Enter number:",i+1);
		fflush(stdin); fflush(stdout);
		scanf("%f",&a[i]);

	}
	for(i=0;i<n;i++)
	{
		sum+=a[i];
	}
	printf("average= %.2f",sum/n);
}
