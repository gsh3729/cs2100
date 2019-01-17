/*
	PROGRAMMER'S NAME : G SRIHARSHA
	ROLLNO:111601005
	PROGRAM DESCRIPTION : 
	DATE=12/09/17   				*/
#include <stdio.h>
void main()
{
	int a[100][100],r,c,i,target,index;
	printf("\n Enter the no of rows of the matrix (<100) ");
	scanf("%d",&r);
	printf("\n Enter the no of colums of the matrix (<100) ");
	scanf("%d",&c);
	printf("\n Enter the elements to the matrix ",i+1);
	for(i=0;i<r;i++)//taking input from user
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}

	printf("\n Enter the target value ");
	scanf("%d",&target);
	
	searchMatrix(a,r,c,x,target);
	printf("\n COMPLEXITY is O(no of rows+ no of colums);
}
void searchMatrix(int a[][],int r,int c,int x,int target)
{
	int i,j;
	
	for(j=0;j<c;j++)
	{
		for(j=0;j<c;j++)
		{
			if(x==1)				
			{
				if(target==a[i][j])
				{	
					printf("\n Target found at (%d,%d)",i,j);
					return ;			
				}
				else if(target<a[i][j])
				{
					break;
				}
			}
			else if ()
			{
				if(target==a[i][j])
				{	
					printf("\n Target found at (%d,%d)",i,j);
					return ;			
				}
				else if(target>a[i][j])
				{
					break;
				}
			}
		}
	}
	printf("\n Target you entered is not there in the matrix");
}
			







































