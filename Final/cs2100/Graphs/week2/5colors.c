/*
	PROGRAMMER'S NAME : G SRIHARSHA
	ROLLNO:111601005
	PROGRAM DESCRIPTION :Enhance 6colour.c to a 5-colouring algorithm using Kempe/Haewood idea. 
	PROGRAM NAME : 5colors.c
	*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct queue //structure declaration
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
int isVerticesConnected(char a[100][100],int n,int i,int j,int l,int adjcolor[n]);
int BreadthFirstSearch(int n,char a[n][n],int n1,int n2);

void main()
{
	char a[100][100];
	int n,start,i=0,j=0;
	
	
	n=readmatrix(a); //function to read adjacent matrix from the input file
	char b[n][n];
	int adjcolor[n]; //matrix which stores colors of vertices
	for(i=0;i<n;i++)
	{
		adjcolor[i]=-1; //keeping all vertices as uncolored
		for(j=0;j<n;j++) //creatiing a copy of adjacent matrix
		{
			b[i][j]=a[i][j];
		}
	}
	int degenerate[n];
	findDegenerateMatrix(n,b,degenerate);//function to find degenerate matrix
	printf("\n Degenerate Matrix\n");
	/*for(i=0;i<n;i++) //printing degenerate matrix
	{
		printf("%d ",degenerate[i]);
	}*/
	colorMatrix(a,n,degenerate,adjcolor);//function to color all vertices
	/*printf("\n color\n");
	for(i=0;i<n;i++) //printing color matrix
	{
		printf("%d ",adjcolor[i]);
	}*/ 
	printf("\n");
	writeDotfile(a,n,adjcolor); //function to write a new dot file with vertices colored
}
void colorMatrix(char a[100][100],int n,int degenerate[n],int adjcolor[n])//function to color all vertices
{
	int i;
	for(i=n-1;i>=0;i--) //coloring is done from back side of degenerate matrix
	{
		checkAdjacentColor(a,n,i,adjcolor); //function will check adjacent vertices color and give a different  color to the vertex 
	}
}
int checkAdjacentColor(char a[100][100],int n,int i, int adjcolor[n])
{
	int j,x[5],k=1,l;
	for(j=0;j<5;j++) //array to store whether a adjacent vertex is having that color or not 
	{
		x[j]=0;
	}
	for(j=0;j<n;j++)
	{ 
		if(a[i][j]=='1' || a[j][i]=='1')
		{
			if(adjcolor[j]==1)  //updates the array x 
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
					
		}
	}
	for(j=0;j<n;j++)
	{
		if(x[j]==0) //assigns a color to the vertex
		{
			adjcolor[i]=j+1;
			k=0;
			break;
		}
	}
	if(k==1) //k==1 when a vertex has 5 different color vertices adjacent to it  
	{
		for(j=0;j<n;j++)
		{
			if(a[i][j]=='1')
			{
				for(l=0;l<n;l++)
				{	
					if(a[i][l]=='1')
					{	
						if(isVerticesConnected(a,n,i,j,l,adjcolor)==0)//if that vertices are not connected then it will swap those colors and assign a color
						{
							k=0;
							break;
						}
					}
				}
			}
			if(k==0)
			{
				break;
			}
		}
	}
}
int isVerticesConnected(char a[100][100],int n,int i,int j,int l,int adjcolor[n])
{
	int p,q,color1,color2;
	char b[n][n];
	for(p=0;p<n;p++)//creating a copy
	{
		for(q=0;q<n;q++) 
		{
			b[p][q]=a[p][q];
		}
	}
	for(p=0;p<n;p++) //creating a new graph
	{
		if(adjcolor[p]!=adjcolor[j] && adjcolor[p]!=adjcolor[l])
		{
			for(q=0;q<n;q++) 
			{
				b[p][q]='0';
				b[q][p]='0';
			}
		}
	}
	if(BreadthFirstSearch(n,b,j,l))// if vertices are connected ,it returns 1
	{
		return 1;
	}
	else  
	{
		color1=adjcolor[j];
		color2=adjcolor[l];
		adjcolor[j]=color2;
		for(p=0;p<n;p++)
		{
			if(adjcolor[p]==color1 || adjcolor[p]==color2)
			{
				if(BreadthFirstSearch(n,b,j,p)) //swapping the colors
				{
					if(adjcolor[p]==color1)
					{
						adjcolor[p]=color2;
					}
					if(adjcolor[p]==color2)
					{
						adjcolor[p]=color1;
					}
				}
			}
		}
		adjcolor[i]=color1;
		return 0;
	}
}
int BreadthFirstSearch(int n,char a[n][n],int n1,int n2)//returns 1 if given two vertices are connected ,o/w -1
{
	int i,j,current;
	queue *front=NULL,*rear=NULL;
	int visited[n];
	for(i=0;i<n;i++) //keeping all nodes as unvisited
	{
		visited[i]=0;
	}
	visited[n1]=1;
	enQueue(&front,&rear,n1);
	while(isEmpty(&front)) //terminating condition
	{
		current=deQueue(&front,&rear); 
		for(j=0;j<n;j++)
		{
			if(a[current][j]=='1') //checking whether edge is there or not
			{
				if(visited[j]==0) //if it is previously unvisited you visit that vertex now
				{
					visited[j]=1;
					enQueue(&front,&rear,j);//pushing it to queue to explore next
					if(j==n2)
					{
						return 1;
					}
				}
			}
		}		
		
	}
	return -1;
}
void findDegenerateMatrix(int n,char b[n][n], int degenerate[n]) //to find degenerate matrix
{
	int i,j,k,x=0;
	while(checkMatrix(n,b))
	{ 
		for(i=0;i<n;i++)
		{
			k=0;
			for(j=0;j<n;j++) //finding the degree
			{
				if(b[i][j]=='1')
				{
					k++;
				}
			}
			if(k<=5)//if degree less than 5 ,vertex goes to degenerate matrix
			{
				degenerate[x]=i;
				x++;	
				vertexDeletion(n,b,i);
			}
		}
	}
}
int checkMatrix(int n,char b[n][n]) //checking if all edges are visited or not
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


