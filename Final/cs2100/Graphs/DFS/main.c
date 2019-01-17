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
void copyMatrix(char a[100][100],int n,char b[n][n],int parent[n],int start);

void main()
{
	char a[100][100];
	int n,start,i=0,j=0;
	
	n=readmatrix(a); //function to read adjacent matrix from the input file
	char b[n][n];
	int parent[n];

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			b[i][j]=a[i][j];
		}
	}
	printf("\n Enter the starting node :");
	scanf("%d",&start);

	DepthFirstSearch(a,n,start,parent,b);
	
	//printf("%d parent \n",parent[start] );
	// for(i=0;i<n;i++)
	// {
	// 	printf(" %d",parent[i] );
	// }
	copyMatrix(a,n,b,parent,start);
	writeDotfile(n,b);
}
int DepthFirstSearch(char a[100][100],int n,int n1,int parent[],char b[n][n])//Graph01.txt
{
	int i,j,current,flag=0;
	stack *top;
	int visited[n];
	
	parent[n1]=-1;
	for(i=0;i<n;i++)
	{
		visited[i]=0;
	}
	
	pushStack(&top,n1);
	while(isEmpty(&top))
	{
		current=popStack(&top);
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
void copyMatrix(char a[100][100],int n,char b[n][n],int parent[n],int start)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(i!=start)
		{
			b[i][parent[i]]='r';
			b[parent[i]][i]='r';
		}
	}	
}



