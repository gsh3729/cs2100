#include <stdio.h>
void incre(int *a,int n);
void main()
{
	int a[3][3],k=0,i,j,n=3;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			a[i][j]=0;
		}
	}
	i=0;
	incre(a[0],n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}
void incre(int *a,int n)
{
	for(int i=0;i<n;i++)
	{
		a[i]=1;
	}
}
