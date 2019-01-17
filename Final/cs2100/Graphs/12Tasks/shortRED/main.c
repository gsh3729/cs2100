/*
	PROGRAMMER'S NAME : G SRIHARSHA
	ROLLNO:111601005
	PROGRAM DESCRIPTION :program, which given a graph and two nodes in that graph tests whether these two nodes are connected and also prints out one of the shortest paths between them (as a sequence of vertices) and reports the distance between the two given nodes.
	PROGRAM NAME : path2nodes.c
	DATE : 3/10/17
	*/
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "readWrite.h"
#include "main.h"



// void BreadthFirstSearch(char a[100][100],int n,int n1,int n2,int parent[100]);
// void printpath(char a[100][100],int parent[], int j,int *distance,int *red);
// int path(int parent[],int i,int j,int n2);


void main()
{
	char a[100][100];
	int n,n1,n2,i=1,j=0,*ptrdist,distance,red;//,reddist,*red;
	ptrdist=&distance;
	*ptrdist=0;
	// red=&reddist;
	red=0;


	n=readmatrix(a); //function to read adjacent matrix from the input file
	int parent[n];
	
	printf("\n Enter the two names of the nodes :\n");
	scanf(" %d %d",&n1,&n2); 

 	BreadthFirstSearch(a,n,n1,n2,parent);
 		
 	//printf("\n Given two nodes %d and %d are connected",n1,n2);
 	printf(" Shortest path between nodes %d and %d is ",n1,n2);
 	printpath(a,parent,n2,ptrdist,&red);
 	printf("\n Distance between nodes %d and %d is %d",n1,n2,*ptrdist);	
 	printf("\n Number of RED edges between nodes %d and %d is %d",n1,n2,red);
    writeDotfile(a,n,n2,parent);		 	
}
void BreadthFirstSearch(char a[100][100],int n,int n1,int n2,int parent[])//Graph01.txt
{
	int i,j,k,current,flag=0,e,d=0;
	queue *front=NULL,*rear=NULL;
	int visited[n],red[n],level[n];

	parent[n1]=-1;
	for(i=0;i<n;i++)  //keeping all nodes as unvisited
	{
		visited[i]=0;
		red[i]=-1;
		level[i]=-1;
	}
	visited[n1]=1;
	level[n1]=0;
	red[n1]=0;
	enQueue(&front,&rear,n1);
	while(isEmpty(&front)) //terminating condition
	{
		current=deQueue(&front,&rear); //pushing it to queue to explore next
		for(j=0;j<n;j++)
		{
			if(a[current][j]!='0') //checking whether edge is there or not
			{
				if(visited[j]==0) //if it is previously unvisited you visit that vertex now
				{
					level[j]=level[current]+1;
					// if(a[current][j]=='1')
					// {
					// 	red[j]=red[current]+1;
					// }
					// else
					// {
					// 	red[j]=red[current];
					// }
					//e=0;
					
					for(k=0;k<n;k++)  
					{
						if(a[k][j]!='0')
						{
							if(level[k]==level[current])
							{
								
							
									if(a[k][j]=='1')
									{
										d=1;
									}
									else
									{
										d=0;
									}
									if(red[j] < (red[k]+d))
									{
										red[j]=red[k]+d;
										parent[j]=k;
										
									}
								
							}
						}
					}
					visited[j]=1;
					enQueue(&front,&rear,j);
				}
			}
		}		
	}
	
}

void printpath(char a[100][100],int parent[], int i,int *ptrdist,int *red) // function which prints the path between two nodes 
{
    if(parent[i]==-1)
    {
      	printf("%d ", i);
		return;
    }
    if(a[i][parent[i]]=='1')
    {
    	(*red)=(*red)+1;
    }
    (*ptrdist)= (*ptrdist)+1;
    printpath(a,parent, parent[i],ptrdist,red);
    printf("%d ", i);
}

int path(int parent[],int i,int j,int n2) //function which checks whether 2 required vertices has edge or not 
{
	int flag1=0,flag2=0,temp;
	if(parent[i]==j || parent[j]==i)
	{
		temp=n2;
		while(temp!=-1)
		{
			if(temp==i)
			{
				flag1++;
				break;
			}
			temp=parent[temp];
		}
		temp=n2;
		while(temp!=-1)
		{
			if(temp==j)
			{
				flag2++;
				break;
			}
			temp=parent[temp];
		}
	}
	else
	{
		return -1;
	}
	if(flag1==1 && flag2==1)
	{
		return 1;
	}
}
