/*

 * Ex1.c
 *
 *  Created on: Aug 7, 2023
 *      Author: smartypc
 */

#include "stdio.h"
int main()
{
	float a[2][2];
	float b[2][2];
	float c[2][2];
	int i, j;
	printf("Enter the element of 1st matrix\n");
	fflush(stdin); fflush(stdout);
	for(i=0;i<2;i++)
		for(j=0;j<2;j++)
		{
			printf("Enter a%d%d: ",i+1, j+1);
			fflush(stdin); fflush(stdout);
			scanf("%f", &a[i][j]);
		}
	printf("Enter the element of 2nd matrix\n");
	for(i=0;i<2;i++)
		for(j=0;j<2;j++)
		{
			printf("Enter b%d%d: ",i+1, j+1);
			fflush(stdin); fflush(stdout);
			scanf("%f", &b[i][j]);
		}
	for(i=0;i<2;i++)
		for(j=0;j<2;j++)
		{
	     	c[i][j]= a[i][j] + b[i][j];
		}
	printf("sum of matrix\n");
	fflush(stdin); fflush(stdout);
	for(i=0;i<2;i++)
			for(j=0;j<2;j++)
			{
		     		printf("%.1f\t",c[i][j]);
                    if(j==1)
    	             printf("\n");
			}
}
