#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "linkedlist.h"
#include "readWriteBfs.h"


void hamiltoninanCycle(char a[100][100],node **head,int n,int visited[n]);
void formingCycle(char a[100][100],node **head);
void findMaximalPath(char a[100][100],node **head,int n,int visited[n]);
void colorHamiltonian(char a[100][100],node **head);
int checkVertex(char a[100][100],node **temp,int n,int visited[n]);
void randomPath(int parent[], int i,node **head,int visited[]);


void main()
{
	int i,n,k;
	char a[100][100];
	node *head;
	n=readmatrix(a);
	int visited[n],parent[n];
	for(i=0;i<n;i++)
	{
		visited[i]=0;
	}
	k=BreadthFirstSearch(a,n,10,visited,parent);
	for(i=0;i<n;i++)
	{
		visited[i]=0;
	}
	randomPath(parent,k,&head,visited);
	/*for(i=0;i<n;i++)
	{
		printf("%d ",visited[i]);
	}*/
	
	findMaximalPath(a,&head,n,visited);
	hamiltoninanCycle(a,&head,n,visited);
	printf(" Hamiltonian Cycle is ");
	printCircular(&head);
	colorHamiltonian(a,&head);
	writeDotfile(a,n);
}

