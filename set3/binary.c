/*
	PROGRAMMER'S NAME : G SRIHARSHA
	ROLLNO:111601005
	PROGRAM DESCRIPTION : searching the array of float numbers using binary search
	DATE=29/08/17   				*/
#include <stdio.h>

void main()
{
	float a[100],value;
	int i,j=0,l,lb,ub,midpoint,k=0;
	printf("\n Enter the length of the list ");//enter the input length
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
			j=1;
			break;
		}
	}
	if(j==1)
	{
		printf("\n Input you entered is not sorted.Please give sorted list of input \n");
		for(i=0;i<l;i++)
		{
			printf("\n Enter the %d element in the list ",i+1);
			scanf("%f",&a[i]);
		}
	}
	printf("\n Enter the target value ");
	scanf("%f",&value);
	lb=0;
	ub=l-1;
	while(lb<=ub) //while for searching the list 
	{
		midpoint=lb+(ub-lb)/2;
		if(a[midpoint]-0.000001<value)
		{
			lb=midpoint+1;
		}
		if(a[midpoint]+0.000001>value)
		{
			ub=midpoint-1;
		}
		if(value >= a[midpoint]-0.000001 && value <= a[midpoint]+0.000001)
		{
			printf("\n Yes\n");
			k=1;
			return;
		}
	
	}
	if(k==0)
	{
		printf("\n No \n");
	}

}



















