/*
	PROGRAMMER'S NAME : G SRIHARSHA
	ROLLNO:111601005
	PROGRAM DESCRIPTION : program to implement bubble sort  to sort of array of integer in descending order.  
	DATE=12/09/17   				*/
#include <stdio.h>

void bubblesort(int a[],int l);

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
	bubblesort(a,l);
	printf("\n The sorted array is \n");
	for(i=0;i<l;i++)//printing the output sorted array
	{
		printf(" %d",a[i]);
	}
	printf("\n");
}

void bubblesort(int a[],int l)//bubble sort function
{
	int i,j,temp;
	for(i=0;i<l-1;i++) //ater 1 loop lowest number in array gets pushed to last element of the array
	{
		for(j=0;j<l-i-1;j++) //then checking the remaining elements
		{
			if(a[j]<a[j+1])
			{
				temp=a[j+1]; //swaping the elements
				a[j+1]=a[j];
				a[j]=temp;
			}
		}
	}
}
