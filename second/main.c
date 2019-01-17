#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

#include "readWriteBfs.h"


void calculateDistance(char a[100][100],int n,int dist[n][n]); //function to calculate distance between all veritces
void distanceBetween2Vertices(int n,int parent[n], int i,int *ptrdist); //function to calculate distance for paticular 2 vetices
void colorMatrix(char a[100][100],int n,int adjcolor[n],int dist[n][n]);
int checkAdjacentColor(char a[100][100],int n,int i, int adjcolor[n],int dist[n][n]);

void main()
{
	int i,n,k;
	char a[100][100];
	
	n=readmatrix(a);
	int adjcolor[n],dist[n][n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
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
	for(i=0;i<n;i++)
	{
		adjcolor[i]=1; 
	}
	calculateDistance(a,n,dist);
	colorMatrix(a,n,adjcolor,dist);
	writeDotfile(a,n);
}
void colorMatrix(char a[100][100],int n,int adjcolor[n],int dist[n][n])//function to color all vertices
{
	int i;
	for(i=n-1;i>=0;i--) //coloring is done from back side of degenerate matrix
	{
		checkAdjacentColor(a,n,i,adjcolor,dist); //function will check adjacent vertices color and give a different  color to the vertex 
	}
}
int checkAdjacentColor(char a[100][100],int n,int i, int adjcolor[n],int dist[n][n])
{
	int k=0,l=2;
	

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(dist[i][j]<3)
			{
				adjcolor[i]=l;
				l++;
			}
			
		}

	}	
	printf("\n %d colors are used \n",l);
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
void calculateDistance(char a[100][100],int n,int dist[n][n])//function to calculate distance between all veritces
{
	int k=0,parent[n],visited[n];
	int *ptrdist,distance;
	ptrdist=&distance;
	int i,j;

	for (int i = 0; i < n; i++) //2 for loops to get distance matrix 
	{
		for (int j = 0; j < n; j++)
		{
			k=0;
			for (int l = 0; l < n ; l++)
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