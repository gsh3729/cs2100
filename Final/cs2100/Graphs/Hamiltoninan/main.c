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
	int i,n;
	char a[100][100];
	node *head;
	n=readmatrix(a);
	int visited[n],parent[n];
	for(i=0;i<n;i++)
	{
		visited[i]=0;
	}
	BreadthFirstSearch(a,n,10,&head,visited,parent);
	for(i=0;i<n;i++)
	{
		visited[i]=0;
	}
	randomPath(parent,k,head,visited);
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
void hamiltoninanCycle(char a[100][100],node **head,int n,int visited[])
{
	int i;
	node *temp,*temp1,*x,*y;
	formingCycle(a,head);
	
	for(i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			temp=*head;
			temp1=temp;
			do
			{
				if(a[i][temp->data]=='1') //checking whether there is extended edge from any of the vertex on the cycle
				{
					visited[i]=1;
					x=(struct node*)(malloc(sizeof(struct node)));	//creating a new node
					x->data=i;
					x->next=NULL; //keeping it at the end of the double linked list

					y=temp->next; 
					y->pre=NULL; 
					*head=y; //assigning head to new double linked list
					temp->next=x; //giving connectioons to new node
					x->pre=temp;	
				
					i=0; //to again start checking in the new double linked list
					formingCycle(a,head); //converts doublelinked list to circularlinkedlist(cycle) 
					break;
				}
				temp=temp->next;
			}while(temp!=temp1);//terminating condition for loop to end
		}
	}
	
}

void formingCycle(char a[100][100],node **head)
{
	node *temp=(*head)->next;
	node *temp1,*temp2,*temp3,*temp4;
	
	temp=temp->next;
	while(temp!=NULL)
	{
		if(a[(*head)->data][temp->data]=='1')
		{
			temp1=goToLastVertex(head); //last node
			if(a[temp1->data][(temp->pre)->data]=='1')
			{				
				temp2=temp1; //last node
				temp3=temp->pre; //good position previous node
				
				while(temp2!=temp)
				{
					temp4=temp2->pre;

					temp3->next=temp2;
					temp2->pre=temp3;

					temp3=temp2;
					temp2=temp4;
				}

				temp3->next=temp2;
				temp2->pre=temp3;
				
				temp->next=*head;
				((*head)->pre)=temp;
				
				return;
				
			}	
		}
		temp=temp->next;
	}
	
}

void findMaximalPath(char a[100][100],node **head,int n,int visited[n])
{
	node *temp,*newnode;
	temp=*head;
	int i;
	while(checkVertex(a,head,n,visited))
	{
		
		for(i=0;i<n;i++)
		{
			if(a[(*head)->data][i]=='1')
			{
				if(visited[i]==0)
				{
					visited[i]=1;
					
					newnode = (node*)malloc(sizeof(node));
					newnode->data=i;
					
					newnode->next=*head;
					newnode->pre=NULL;

					(*head)->pre=newnode;
					*head=newnode;
					break;
				}
			}
		}
	}
	temp=goToLastVertex(head);
	while(checkVertex(a,&temp,n,visited))
	{
		
		for(i=0;i<n;i++)
		{
			if(a[temp->data][i]=='1')
			{
				if(visited[i]==0)
				{
					visited[i]=1;

					newnode = (node*)malloc(sizeof(node));
					newnode->data=i;

					newnode->next=NULL;

					temp->next=newnode;
					newnode->pre=temp;

					temp=temp->next;
					break;
				}
			}
		}
	}
	
}

int checkVertex(char a[100][100],node **temp,int n,int visited[n])
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[(*temp)->data][i]=='1')
		{
			if(visited[i]==0)
			{
				
				return 1;
			}
		}
	}
	return 0;
}
					


void randomPath(int parent[], int i,node **head,int visited[]) // function which prints the path between two nodes 
{
    if(parent[i]==-1)
    {
    	visited[i]=1;
    	
      	doublelinkedlist(head,i);
		return;
    }
    randomPath(parent, parent[i],head,visited);
    visited[i]=1;
    doublelinkedlist(head,i);
   
}


void colorHamiltonian(char a[100][100],node **head)
{
	node *temp,*temp1;
	temp=*head;
	do
	{
		temp1=temp->next;
		if(a[temp->data][temp1->data]=='1')
		{
			a[temp->data][temp1->data]='r';
			a[temp1->data][temp->data]='r';
		}
		temp=temp1;
	}while(temp!=*head);
}

