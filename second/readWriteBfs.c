#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

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
int BreadthFirstSearch(char a[100][100],int n,int n1,int n2,int parent[n],int visited[n])//Graph01.txt
{
	int i,j,current,flag=0,k=0,l=0;
	
	queue *front=NULL,*rear=NULL;
	visited[n1]=1;
	parent[n1]=-1;


	enQueue(&front,&rear,n1);
	
	while(isEmpty(&front))
	{
		current=deQueue(&front,&rear);//pushing it to queue to explore next
		// connect[k]=current;
		// k++;
		for(j=0;j<n;j++)
		{
			if(a[current][j]=='1') //if it is previously unvisited you visit that vertex now
			{ 
				if(visited[j]==0)
				{
					parent[j]=current;
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