/*
	PROGRAMMER'S NAME : G SRIHARSHA
	ROLLNO:111601005
	PROGRAM DESCRIPTION :C program which given an input graph G (as adjacency matrix) and a starting node r, computes a DFS tree of G rooted at r. Highlight the edges of the DFS tree in a different colour in the dot file. 
	PROGRAM NAME : dfs.c
	DATE : 31/10/17
	*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "readWrite.h"

int DepthFirstSearch(char a[100][100],int n,int n1,int parent[],char b[n][n]);
void cutVertex(int n,int parent[],int cutVertices[n]);

void main()
{
	char a[100][100];
	int n,start,i=0,j=0;
	
	n=readmatrix(a); //function to read adjacent matrix from the input file
	char b[n][n];
	int parent[n],cutVertices[n];
	for(i=0;i<n;i++)
	{
		cutVertices[i]=i;
		for(j=0;j<n;j++)
		{
			b[i][j]=a[i][j];
		}
	}
	printf("\n Enter the starting node :");
	scanf("%d",&start);

	DepthFirstSearch(a,n,start,parent,b);
	cutVertex(n,parent,cutVertices);
	//printf("%d parent \n",parent[start] );
	for(i=0;i<n;i++)
	{
		if(cutVertices[i]!=-1)
		{
			printf(" %d",cutVertices[i] );
		}
		//printf(" %d",parent[i] );
	}
	//writeDotfile(n,b);

}
int DepthFirstSearch(char a[100][100],int n,int n1,int parent[],char b[n][n])//Graph01.txt
{
	int i,j,current,flag=0;
	stack *top;
	int visited[n];
	int mparent[n];

	parent[n1]=-1;
	for(i=0;i<n;i++)
	{
		visited[i]=0;
	}
	
	pushStack(&top,n1);
	while(isEmpty(&top))
	{
		current=popStack(&top);
		mparent[current]=parent[current];
		//printf(" %d",current );
		if(visited[current]==0)
		{
			//printf(" %d",current );
			visited[current]=1;
			for(j=0;j<n;j++)
			{
				if(a[current][j]=='1' && visited[j]==0)
				{
					parent[j]=current;
					pushStack(&top,j);
				}
			}
		}		
	}
	
	return 1;
}
void cutVertices(char a[100][100],int n,int parent[n],int start,char b[n][n],int cutVertex[n])
{
	int i,j,k=0;
	for(i=0;i<n;i++)
	{
		if(b[start][i]=='r')
		{
			j++;
		}
	}
	if(j>1)
	{
		cutVertex[start]=-1;
	}
	/*k=CheckAdjacentEdges(a,n,b,parent,7);
	printf("k value%d\n",k );*/
	for(i=0;i<n;i++)
	{
		if(i==start)
		{
			continue;
		}
		
		if(CheckAdjacentEdges(a,n,b,parent,i)==1)
		{
			cutVertex[i]=-1;
		}
	}
}
int CheckAdjacentEdges(char a[100][100],int n,char b[n][n], int parent[n],int x)
{
	for(int i=0;i<n;i++)
	{
		if(parent[i]==x /*&& a[i][parent[x]]=='1' && b[i][parent[x]]!='r'*/)
		{
			if(a[i][parent[x]]=='1' && b[i][parent[x]]!='r')
			{
				return 1;
			}
			return 1;
		}

		/*if (parent[i]==x)
		{
			printf("pa%d\n",i );
			if (a[i][parent[x]]=='1')
			{
				printf("pa2%d\n",i );
				if (b[i][parent[x]]!='r')
				{
					printf("pa3%d\n",i );
					return 1;
				}
			}
		}*/
	}
	return 0;
}

