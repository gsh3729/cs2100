/*
	PROGRAMMER'S NAME : G SRIHARSHA
	ROLLNO:111601005
	PROGRAM DESCRIPTION : FINDING MINIMUM NUMBER IN THE ARRAY USING RECURSION FUNCTION
	DATE=22/08/17   				*/
#include <stdio.h>
void main()
{
	int i,a[20],m,n;
	printf("\n Enter the number of elements in array");
	scanf("%d",&n);
	for(i=0;i<n;i++)//TAKING INPUT ARRAY
	{
		printf("\n Enter the %d element in array ",i+1);
		scanf("%d",&a[i]);
	}
	m=min(a,n);//CALLING RECURSION FUNCTION
	printf("MINIMUM IS %d\n",m);
}
int min(int *a,int n)
{
	int k=0,m,i;
	m=a[0];
	for(i=0;i<n;i++)
	{
		if(m>a[i]) //CHECKING WHETHER THE FIRST ELEMENT OF THE ARRAY IS MINIMUM OR NOT BY COMPARING WITH OTHER ELEMENTS
		{
			k=1;
			break;
		}
	}
	if(k==0)// k==0 means that first element is minimum otherwise it will call another function 
	{
		return a[0];
	}
	else
	{
		min(a+1,n-1);
	}
	
	
}		
 
	
