#include <stdio.h>

void main()
{
	int i;
	char a[100][100];
	node *head;
	n=readmatrix(a);
	BreadthFirstSearch(a,n,0,&head);
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
int BreadthFirstSearch(char a[100][100],int n,int n1,node **head)//Graph01.txt
{
	int i,j,current,flag=1,k=0;
	int visited[n];
	queue *front=NULL,*rear=NULL;
	
	for(i=0;i<n;i++)
	{
		visited[i]=0;
	}
	visited[n1]=1;
	
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
					doublelinkedlist(head,j);
				}
			}
		}		
	}
	return  1;
}
