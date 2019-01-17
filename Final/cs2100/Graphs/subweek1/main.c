#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node //creating a structure node and giving alias name 'node'
{
	int data;
	struct node *next;
	struct node *pre;
}node;

typedef struct queue //structure declaration
{
	char data;
	struct queue *next;
}queue;

int readmatrix(char a[100][100]);
void enQueue(queue **front,queue **rear,int value);//declaring function prototypes
int deQueue(queue **front,queue **rear);
int isEmpty(queue **front);
void hamiltoninanCycle(char a[100][100],node **head,int n,int visited[n]);
void writeDotfile(char a[100][100],int n);
void formingCycle(char a[100][100],node **head);
void findMaximalPath(char a[100][100],node **head,int n,int visited[n]);
int BreadthFirstSearch(char a[100][100],int n,int n1,node **head,int visited[n],int parent[n]);
void printCircular(node **head);
void colorHamiltonian(char a[100][100],node **head);
void doublelinkedlist(node **head,int i);
int checkVertex(char a[100][100],node **temp,int n,int visited[n]);
node* goToLastVertex(node **head);
void randomPath(int parent[], int i,node **head,int visited[]);
void printdl(node **head);

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
/*void checkPath()
{
	node *temp=*head;
	while(temp!=NULL)
	{
		for(i=0;i<n;i++)
		{
			if(a[temp->value][i]=='1')
			{
				if(visited[i]==0)
				{
					return 1;
				}
			}
		}
		temp=temp->next;
	}
	return 0;
}*/
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
node* goToLastVertex(node **head)
{
	node *temp=*head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	return temp;
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
  
	return n;//function will return the size of the matrix
	
}
int BreadthFirstSearch(char a[100][100],int n,int n1,node **head,int visited[],int parent[n])//Graph01.txt
{
	int i,j,current,flag=1,k=0;
	
	queue *front=NULL,*rear=NULL;
	for(j=0;j<n;j++)
	{
		parent[j]=0;
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
	for(i=0;i<n;i++)
	{
		visited[i]=0;
	}
	randomPath(parent,k,head,visited);
	
	return  1;
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
void doublelinkedlist(node **head,int i)
{
	node *temp=*head,*newnode;

	if(*head==NULL)
	{
		newnode=(node*)malloc(sizeof(node));
		newnode->data=i;
		
		*head=newnode;
		newnode->pre=NULL;
		newnode->next=NULL;
	}
	else
	{
		newnode=(node*)malloc(sizeof(node));
		newnode->data=i;
		
		while((temp->next)!=NULL)
		{
			temp=temp->next;
		}

		temp->next=newnode;
		newnode->pre=temp;
		newnode->next=NULL;

	}
}
void printCircular(node **head)
{
	node *temp;
	temp=*head;
	do
	{
		printf(" %d",temp->data);
		temp=temp->next;
	}while((temp)!=(*head));
	
	printf(" %d",(*head)->data);
	printf("\n");
	
	return;
}
void printdl(node **head)
{
	node *temp;
	temp=*head;
	while((temp)!=NULL)
	{
		printf(" %d",temp->data);
		temp=temp->next;
	}
	
	printf("\n");
	
	return;
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
