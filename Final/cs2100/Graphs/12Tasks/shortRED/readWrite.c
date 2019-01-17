/*
	PROGRAMMER'S NAME : G SRIHARSHA
	ROLLNO:111601005
	PROGRAM DESCRIPTION :program, which given a graph and two nodes in that graph tests whether these two nodes are connected and also prints out one of the shortest paths between them (as a sequence of vertices) and reports the distance between the two given nodes.
	PROGRAM NAME : path2nodes.c
	DATE : 3/10/17
	*/
#include <stdio.h>
#include <stdlib.h>
#include "readWrite.h"
#include "main.h"

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
				if(a[i][j]!='0')
				{
					if(path(parent,i,j,n2)==1)
					{
						if(a[i][j]=='1')
						{
							fprintf(p,"%d--%d [style=dotted,color=red];\n",i,j);	
						}
						if(a[i][j]=='2')
						{
							fprintf(p,"%d--%d [style=dotted,color=green];\n",i,j);	
						}
						if(a[i][j]=='3')
						{
							fprintf(p,"%d--%d [style=dotted,color=blue];\n",i,j);	
						}
						
					}
					else
					{
						if(a[i][j]=='1')//printing the adjacent matrix to dot file
						{
							fprintf(p,"%d--%d [color=red];\n",i,j);	
						}
						if(a[i][j]=='2')
						{
							fprintf(p,"%d--%d [color=green];\n",i,j);	
						}
						if(a[i][j]=='3')
						{
							fprintf(p,"%d--%d [color=blue];\n",i,j);	
						}
						
					}
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








