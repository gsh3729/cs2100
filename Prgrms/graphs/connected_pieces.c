/*
Name - Arpit Singh
Roll number - 111601031
Program : This is suppose to find the number of components in the graph and then show that on the graph
		and it also prints the graph that shows which node we have actually travelled to explore the whole 
*/


//including the important libraries
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

//including the header files
#include "graph.h"
#include "queue.h"

//Global variables 
FILE *file1;
FILE *file2;


int * BFS (struct Graph *graph , int start )
//this function takes the graph , root value and the goal to see wether both are connected or not
{
	
	int n = graph -> vc;
	Queue Q = newQueue ();
	int *visited = (int *)malloc(n * sizeof(int));

	
	//making all the nodes unvisited
	for (int i =0 ; i < n ; i++)
		visited[i] = 0;



	enQueue (&Q , start);
	visited[start] = 1;

	while (QueueisEmpty (Q) == 0)
	{
		int vertex = deQueue (&Q);

		//checking all the neighbours
		for (int i =0 ; i < n ; i++)
		{
			if (graph -> a[vertex][i] != 0)
			{
				//if i is not visited
				if (visited[i] != 1)
				{
					if (graph->a[vertex][i] == 1)

					{		
						fprintf(file2 , "%d -- %d [color = red];\n" , vertex , i);
						graph->a[vertex][i]++;
						graph->a[i][vertex]++;
						
						
					}

					visited[i] = 1;
					enQueue(&Q , i);
				}

				else
				{
					if (graph->a[vertex][i] == 1)

					{		
						fprintf(file2 , "%d -- %d [color = black];\n" , vertex  ,i);
						graph->a[vertex][i]++;
						graph->a[i][vertex]++;
					}

				}
			}
		}
	}

	return visited;
}

int checkingVisits (int *visit , int n)
//return the index of the first vertice that is not visited , otherwise return -1
{
	for (int i =0 ;  i <n ; i++)
		if (visit[i] == 0)
			return i;

	return -1;
}

int inside (int *shortest , int n , int value)
{
	for (int i =0 ; i < n ; i++)
		if (value == shortest[i])
			return 1;

	return 0;
}

char* colors (int components)
{
	if (components%5 == 0)
		return "red";

	else if (components%5 == 1)
		return "green";

	else if (components%5 == 2)
		return "blue";

	else if (components%5 == 3)
		return "orange";

	else if(components%5 == 4)
		return "black";

}

int main ()
{
	//asking for the input file name
	char filename[100];
	printf("Enter the name of the input file\n");
	scanf("%s",filename);

	//reading the graph from the file
	struct Graph graph;
	int check = readGraph (filename , &graph);

	if (check == 0)
		return 0;


	int n = graph.vc;

	//asking for the name of the output file
		char output1[100];
		printf("Enter the name of the output file that shows different components\n");
		scanf("%s",output1);

	//asking for the name of the output file
		char output2[100];
		printf("Enter the name of the output file that shows edges  that we have followed\n");
		scanf("%s",output2);

	//opening the output file
		file1 = fopen (output1 , "w");
		file2 = fopen (output2 , "w");

	//beginning writing in both the files;
		//printing the necesssary details in file 1
		fprintf(file1 , "graph one\n");
		fprintf(file1 , "{\n");

		//printing the necesssary details in file2
		fprintf(file2 , "graph one\n");
		fprintf(file2 , "{\n");



	//for the points that we have visited
	int component = 0; 			//to keep track of the number of components
	int visited[n];
	for (int i =0 ; i < n ; i++)
		visited[i] = 0;

	int *visited2 = (int*)malloc(n * sizeof(int));

	
	while (1)
	{

		int vertex = checkingVisits(visited , n);


			//checking if all are visited
		if (vertex == -1)
			break;

		else
		{
			//the component is going to increase by one each time we apply BFS
			component++;
			visited2 = BFS (&graph , vertex );

			//for selecting the isolated components
				char col[100];
				strcpy (col , colors(component));
				
			//printing details in the file ; where different edges are to be printed in different colors
				for (int i =0 ; i < n ; i++)
				{
				for (int j = i ; j < n ; j++)
					{
						if (graph.a[i][j] != 0 && (visited2[i] == 1 && visited2[j] == 1))
							fprintf(file1 , "%d -- %d [color = %s];\n" , i , j , col);
					}
				}

			//updating the values of the visits
				for (int i =0 ; i< n ; i++)
					if (visited[i] == 0)
					visited[i] = visited2[i];

				

		}
	}

	printf("The number of connected components of the graph are %d\n",component);

	//printing the isolated vertices in both the graphs
	//For graph1 and graph2 both
	int flag ;
		//printing the isolated vertices
		for (int i =0 ; i < n ; i++)
		{
			flag = 0;

			for (int j =0 ; j < n ; j++)
				if (graph.a[i][j] != 0)
					flag = 1;

			if (flag == 0)
			{	
				fprintf( file1 , "%d;\n", i );
				fprintf( file2 , "%d;\n" , i);
			}
		}




	//printing the final details on the file

		fprintf(file1 , "}\n");

		fprintf(file2 , "}\n");

	return 0;


}

