/*
 * Ex4.c
 *
 *  Created on: Aug 18, 2023
 *      Author: smartypc
 */


#include "stdio.h"
int powerfn(int n, int p);
int main()
{
	int n, p;
	printf("Enter base number:");
	fflush(stdin); fflush(stdout);
	scanf("%d",&n);
	printf("Enter power number:");
	fflush(stdin); fflush(stdout);
	scanf("%d",&p);
	printf("%d^%d = %d",n, p, powerfn(n, p));
}
int powerfn(int n, int p)
{
	if( p!=0 )
		return(n*powerfn(n,p-1));
	else
		return 1;

}
