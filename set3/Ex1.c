/*
	PROGRAMMER'S NAME : G SRIHARSHA
	ROLLNO:111601005
	PROGRAM DESCRIPTION : searching a float number from the user input list
	DATE=8/09/17   				*/
#include <stdio.h>
void main()
{
	float a[100],value;
	int l,i,j=0;
	printf("\n Enter the length of the list ");
	scanf("%d",&l);
	for(i=0;i<l;i++)//taking input from user
	{
		printf("\n Enter the %d element in the list ",i+1);
		scanf("%f",&a[i]);
	}
	for(i=0;i<l-1;i++) //checking whether the list is sorted or not
	{
		if(a[i+1]<a[i])
		{
			printf("\n Entered input is not sorted.So terminating from the program\n");
			return;
		}
	}
	printf("\n Enter the target value ");
	scanf("%f",&value);
	for(i=0;i<l;i++)//for loop to check the array
	{
		if(value >= a[i]-0.000001 && value <= a[i]+0.000001)
		{
			j=1;
			break;
		}
	}
	if(j==1)
	{
		printf("\n Yes\n");
	}
	else
	{
		printf("\n No\n");
	}
}
		 

