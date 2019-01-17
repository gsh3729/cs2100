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
void findDegenerateMatrix(int n,char b[n][n], int degenerate[n]);
void vertexDeletion(int n,char b[n][n],int vertex);
int checkMatrix(int n,char b[n][n]);
void colorMatrix(char a[100][100],int n,int degenerate[n],int adjcolor[n]);
int checkAdjacentColor(char a[100][100],int n,int i, int adjcolor[n]);
void writeDotfile(char a[100][100],int n,int adjcolor[n]);

void main()
{
	char a[100][100];
	int n,start,i=0,j=0;
	
	
	n=readmatrix(a); //function to read adjacent matrix from the input file
	char b[n][n];
	int adjcolor[n];  //matrix which stores colors of vertices
	for(i=0;i<n;i++)
	{
		adjcolor[i]=-1;  //keeping all vertices as uncolored
		for(j=0;j<n;j++)  //creatiing a copy of adjacent matrix
		{
			b[i][j]=a[i][j];
		}
	}
	int degenerate[n];
	findDegenerateMatrix(n,b,degenerate); //function to find degenerate matrix
	printf("\n degen\n");
	/*for(i=0;i<n;i++) //printing degenerate matrix
	{
		printf("%d ",degenerate[i]);
	}*/
	colorMatrix(a,n,degenerate,adjcolor); //function to color all vertices
	printf("\n color\n");
	/*for(i=0;i<n;i++) //printing color matrix
	{
		printf("%d ",adjcolor[i]);
	}*/
	printf("\n");
	writeDotfile(a,n,adjcolor); //function to write a new dot file with vertices colored
}
void colorMatrix(char a[100][100],int n,int degenerate[n],int adjcolor[n]) //function to color all vertices
{
	int i;
	for(i=n-1;i>=0;i--)  //coloring is done from back side of degenerate matrix
	{
		checkAdjacentColor(a,n,i,adjcolor);//function will check adjacent vertices color and give a different  color to the vertex 
	}
}
int checkAdjacentColor(char a[100][100],int n,int i, int adjcolor[n])
{
	int j,x[6];
	for(j=0;j<6;j++) //array to store whether a adjacent vertex is having that color or not 
	{
		x[j]=0;
	}
	for(j=0;j<n;j++)
	{ 
		if(a[i][j]=='1' || a[j][i]=='1')
		{
			if(adjcolor[j]==1) //updates the array x 
			{
				x[0]=1;
			}
			if(adjcolor[j]==2)
			{
				x[1]=1;
			}																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																
			if(adjcolor[j]==3)
			{
				x[2]=1;
			}
			if(adjcolor[j]==4)
			{
				x[3]=1;
			}
			if(adjcolor[j]==5)
			{
				x[4]=1;
			}
			if(adjcolor[j]==6)
			{
				x[5]=1;
			}		
		}
	}
	for(j=0;j<n;j++)
	{
		if(x[j]==0)//assigns a color to the vertex
		{
			adjcolor[i]=j+1;
			break;
		}
	}

}
void findDegenerateMatrix(int n,char b[n][n], int degenerate[n])
{
	int i,j,k,x=0;
	while(checkMatrix(n,b))
	{ 
		for(i=0;i<n;i++)
		{
			k=0;
			for(j=0;j<n;j++)
			{
				if(b[i][j]=='1') //finding the degree
				{
					k++;
				}
			}
			if(k<=5)
			{
				degenerate[x]=i; //if degree less than 5 ,vertex goes to degenerate matrix
				x++;	
				vertexDeletion(n,b,i);
			}
		}
	}
}
int checkMatrix(int n,char b[n][n])  //checking if all edges are visited or not
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
void vertexDeletion(int n,char b[n][n],int vertex) //delete the vertex
{
	int i;
	for(i=0;i<n;i++)
	{
		b[vertex][i]='0';
		b[i][vertex]='0';
	}
}

void writeDotfile(char a[100][100],int n,int adjcolor[n])
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
		for(i=0;i<n;i++) //giving colors to vertices
    	{
    		if(adjcolor[i]==1)
    		{
        		fprintf(p,"%d [color=red,style=filled]\n",i);
        	}
        	else if(adjcolor[i]==2)
        	{
				fprintf(p,"%d [color=yellow,style=filled]\n",i);
        	}
        	else if(adjcolor[i]==3)
        	{
				fprintf(p,"%d [color=green,style=filled]\n",i);
        	}else if(adjcolor[i]==4)
        	{
				fprintf(p,"%d [color=orange,style=filled]\n",i);
        	}else if(adjcolor[i]==5)
        	{
				fprintf(p,"%d [color=pink,style=filled]\n",i);
        	}else if(adjcolor[i]==6)
        	{
				fprintf(p,"%d [color=cyan,style=filled]\n",i);
        	}
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


