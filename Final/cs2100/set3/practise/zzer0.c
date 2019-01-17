/*
	PROGRAMMER'S NAME : G SRIHARSHA
	ROLLNO:111601005
	PROGRAM DESCRIPTION : program to implement merge sort with help recursive function call to sort of array of integer in ascending order. 
	DATE=12/09/17   				*/
#include <stdio.h>

void main()
{
	int r,c,a[100][100],i,j,k;

	printf("\n Enter the number or rows ");
	scanf("%d",&r);
	printf("\n Enter the number or columns ");
	scanf("%d",&c);

	printf("\n Enter the inputs to the matrix\n");	
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("\n Entered matrix is \n");	
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf(" %d\t",a[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(a[i][j]==0)
			{
				for(k=0;k<c;k++)
				{
					a[i][k]=0;
				}
				for(k=0;k<r;k++)
				{
					a[k][j]=0;
				}
				k=1;
				break;
			}
		}
		if(k==1)
		{
			break;
		}
	}
	printf("\n Output matrix is \n");	
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf(" %d\t",a[i][j]);
		}
		printf("\n");
	}
	
}		
		

	
