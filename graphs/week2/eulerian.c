/*
	PROGRAMMER'S NAME : G SRIHARSHA
	ROLLNO:111601005
	PROGRAM DESCRIPTION :C program to find an Eulerian circuit in a given graph, if it has one. 
	PROGRAM NAME : counting_pieces.c
	DATE : 10/10/17
	*/
#include <stdio.h>
#include <stdlib.h>


typedef struct queue
{
	char data;
	struct queue *next;
}queue;
typedef struct node
{
	int data;
	struct node *next;
}node;
int readmatrix(char a[100][100]);
void enQueue(queue **front,queue **rear,int value);//declaring function prototypes
int deQueue(queue **front,queue **rear);
int isEmpty(queue **front);
int isEulerian(char a[100][100],int n);
int BreadthFirstSearch(char a[100][100],int n,int n1);
void linkedlist(node **head,int value);
void printlinkedlist(node **head);

void main()
{
	char a[100][100];
	int n,start,i=0,j=0;
	
	n=readmatrix(a); //function to read adjacent matrix from the input file
	i=isEulerian(a,n);	
	if(i==1)
	{
		printf("\n Eulerian circuit exists in the given graph\n");
		printf("\n Enter the starting vertex of the eulerian circuit :");
		scanf("%d",&start);
		printEulerian(a,n,start);
	}		 
}
int printEulerian(char a[100][100],int n,int start)
{
	


}
int isEulerian(char a[100][100],int n) //Egraph_2.txt
{
	int i,j,k,deg;
	i=BreadthFirstSearch(a,n,1);
	if(i==1)
	{
		for(i=0;i<n;i++)
		{
			deg=0;
			for(j=0;j<n;j++)
			{
				if(a[i][j]=='1')
				{
					deg++;
				}
			} 
			if((deg%2)!=0)
			{
				printf("\n No Eulerian circuit is found.Since all vertices don't have even degree\n");
				return 0;
			}
		}		
	}
	else
	{
		printf("\n No Eulerian circuit is found.Since it is not connected\n");
		return 0;
	}
	return 1;
}

int BreadthFirstSearch(char a[100][100],int n,int n1)//Graph01.txt
{
	int i,j,current,flag=1,k=0;
	int visited[n];
	queue *front=NULL,*rear=NULL;
	
	for(i=0;i<n;i++)
	{
		visited[i]=0;
	}
	visited[n1]=1;
	for(i=0;i<n;i++)
	{
		k=0;
		for(j=0;j<n;j++)
		{
			if(a[i][j]=='0')
			{
				k++;
			}
		}
		if(k==n)
		{
			visited[i]=1;
		} 
	}
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
					visited[j]=1;
					enQueue(&front,&rear,j);
				}
			}
		}		
	}
	for(i=0;i<n;i++)//keeping all nodes as unvisited
	{
		if(visited[i]!=1)
		{
			printf("%d hai",i);
			flag=0;
			break;
		}
	} 
	if (flag==1)
	{
		return 1;
	}
	else
	{
		return 0;
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
void linkedlist(node **head,int value)
{
	int i;
	node *a,*temp;
	temp=*head;
	a = (node*)malloc(sizeof(node));
	a->data=value;
	
	while((temp->next)!=NULL)
	{
		temp=temp->next;
	}
	temp->next=a;
}
void printlinkedlist(node **head) // printing linked list data using pointers in it
{
	node *temp;
	temp=*headRef;
	while(temp->next!=NULL) 
	{
		printf(" %d",temp->data);
		temp=temp->next;
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




