/*

 * ex6.c
 *
 *  Created on: Aug 3, 2023
 *      Author: smartypc
 */


#include "stdio.h"
int main()
{
	int n, i, sum=0;
	printf("Enter an integer: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		sum+=i;
	}
	printf("sum= %d",sum);
}
