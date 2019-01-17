/*
	PROGRAMMER'S NAME : G SRIHARSHA
	ROLLNO:111601005
	PROGRAM DESCRIPTION :program, which given a graph and two nodes in that graph tests whether these two nodes are connected. 
	PROGRAM NAME : path_finder.c
	DATE : 3/10/17
	*/
#include <stdio.h>
#include <stdlib.h>


typedef struct queue
{
	char data;
	struct queue *next;
}queue;

void DepthFirstSearch(char a[100][100],int n,int start,int visited[n]);
void main()
{
	char a[100][100];
	int n,start,i=0,j=0;
	
	n=readmatrix(a); //function to read adjacent matrix from the input file
	char b[n][n];
	int parent[n],visited[n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			b[i][j]=a[i][j];
		}
	}
	printf("\n Enter the starting node :");
	scanf("%d",&start);

	DepthFirstSearch(a,n,b,start,visited);
	//writeDotfile(n,b);

}
void DepthFirstSearch(char a[100][100],int n,char b[n][n],int start,int visited[n])
{
	int i,j;
	visited[start]=1;
	for(i=0;i<n;i++)
	{
		if(a[start][j]=='1' && visited[j]==0)
		{
			b[start][j]='r';
			b[j][start]='r';
			DepthFirstSearch(a,n,b,j,visited);
		}
	}
}












