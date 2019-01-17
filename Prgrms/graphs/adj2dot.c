/*
Name - Arpit Singh
Roll number - 111601031
PC IP - 10.64.1.163
serial number - D
*/

//Note that the associativity followed here is left associativity

//declaring all the libraries
	#include <stdio.h>
	#include <stdlib.h>
	#include <limits.h>
	#include <string.h>

//declaring the structure which contains information about graphs
struct graphs
{
	int vc;
	int **a;
	char graphName[30];

};



//declaring all the necessary functions
	int readGraph (char filename[] , struct graphs* graph );
	void printGraph (struct graphs* graph);
	void makeGraph (struct graphs* graph , FILE *file);

//main function
	int main ()
	{
		char filename[100];
		//asking for the name of filename
		printf("Enter the name of the file \n");
		scanf("%s",filename);

		//calling the reading functions
		struct graphs graph1;
		int check = readGraph (filename , &graph1);

		//checking if the file entered is correct or not
		if (check == 0)
		return 0;
		//giving name to the graph
		strcpy (graph1.graphName , "Graph01");

		//printGraph (&graph1);


		//declaring the file pointer and making the graph in the odt file
		FILE *file;

		makeGraph ( &graph1  , file);
		return 0;
	}

	int readGraph (char filename[] , struct graphs* graph)
	//this function takes the AM file as the input and then scans the matrix and then return the matrix
	{
		FILE * file1;
		file1 = fopen (filename , "r");



		if (file1 == 0)
		{
			printf("error in opening the file\n");
			return 0;
		}

		char temp[1000];
		int success;
		success = fscanf(file1 , "%s" , temp);
		success = fscanf (file1 , "%s" , temp);



		success = fscanf(file1 , "%d" , &graph -> vc);


		int n = graph -> vc;
		graph ->a = (int **)malloc (n * sizeof (int *));
		for (int i = 0 ; i < n ; i++)
		{
			graph ->a[i] = (int *)malloc(n * sizeof(int));
		}



		int counter = 0;
		do
		{
			success = (file1 , "%s" , temp);

			if (success == -1)
				break;
			for (int i =0 ; i < n ; i++)
			{
				graph -> a[counter][i] = temp[i] - '0';

			}


			counter++;

		}while (success != -1);


		fclose(file1);

		return 1;


	}

	void printGraph (struct graphs *graph)
	//this function just prints the graph
	{
		printf("The graph name is %s\n" , graph->graphName);
		printf("The number of vertices are %d\n" , graph -> vc);

		int n = graph -> vc;

		printf("The matrix is \n");
		for (int i =0 ; i < n ; i++)
		{
			for (int j =0 ; j< n ; j++)
			{
				printf("%d ",graph->a[i][j]);
			}
			printf("\n");
		}
	}

	void makeGraph ( struct graphs* graph , FILE *file)
	{
		//for the output file
		char output[100];
		printf("Enter the name of the output file\n");
		scanf("%s",output);

		file = fopen (output , "w");
		fprintf(file , "graph one\n" );
		fprintf(file , "{\n");

		int n = graph->vc;
		for (int i =0 ; i < n ; i++)
		{
			for (int j =i ; j< n ; j++)
			{
				if (graph->a[i][j] == 1)
				{
					fprintf(file , "%d -- %d;\n" , i , j);
				}
			}
		}
		fprintf(file , "}\n");
	}
