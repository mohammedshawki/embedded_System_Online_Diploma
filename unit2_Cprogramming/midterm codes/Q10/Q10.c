/*
 * Q10.c
 *
 *  Created on: Aug 26, 2023
 *      Author: smartypc
 */


#include "stdio.h"
int binfn(int a);
int main()
{
	int a;
	printf("Enter the number:");
	fflush(stdin); fflush(stdout);
	scanf("%d",&a);
	printf("The max number of ones between two zeros is:%d",binfn(a));
}
int binfn(int a)
{
	int i, test, count=0, max=0;
		for(i=0;i<sizeof(a)*8;i++)
		{
			test= a & (1<<i);
			if(test>0)
			{
				count++;
			}
			else
			{
				if (count > max)
				{
					max = count;
				}
				count=0;
			}
		}
		return max;
}
