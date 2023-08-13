/*

 * Ex5.c
 *
 *  Created on: Aug 7, 2023
 *      Author: smartypc
 */

#include "stdio.h"
int main()
{
	int a[100];
	int i, n, ele;
	printf("Enter no of elements:");
    fflush(stdin); fflush(stdout);
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    	scanf("%d",&a[i]);
    }
    printf("Eneter the element to be searched:");
    fflush(stdin); fflush(stdout);
    scanf("%d",&ele);
    for(i=0;i<n;i++)
    {
    	if(a[i]==ele){
    		break;
    	}
    }
    if(a[i]==ele){
    	printf("number found at location: %d",i+1);
    }
    else
    {
    	printf("error");
    }


}
