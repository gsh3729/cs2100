/*
	PROGRAMMER'S NAME : G SRIHARSHA
	ROLLNO:111601005
	PROGRAM DESCRIPTION : program to implement merge sort with help recursive function call to sort of array of integer in ascending order. 
	DATE=12/09/17   				*/
#include <stdio.h>
#include <string.h>

void mergesort(char a[][100],int);
void merge(char a[][100],char left[][100],char right[][100],int ,int);

void main()
{
	char a[100][100];
	int l,i,j;
	printf("\n Enter the length of the list ");
	scanf("%d",&l);
	for(i=0;i<l;i++)//taking input from user
	{
		printf("\n Enter the %d name in the list ",i+1);
		scanf("%s",a[i]);
	}
	
	printf("\n Before sorting the list is \n");
	for(i=0;i<l;i++)//printing the output sorted array
	{
		printf(" %s\n",a[i]);
	}
	mergesort(a,l);
	printf("\n The sorted list is \n");
	for(i=0;i<l;i++)//printing the output sorted array
	{
		printf(" %s\n",a[i]);
	}
	printf("\n");
}
void mergesort(char a[][100],int l)
{
	char left[100][100],right[100][100]; //dividing the input array in to 2 arrays
	int midpoint,n1,n2,i;
	if(l==1)//terminating condition for recursion
	{
		return ;
	}

	midpoint = l/2; //calculating midpoint
	//dividing the input array in to 2 arrays
	for(i=0;i<midpoint;i++)//left array
	{
		strcpy(left[i],a[i]);
	}
	for(i=0;i<(l-midpoint);i++)//right array
	{
		strcpy(right[i],a[i+midpoint]);
	}
	
	mergesort(left,midpoint); //goes on dividing the array untill single element array is reached 
	mergesort(right,l-midpoint);
	merge(a,left,right,midpoint,l-midpoint);//then merging happens from the single element to full array 
}
void merge(char a[][100],char left[][100],char right[][100],int n1,int n2)
{
	int i=0,j=0,k=0,m=1;
	while(i<n1 && j<n2) 
	{
		if(left[i][0] <= right[i][0]) 
		{	
			while(1)
			{
				if(left[i][m] == right[i][m])
				{
					m++;
					continue;
				}
				if(left[i][m] < right[i][m])
				{
					strcpy(a[k],left[i]);
					break;
				}
				else
				{
					strcpy(a[k],right[j]);
					break;
				}
			}
			k++;
			i++;
		}
		else
		{
			strcpy(a[k],right[j]);
			k++;
			j++;
		}
	}
	while(i<n1) 
	{
		strcpy(a[k],left[i]); 
		k++;
		i++;
	}
	while(j<n2)
	{
		strcpy(a[k],right[j]);
		k++;
		j++;
	}
}
















		
