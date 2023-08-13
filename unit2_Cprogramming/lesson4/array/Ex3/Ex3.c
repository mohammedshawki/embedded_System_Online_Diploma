/*
 * Ex3.c
 *
 *  Created on: Aug 7, 2023
 *      Author: smartypc
 */


#include "stdio.h"
int main()
{
	int a[20][20];
	int t[20][20];
	int i, j, row, column;
	printf("Enter rows and column of matrix:");
	fflush(stdin); fflush(stdout);
	scanf("%d %d",&row, &column);
	printf("Enter the elements of matrix:\n");
	fflush(stdin); fflush(stdout);
	for(i=0;i<row;i++)
		for(j=0;j<column;j++)
		{
			printf("Enter elements a%d%d: ",i+1, j+1);
			fflush(stdin); fflush(stdout);
			scanf("%d",&a[i][j]);
		}
	printf("Enterd matix:\n");
	for(i=0;i<row;i++)
		for(j=0;j<column;j++)
		{
			printf("%d\t",a[i][j]);
			if(j==column-1)
				printf("\n");
		}
	for(i=0;i<row;i++)
		for(j=0;j<column;j++)
		{
			t[j][i] = a[i][j];
		}
	printf("Transpose of matrix:\n ");
	for(i=0;i<column;i++)
		for(j=0;j<row;j++)
		{
			printf("%d\t",t[i][j]);
            if(j==row-1)
            	printf("\n");
		}
}
