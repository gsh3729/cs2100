/*
Name - Arpit Singh
Roll number - 111601031
Program : This program is suppose to read simple undirected graph from the matrix and plot it in the xdot 
*/

//declaring all the necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

//declaring the important structure
	struct Graph
	{
		int vc;
		int **a;
		int graphName[100];
	};

//declaring the important functions
	int readGraph (char filename[] , struct Graph * graph);
	void makeGraph (struct Graph *graph , FILE *file);

//main function
	int main ()
	{
		//asking for the name of the input file
			char filename[100];
			printf("Enter the name of the file \n");
			scanf("%s",filename);

		//declaring the structure and then reading it from the file
			struct Graph graph1;
			int check = readGraph (filename , &graph1);

			if (check == 0)
				return 0;
		//declaring the output file pointer and then making it
			FILE *file;
			makeGraph ( &graph1 , file);
		
		return 0;


	}

int readGraph (char filename[] , struct Graph *graph)
//This function takes the filename as the input and then returns wether file is there or not
{
	//asking for the name of the input file and opening it
		FILE *file ;
		file = fopen (filename , "r");

		if (file == 0)
		{
			printf("Error in opening the file \n");
			return 0;
		}

	//scanning the initial details
		char temp[1000];
		int success ;
		success = fscanf(file , "%s" , temp);
		success = fscanf(file , "%s" , temp);

		success = fscanf(file, "%d" , &graph -> vc);
		int n = graph -> vc;

	//declaration of the matrix using malloc
		graph ->a = (int **)malloc (n * sizeof (int *));
		for (int i =0 ; i<n ; i++)
		{
			graph->a[i] = (int*)malloc (n * sizeof(int));
		}

	//reading the file
		for (int i =0 ; i< n ; i++)
		{
			success = fscanf(file , "%s" , temp);

			for (int j =0 ; j < n ; j++)
			{
				graph ->a[i][j] = temp[j] - '0';
			}
		}

	//closing the file
	fclose (file);
	return 1;
}

void makeGraph (struct Graph *graph , FILE *file)
//This function takes the output file open it and make the dot file of the graph
{
	//asking for the name of the output file
		char output[100];
		printf("Enter the name of the output file\n");
		scanf("%s",output);

	//opening the output file
		file = fopen (output , "w");
	
	//printing the necesssary details
		fprintf(file , "graph one\n");
		fprintf(file , "{\n");

		int flag = 0; 		//this is to check the isolated vertices

		//printing the connected components
		int n = graph -> vc;
		for (int i =0 ; i < n ; i++)
		{
			for (int j = i ; j < n ; j++)
			{
				if (graph ->a[i][j] == 1)
					fprintf(file , "%d -- %d;\n" , i , j);
			}
		}

		//printing the isolated vertices
		for (int i =0 ; i < n ; i++)
		{
			flag = 0;

			for (int j =0 ; j < n ; j++)
				if (graph->a[i][j] != 0)
					flag = 1;

			if (flag == 0)
				fprintf( file , "%d;\n", i );
		}


		fprintf(file , "}\n");
}
