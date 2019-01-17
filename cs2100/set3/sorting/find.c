/*
	PROGRAMMER'S NAME : G SRIHARSHA
	ROLLNO:111601005
	PROGRAM DESCRIPTION : finding the index of the given input number from the user inputed rotated array 
	DATE=12/09/17   				*/
#include <stdio.h>
int FindRotate(int a[],int n,int target);
int findpivot(int a[],int l,int h);
int binarysearch(int a[],int l,int h,int target);
void main()
{
	int a[100],len,i,target,index;
	printf("\n Enter the length of the list (<100) ");
	scanf("%d",&len);
	for(i=0;i<len;i++)//taking input from user
	{
		printf("\n Enter the %d element in the list ",i+1);
		scanf("%d",&a[i]);
	}
	printf("\n Enter the target value ");//entering the target value
	scanf("%d",&target);
	index = FindRotate(a,len,target);//findrotate function to get index of the target in the array
	printf("\n Index of the target value is %d",index);
}
int FindRotate(int a[],int n,int target)
{
	int pivot,index;
	pivot = findpivot(a,0,n-1); //function for finding the index in the rotated array from where cahnge occurs int the array
	index=binarysearch(a,0,pivot,target);//function for finding target up to pivot
	if(index==-1)
	{
		index=binarysearch(a,pivot+1,n-1,target);
	}
	return index;
}
int findpivot(int a[],int l,int h) 
{
	int mid;
	mid=(l+h)/2;

	if(l==h)
	{
		return l;
	}
	if(a[mid]>a[mid+1])
	{
		return mid;
	}
	if(a[mid]<a[mid-1])
	{
		return mid-1;
	}
	if(a[l]>a[mid])
	{
		return findpivot(a,l,mid-1);
	}
	
	return findpivot(a,mid+1,h);
}
int binarysearch(int a[],int lb,int ub,int target)//binary search function
{
	int midpoint;
	while(lb<=ub) //while for searching the list 
	{
		midpoint=(lb+ub)/2;
		if(a[midpoint]<target)
		{
			lb=midpoint+1;
		}
		if(a[midpoint]>target)
		{
			ub=midpoint-1;
		}
		if(target==a[midpoint])
		{
			return midpoint; //returning the index of the target
		}
	
	}  
	return -1;
}
	 






















