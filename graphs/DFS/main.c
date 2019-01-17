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
	//visited[n1]=1;
	pushStack(&top,n1);
	while(isEmpty(&top))
	{
		current=popStack(&top);
		
		if(visited[current]==0)
		{
			visited[current]=1;
			printf(" %d\t",current );
			for(j=n-1;j>=0;j--)
			{
				if(a[current][j]=='1' && visited[j]==0)
				{
					b[j][current]='r';
					b[current][j]='r';
					parent[j]=current;
					
					pushStack(&top,j);
					
				}
			}
			
		}		
	}
	
	return 1;
	
}
	

