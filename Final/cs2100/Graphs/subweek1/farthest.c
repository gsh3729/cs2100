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

int readmatrix(char a[100][100]);
void enQueue(queue **front,queue **rear,int value);//declaring function prototypes
int deQueue(queue **front,queue **rear);
int isEmpty(queue **front);
void printpath(int parent[], int i);
int BreadthFirstSearch(char a[100][100],int n,int n1,int parent[]);

void main()
{
	char a[100][100];
	int n,n1,n2,i=1,j=0,x,y;
	
	n=readmatrix(a); //function to read adjacent matrix from the input file
	int parent[n];

	x=BreadthFirstSearch(a,n,6,parent);
	for(i=0;i<n;i++)  //keeping all nodes as unvisited
	{
		parent[i]=0;
	}
	y=BreadthFirstSearch(a,n,x,parent);
	printpath(parent,y);


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

int BreadthFirstSearch(char a[100][100],int n,int n1,int parent[])//Graph01.txt
{
	int i,j,current,flag=0,k=0;
	queue *front=NULL,*rear=NULL;
	int visited[n];

	
	for(i=0;i<n;i++)  //keeping all nodes as unvisited
	{
		visited[i]=0;
	}
	visited[n1]=1;
	parent[n1]=-1;

	enQueue(&front,&rear,n1);
	while(isEmpty(&front))
	{
		current=deQueue(&front,&rear);//pushing it to queue to explore next
		for(j=0;j<n;j++)
		{
			if(a[current][j]=='1') //if it is previously unvisited you visit that vertex now
			{ 
				if(visited[j]==0)
				{
					parent[j]=current;
					visited[j]=1;
					enQueue(&front,&rear,j);
					k=j;
				}
			}
		}		
		
	}
	return k;
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
   /*	printf("%s\n",filename);//printing the input filename
	printf("%s\n",file); 
	printf("%s\n",type);//printing the type of the matrix
	printf("%d\n",n);//printing the size of the adjacent matrix
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%c",a[i][j]);//printing the adjacent matrix
		}
		printf("\n");
	} */
	return n;//function will return the size of the matrix
	
}


void enQueue(queue **front,queue **rear,int value)//enqueue function
{
	queue *newnode;
	newnode=(queue *)malloc(sizeof(queue));
	newnode->data=value;
	if(isEmpty(front))
	{
		(*rear)->next=newnode;
	}
	else
	{
		*front=newnode;	
	}
	*rear=newnode;		
}
int deQueue(queue **front,queue **rear)//dequeue function
{
	int value;
	if(!isEmpty(front))
	{
		printf("\n queue is empty");
		return -1;
	}
	else if(*front==*rear)
	{
		value=(*front)->data;
		*front = NULL;
		*rear = NULL;
		return value;
	}
	else
	{
		value=(*front)->data;
		*front=(*front)->next;
		return value;
	}


}
int isEmpty(queue **front)//checking whether queue is empty or not
{
	if (*front == NULL)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

