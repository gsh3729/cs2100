/*
	PROGRAMMER'S NAME : G SRIHARSHA
	ROLLNO:111601005
	PROGRAM DESCRIPTION :C program to find an Eulerian circuit in a given graph, if it has one. 
	PROGRAM NAME : counting_pieces.c
	DATE : 10/10/17
	*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct queue
{
	char data;
	struct queue *next;
}queue;

int readmatrix(char a[100][100]);
void enQueue(queue **front,queue **rear,int value);//declaring function prototypes
int deQueue(queue **front,queue **rear);
int isEmpty(queue **front);
void degen(int n,char b[n][n], int degenerate[n]);
void vertexDeletion(int n,char b[n][n],int vertex);
void colorMatrix(char a[100][100],int n,int degenerate[n],char adjcolor[15][n]);
int checkmatrix(int n,char b[n][n]);

void main()
{
	char a[100][100];
	int n,start,i=0,j=0;
	
	
	n=readmatrix(a); //function to read adjacent matrix from the input file
	char b[n][n],adjcolor[n][15];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			b[i][j]=a[i][j];
		}
	}
	int degenerate[n];
	degen(n,b,degenerate);
	printf("\n degenearte matrix\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",degenerate[i]);
	}
	colorMatrix(a,n,degenerate,adjcolor);
}
void colorMatrix(char a[100][100],int n,int degenerate[n],char adjcolor[n][15])
{
	int i;
	for(i=0;i<n;i++)
	{
		strcpy(adjcolor[i],"NULL");
	}
	/*for(i=0;i<n;i++)
	{
		printf("%s\n",adjcolor[i] );
	}*/
	//for(i=n-1;i<=0;i++)
	//{

		//adjcolor[n]

}
void degen(int n,char b[n][n], int degenerate[n])
{
	
	int i,j,k,x=0;
	while(checkmatrix(n,b))
	{
		for(i=0;i<n;i++)
		{
			k=0;
			for(j=0;j<n;j++)
			{
				if(b[i][j]=='1')
				{
					k++;
				}
			}
			if(k<=5)
			{
				degenerate[x]=i;
				x++;	
				vertexDeletion(n,b,i);
			}
		}
	}
}
int checkmatrix(int n,char b[n][n])
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(b[i][j]=='1')
			{
				return 1;
			}
		}
	}
	return 0;
}
void vertexDeletion(int n,char b[n][n],int vertex)
{
	int i;
	for(i=0;i<n;i++)
	{
		b[vertex][i]='0';
		b[i][vertex]='0';
	}
}

/*void writeDotfile(char a[100][100],int n)
{
	char file[30];
	int i,j;
	FILE *p;
	printf("\n Enter the output dotfile name: ");
	scanf("%s",file);
	p=fopen(file,"w");
	if(p==0)   // Check if the file was opened correctly 
  	{
  		printf("Error in opening the file\n");
   		return;
  	}
	else
	{
		fprintf(p,"graph G{\n");
		for(i=0;i<n;i++)
    	{
        	fprintf(p,"%d [color=%s,style=filled]\n",i,adjcolor[i]);
    	}
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
} */


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


