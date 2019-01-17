/*
	PROGRAMMER'S NAME : G SRIHARSHA
	ROLLNO:111601005
	PROGRAM DESCRIPTION : program to implement quick sort with help recursive function call to sort of array of integer in ascending order. 
	DATE=12/09/17   				*/
#include <stdio.h>



void main()
{
	int a[100],l,i;
	printf("\n Enter the length of the list (<100) ");
	scanf("%d",&l);
	for(i=0;i<l;i++)//taking input from user
	{
		printf("\n Enter the %d element in the list ",i+1);
		scanf("%d",&a[i]);
	}
	printf("\n Before sorting the array is \n");
	for(i=0;i<l;i++)//printing the output sorted array
	{
		printf(" %d",a[i]);
	}
	quicksort(a,l);
	printf("\n The sorted array is \n");
	for(i=0;i<l;i++)//printing the output sorted array
	{
		printf(" %d",a[i]);
	}
	printf("\n");
}
void quicksort()
{
























