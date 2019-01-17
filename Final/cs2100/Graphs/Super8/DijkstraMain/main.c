/*
	PROGRAMMER'S NAME : G SRIHARSHA
	ROLLNO:111601005
	PROGRAM DESCRIPTION : 
	PROGRAM NAME :dijkstra.c
	*/
#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
//#include "doublelist.h"
void dijkstra(char a[100][100],int n,int start,int end,int parent[n],int dist[n]);
int checkAdjacentEdges(int n,int visited[n],int dist[n]) ;
int checkVertex(int n,int visited[n]);
int readmatrix(char a[100][100]);
void printpath(int parent[], int i) ;
void colorpath(char a[100][100],int parent[], int i);
void writeDotfile(char a[100][100],int n);

void main()
{
	int i,n,k,start,end,distance;
	char a[100][100];

	n=readmatrix(a);
	int parent[n],dist[n];
	
	printf("\n Enter the starting vertex :");
	scanf(" %d",&start);
	printf("\n Enter the ending vertex :");
	scanf(" %d",&end);
	
	dijkstra(a,n,start,end,parent,dist);
	/*for(i=0;i<n;i++)
	{
		printf(" %d -> %d\n",i,dist[i]);
	}*/
	printf("\n Distance between the %d and %d is %d",start,end,dist[end]);
	
	printf("\n Shortest path between %d and %d is \" ",start,end);
	printpath(parent,end);
	printf("\"\n");
	colorpath(a,parent,end);
	writeDotfile(a,n);
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
void colorpath(char a[100][100],int parent[], int i) // function which prints the path between two nodes 
{
    if(parent[i]==-1)
    {
		return;
    }
    a[i][parent[i]]='r';
    a[parent[i]][i]='r';
    colorpath(a,parent, parent[i]);
    
}

void dijkstra(char a[100][100],int n,int start,int end,int parent[n],int dist[n])
{
	int i,j,dist1,k=0;
	int visited[n];
	for(i=0;i<n;i++)
	{
		visited[i]=0;
		parent[i]=0;
		dist[i]=INT_MAX;
	}

	parent[start]=-1;
	dist[start]=0;
	//i=start;

	//while(checkVertex(n,visited))
	for(k=0;k<n;k++)
	{
		j=checkAdjacentEdges(n,visited,dist);
		//printf("%d zero\n",j );
	//j=0;
		visited[j]=1;

		for(i=0;i<n;i++)
		{
			if(a[j][i]!='0')
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


int checkAdjacentEdges(int n,int visited[n],int dist[n]) 
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

int checkVertex(int n,int visited[n])
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

void writeDotfile(char a[100][100],int n)
{
	char file[30];
	int i,j;
	FILE *p;
	printf("\n Enter the output dotfile name: ");
	scanf("%s",file);
	p=fopen(file,"w");
	if(p==0)   /* Check if the file was opened correctly */
  	{
  		printf("Error in opening the file\n");
   		return;
  	}
	else
	{
		fprintf(p,"graph G{\n");
		for(i=0;i<n;i++)
		{
			for(j=i;j<n;j++)
			{
				if(a[i][j]=='r')
				{
					fprintf(p,"%d--%d [color=red];\n",i,j);
				}
				else if(a[i][j]!='0')
				{
					fprintf(p,"%d--%d;\n",i,j);//printing the adjacent matrix to dot file
				}
				
			}
		}
		fprintf(p,"}");
		fclose(p);//closing the file
	}
}
int readmatrix(char a[100][100])
{
	int i,j,n;
	char file[30],type[10],filename[30];
	FILE *p;

	printf("\n Enter the file name: ");//enter the input filename
	scanf("%s",filename);
	p=fopen(filename,"r");
	
	if(p==0)   /* Check if the file was opened correctly */
  	{
  		printf("Error in opening the file\n");
   		return 0;
  	}
	else
	{
		fscanf(p,"%s",file);//scanning the filename
		fscanf(p,"%s",type);//scanning the type of the matrix
		fscanf(p,"%d\n",&n);//scanning the size of the square adjacent matrix
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				fscanf(p,"%c",&a[i][j]);//scanning the matrix
			}
			fscanf(p,"\n");	
		}
		fclose(p);//closing the file
	} 
  
	return n;//function will return the size of the matrix
	
}