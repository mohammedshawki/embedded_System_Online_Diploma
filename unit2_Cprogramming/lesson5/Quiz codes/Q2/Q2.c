/*
 * Q2.c
 *
 *  Created on: Aug 19, 2023
 *      Author: smartypc
 */

#include "stdio.h"
int main()
{
	int A[10], B[10], C[10], i;
    printf("Enter the first array:");
    fflush(stdin); fflush(stdout);
    for(i=0;i<10;i++)
    	scanf("%d",&A[i]);
    printf("Enter the second array:");
    fflush(stdin); fflush(stdout);
    for(i=0;i<5;i++)
       scanf("%d",&B[i]);
    printf("array before swapping\n first array:");
    for(i=0;i<10;i++)
    	printf("\t%d",A[i]);
    printf("\nthe second array:");
    for(i=0;i<5;i++)
    	printf("\t%d",B[i]);
    for(i=0;i<10;i++)
    {
    	C[i]=A[i];
    	A[i]=B[i];
    	B[i]=C[i];
    }
    printf("\nAfter swapping:\nthe first array:");
    for(i=0;i<5;i++)
        printf("\t%d",A[i]);
    printf("\nThe second array:");
    for(i=0;i<10;i++)
      	printf("\t%d",B[i]);

}
