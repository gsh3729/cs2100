#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"



int readmatrix(char a[100][100],char filename[50])
{
	int i,j,n;
	char file[30],type[10];
	FILE *p;

	// printf("\n Enter the file name: ");//enter the input filename
	// scanf("%s",filename);
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
 //   	printf("%s\n",filename);//printing the input filename
	// printf("%s\n",file); 
	// printf("%s\n",type);//printing the type of the matrix
	// printf("%d\n",n);//printing the size of the adjacent matrix
	// for(i=0;i<n;i++)
	// {
	// 	for(j=0;j<n;j++)
	// 	{
	// 		printf("%c",a[i][j]);//printing the adjacent matrix
	// 	}
	// 	printf("\n");
	// } 
	return n;//function will return the size of the matrix
	
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
void writeDotfile(char a[100][100],int n,char filename[50],int dist[n][n])
{
	//char file[30];
	int i,j;
	FILE *p;
	char outputfilename[50];


	// i=0;
	// while(filename[i]!='.')
	// {
	// 	outputfilename[i]=filename[i];
	// 	i++;
	// }
	// outputfilename[i]='\0';
	// // printf("\n Enter the output dotfile name: ");
	// // scanf("%s",file);

	// printf("1%s\n",outputfilename );
	// strcat(outputfilename,"-distance.txt");
	// printf("2%s\n",outputfilename);

	strcat(filename,"-distance.txt");
	p=fopen(filename,"w");
	if(p==0)   /* Check if the file was opened correctly */
  	{
  		printf("Error in opening the file\n");
   		return;
  	}
	else
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				
				fprintf(p,"%d ",dist[i][j]);
				
			}
			fprintf(p,"\n");
		}
		
		fclose(p);//closing the file
	}
}