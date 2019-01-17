/*
	PROGRAMMER'S NAME : G SRIHARSHA
	ROLLNO:111601005
	PROGRAM DESCRIPTION :program which uses BFS to count the number of connected components in a graph and 
	generates a dot file for the graph, in which the edges of the BFS tree you trace is shown in a red colour.
	You include an edge into the BFS tree, only if that edge resulted in finding a previously unvisited vertex.

	PROGRAM NAME : redpieces.c
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
int BreadthFirstSearch(char a[100][100],int n,int n1,int visited[],int *connect);
int connected(char a[100][100],int n);
void writeDotfile(char a[100][100],int n);
void main()
{
	char a[100][100];
	int n,n1,n2,i=1,j=0;
	int parent[100];
	
	n=readmatrix(a); //function to read adjacent matrix from the input file
	connected(a,n); 
	writeDotfile(a,n);		 
}
int connected(char a[100][100],int n)
{
	int visited[n],connect[n][n],k=0,i,j;
	for(i=0;i<n;i++)
	{
		visited[i]=0;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			connect[i][j]=-1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (visited[i]==0)
		{
			BreadthFirstSearch(a,n,i,visited,connect[k]);
			k++;
		}
	}
	printf("\n No of connected components in graph is %d\n",k);
	printf("\n Connected components are \n");
	for(i=0;i<k;i++)
	{
		j=0;
		while(connect[i][j]!=-1)
		{
			printf("%d ",connect[i][j]);
			j++;
		}
		printf("\n");
	}
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
				else if(a[i][j]=='1')
				{
					fprintf(p,"%d--%d;\n",i,j);//printing the adjacent matrix to dot file
				}
				
			}
		}
		fprintf(p,"}");
		fclose(p);//closing the file
	}
}
int BreadthFirstSearch(char a[100][100],int n,int n1,int visited[],int *connect)//Graph01.txt
{
	int i,j,current,flag=0,k=0;
	queue *front=NULL,*rear=NULL;
	
	visited[n1]=1;
	enQueue(&front,&rear,n1);
	while(isEmpty(&front))
	{
		current=deQueue(&front,&rear);
		connect[k]=current;
		k++;
		for(j=0;j<n;j++)
		{
			if(a[current][j]=='1')
			{
				if(visited[j]==0)
				{
					a[current][j]='r';
					a[j][current]='r';
					visited[j]=1;
					enQueue(&front,&rear,j);
				}
			}
		}		
		
	}
	if (flag==1)
	{
		return 1;
	}
	else
	{
		return -1;
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
   	printf("%s\n",filename);//printing the input filename
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
	} 
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
	








