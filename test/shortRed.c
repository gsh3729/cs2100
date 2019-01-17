/*
	PROGRAMMER'S NAME : G SRIHARSHA
	ROLLNO:111601005
	PROGRAM DESCRIPTION :program, which given a graph and two nodes in that graph tests whether these two nodes are connected and also prints out one of the shortest paths between them (as a sequence of vertices) and reports the distance between the two given nodes.
	PROGRAM NAME : path2nodes.c
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
int BreadthFirstSearch(char a[100][100],int n,int n1,int n2,int parent[100]);
void printpath(int parent[], int j,int *distance);
int red1(char a[100][100],int parent[], int i,int *d);
void writeDotfile(char a[100][100],int n,int n2,int parent[]);
void main()
{
	char a[100][100];
	int n,n1,n2,i=1,j=0,*ptrdist,distance;
	ptrdist=&distance;
	*ptrdist=0;

	n=readmatrix(a); //function to read adjacent matrix from the input file
	int parent[n];
	
		printf("\n Enter the two names of the nodes :\n");
		scanf(" %d %d",&n1,&n2); 

 		j=BreadthFirstSearch(a,n,n1,n2,parent);
 		if(j==1)
 		{
 			//printf("\n Given two nodes %d and %d are connected",n1,n2);
 			printf("\n Shortest path between nodes %d and %d is ",n1,n2);
 			printpath(parent,n2,ptrdist);
 			printf("\n Distance between nodes %d and %d is %d\n\n",n1,n2,*ptrdist);	
            		
 		}
 		else if(j==-1)
 		{
 			printf("\n Given two nodes %d and %d are not connected",n1,n2);
 		}
 		
 	
}
int red1(char a[100][100],int parent[], int i,int *d)
{
	if(parent[i]==-1)
   	{
		return *d;
    	}
	if(a[i][parent[i]]=='1')
    	{
		(*d)= (*d)+1;
	}
    	printpath(parent, parent[i],d);
    	
}	
int BreadthFirstSearch(char a[100][100],int n,int n1,int n2,int parent[])//Graph01.txt
{
	int i,j,current,flag=0,m=1,*d;
	queue *front=NULL,*rear=NULL;
	int visited[n],red[n],level[n],bestparent[n];
	char c;

	parent[n1]=-1;
	for(i=0;i<n;i++)  //keeping all nodes as unvisited
	{
		visited[i]=0;
		red[i]=0;
		level[i]=0;
	}
	visited[n1]=1;
	level[n1]=1;
	enQueue(&front,&rear,n1);
	while(isEmpty(&front)) //terminating condition
	{
		current=deQueue(&front,&rear); //pushing it to queue to explore next
		m++;
		for(j=0;j<n;j++)
		{
			
			if(a[current][j]!='0') //checking whether edge is there or not
			{
				level[j]=m;
				
				if(visited[j]==0) //if it is previously unvisited you visit that vertex now
				{
					
					*d=0;
					red[j]=red1(a,bestparent,j,d);
					
					c=a[current][j];
					
					visited[j]=1;
					enQueue(&front,&rear,j);
					if(j==n2)
					{
						flag=1;
					}
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
void printpath(int parent[], int i,int *ptrdist) // function which prints the path between two nodes 
{
    if(parent[i]==-1)
    {
      	printf("%d ", i);
		return;
    }
    (*ptrdist)= (*ptrdist)+1;
    printpath(parent, parent[i],ptrdist);
    printf("%d ", i);
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

void writeDotfile(char a[100][100],int n,int n2,int parent[]) //function to write dot file
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
				if(a[i][j]=='1')
				{
				
						fprintf(p,"%d--%d;\n",i,j);//printing the adjacent matrix to dot file
					
				}
			}
		}
		fprintf(p,"}");
		fclose(p);//closing the file
	}
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









