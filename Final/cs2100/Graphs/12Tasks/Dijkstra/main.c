/*
	PROGRAMMER'S NAME : G SRIHARSHA
	ROLLNO:111601005
	PROGRAM DESCRIPTION : Distance between x and y (length of the shortest path).List of vertices in a shortest path.
	PROGRAM NAME :dijkstra.c
	*/
#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
#include "readWrite.h"

void dijkstra(char a[100][100],int n,int start,int end,int parent[n],int dist[n]);
int pickMinDistEdge(int n,int visited[n],int dist[n]) ;
int checkVertex(int n,int visited[n]);
void printpath(int parent[], int i) ;
void colorpath(char a[20][20],int parent[], int i);


void main()
{
	int i,n,j,start,end,distance;
	char a[100][100];

	n=readmatrix(a);
	int parent[n],dist[n];
	char b[n][n];
	
	printf("\n Enter the starting vertex :");
	scanf(" %d",&start);
	printf("\n Enter the ending vertex :");
	scanf(" %d",&end);
	
	dijkstra(a,n,start,end,parent,dist); //calling dijkstra function
	/*for(i=0;i<n;i++)
	{
		printf(" %d -> %d\n",i,dist[i]);
	}*/
	printf("\n Distance between the %d and %d is %d",start,end,dist[end]);
	
	printf("\n Shortest path between %d and %d is \" ",start,end);
	printpath(parent,end); //function to print path from start to end
	printf("\"\n");
	for(i=0;i<n;i++)//copying the adjacent matrix
	{
		for(j=0;j<n;j++)
		{
			b[i][j]=a[i][j];
		}
	}
		
	colorpath(b,parent,end); // function to color the shortest path
	writeDotfile(a,n,b);
}
void printpath(int parent[], int i) // function which prints the path between two nodes 
{
    if(parent[i]==-1)
    {
      	printf("%d ", i);
		return;
    }
    
    printpath(parent, parent[i]);
    printf("%d ", i);
}
void colorpath(char b[20][20],int parent[], int i) // function to color the shortest path
{
    if(parent[i]==-1)
    {
		return;
    }
    b[i][parent[i]]='r';
    b[parent[i]][i]='r';
    colorpath(b,parent, parent[i]);
    
}

void dijkstra(char a[100][100],int n,int start,int end,int parent[n],int dist[n])
{
	int i,j,dist1,k=0;
	int visited[n];
	for(i=0;i<n;i++) 
	{
		visited[i]=0; //keeping all vertices as unvisited 
		parent[i]=0; //parent array to store parent of a vertex
		dist[i]=INT_MAX; //distance is given as infinity to every vertex
	}

	parent[start]=-1; //for starting vertex parent is -1
	dist[start]=0; //for starting vertex distance is 0
	//i=start;

	while(checkVertex(n,visited)) // checking whether all vertices are visited or not
	//for(k=0;k<n;k++)
	{
		j=pickMinDistEdge(n,visited,dist); //pick the minimum distance vertex from the start point
		//printf("%d zero\n",j );
	//j=0;
		visited[j]=1;

		for(i=0;i<n;i++) 
		{
			if(a[j][i]!='0') //all the neighboring edges distance will get update
			{
				if(visited[i]==0)
				{
					if (dist[j]!=INT_MAX && (dist[i] > dist[j] + (a[i][j]-'0')) )
					{
						dist[i] = dist[j] + (a[i][j]-'0'); 
						parent[i]=j;
					}
					//dist[i] = dist[j] + (a[i][j]-'0');
					//k++;
						
				}
			}
		}
	}
	//printf("%d\n",k );
	// for(i=0;i<n;i++)
	// {
	// 	printf(" %d ",visited[i]);
	// }

}	


int pickMinDistEdge(int n,int visited[n],int dist[n]) //function to pick the minimum distance vertex from the start point
{
	int i,min1=INT_MAX,min;
	for(i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			if(dist[i]<= min1)
			{
				min1=dist[i];
				min=i;
			}
			
		}
	}
	return min;
}

int checkVertex(int n,int visited[n]) // checking whether all vertices are visited or not
{
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			return 1;
		}
	}
	return 0;
}

