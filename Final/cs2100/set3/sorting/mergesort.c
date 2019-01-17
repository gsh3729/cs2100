/*
	PROGRAMMER'S NAME : G SRIHARSHA
	ROLLNO:111601005
	PROGRAM DESCRIPTION : program to implement merge sort with help recursive function call to sort of array of integer in ascending order. 
	DATE=12/09/17   				*/
#include <stdio.h>

void mergesort(int a[],int);
void merge(int a[],int left[],int right[],int ,int);

void main()
{
	int a[100],l,i;
	printf("\n Enter the length of the list ");
	scanf("%d",&l);
	for(i=0;i<l;i++)//taking input from user
	{
		printf("\n Enter the %d element in the list ",i+1);
		scanf("%d",&a[i]);
	}
	mergesort(a,l);
	printf("\n The sorted array is \n");
	for(i=0;i<l;i++)//printing the output sorted array
	{
		printf(" %d",a[i]);
	}
	printf("\n");
}
void mergesort(int a[],int l)
{
	int left[100],right[100]; //dividing the input array in to 2 arrays
	int midpoint,n1,n2,i;
	if(l==1)//terminating condition for recursion
	{
		return ;
	}

	midpoint = l/2; //calculating midpoint
	//dividing the input array in to 2 arrays
	for(i=0;i<midpoint;i++)//left array
	{
		left[i]=a[i];
	}
	for(i=0;i<(l-midpoint);i++)//right array
	{
		right[i]=a[i+midpoint];
	}
	
	mergesort(left,midpoint); //goes on dividing the array untill single element array is reached 
	mergesort(right,l-midpoint);
	merge(a,left,right,midpoint,l-midpoint);//then merging happens from the single element to full array 
}
void merge(int a[],int left[],int right[],int n1,int n2)
{
	int i=0,j=0,k=0;
	while(i<n1 && j<n2) 
	{
		if(left[i] <= right[j])
		{
			a[k]=left[i]; //updating the final array
			k++;
			i++;
		}
		else
		{
			a[k]=right[j];
			k++;
			j++;
		}
	}
	while(i<n1) //if any elements in left array are remaining 
	{
		a[k]=left[i];
		k++;
		i++;
	}
	while(j<n2) //if any elements in right array are remaining 
	{
		a[k]=right[j];
		k++;
		j++;
	}
}
















		
