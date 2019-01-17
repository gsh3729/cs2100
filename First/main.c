/*
	PROGRAMMER'S NAME : G SRIHARSHA
	ROLLNO:111601005
	PROGRAM DESCRIPTION : calculating distance betweeen 2 vertices
	DATE=7/11/17   				*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "readWriteBfs.h"

void calculateDistance(char a[100][100],int n,int dist[n][n]); //function to calculate distance between all veritces
void distanceBetween2Vertices(int n,int parent[n], int i,int *ptrdist); //function to calculate distance for paticular 2 vetices
void average(int n,int dist[n][n]);

void main()
{
	char a[100][100],filename[50];
	int n,n1,n2,i=1,j=0,*ptrdist,distance;
	
	ptrdist=&distance;
	*ptrdist=0;

	printf("\n Enter the file name: ");//enter the input filename
	scanf("%s",filename);
	
	//printf("%s111\n",filename );
	n=readmatrix(a,filename); //function to read adjacent matrix from the input file
	int dist[n][n];
	for ( i = 0; i < n; i++)
	{
		for ( j = 0; j < n; j++)
		{
			//printf("%c ",a[i][j] );
			dist[i][j]=-1;
			if (i==j)
			{
				dist[i][j]=0;	/* code */
			}
		}

		//printf("\n");
	}
	//printf("hai\n");
	calculateDistance(a,n,dist);
	//printf("hi\n");
 	for (i = 0; i < n; i++)
	{
		for ( j = 0; j < n; j++)
		{
			printf(" %d",dist[i][j]); //printing the distance matrix
		}
		printf("\n");
	}

 	writeDotfile(a,n,filename,dist); //function to generate output txt file
 	 
 	average(n,dist);
}
void average(int n,int dist[n][n])
{
	int sum=0,k,i,j;
	float average;
	for (i = 0; i < n; i++)
	{
		for ( j = 0; j < n; j++)
		{
			if (dist[i][j]==-1 && i!=j) // checking whether the graph is connected or not
			{
				printf("\n Graph is disconnected \n");
				return;
			}
		}
	}
	printf(" k before%d\n",k );
	for (i = 0; i < n; i++)
	{
		for ( j = i; j < n; j++)
		{
			if (dist[i][j]!=-1)
			{
				sum=sum+dist[i][j]; //calculating the average
				k++;
			}
		}
	}
	printf("k value %d\n", k);
	printf("\n sum %d ",sum);
	average = ((float)sum/k);
	printf("\n Average is %f\n",average);
}
void calculateDistance(char a[100][100],int n,int dist[n][n])//function to calculate distance between all veritces
{
	int k=0,parent[n],visited[n];
	int *ptrdist,distance;
	ptrdist=&distance;
	int i,j,l;

	for (i = 0; i < n; i++) //2 for loops to get distance matrix 
	{
		for (j = 0; j < n; j++)
		{
			k=0;
			for (l = 0; l < n ; l++)
			{
				parent[l]=0;
				visited[l]=0;
				
			}

			
			k=BreadthFirstSearch(a,n,i,j,parent,visited); 
			//printf("k value %d\n",k );
			if (k==1)
			{
				*ptrdist=0;
				distanceBetween2Vertices(n,parent,j,ptrdist);
				if (i!=j)
				{
					dist[i][j]=*ptrdist;
					dist[j][i]=*ptrdist;
				}
				
			}
		}
	}
	

}
void distanceBetween2Vertices(int n,int parent[n], int i,int *ptrdist)//function to calculate distance for paticular 2 vetices
{
    if(parent[i]==-1)
    {
		return;
    }
    (*ptrdist)= (*ptrdist)+1;
    distanceBetween2Vertices(n,parent, parent[i],ptrdist);
}
