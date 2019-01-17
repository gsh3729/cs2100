/*
	PROGRAMMER'S NAME : G SRIHARSHA
	ROLLNO:111601005
	PROGRAM DESCRIPTION : program to read the adjacency matrix of a simple undirected graph, stored in a text file and generate a dot file for the same
	PROGRAM NAME : adj2dot.c
	DATE : 3/10/17
	*/
#include <stdio.h>
int readmatrix(char a[100][100]);//declaring function prototypes
void writeDotfile(char a[100][100],int n);

void main()
{
	char a[100][100],i,j,n;

	n=readmatrix(a);//function to read adjacent matrix from the input file
	writeDotfile(a,n);//function to write dot file 
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
		
	











		
