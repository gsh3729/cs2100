/*
Name - Arpit Singh
Roll number - 111601031
Program : This program is suppose to find the shortest longest path in the graph , i.e. the diameter of the graph
		it also shows one of the shortest longest path in the graph 
*/



//including the important libraries
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>


//including the header files
#include "graph.h"
#include "queue.h"


int * BFS (struct Graph *graph , int start )
//this function takes the graph , and a start node and returns distance of every node from start node in connected graph
{
	
	int n = graph -> vc;
	Queue Q = newQueue ();
	int visited[n];

	//array for storing the level of each of the nodes from the start node
	int *value = (int*)malloc(n * sizeof (int));
	for (int i =0 ; i < n ; i++)
		value[i] = 0;


	value[start] = 0; 		//setting the value of the starting node

	//making all the nodes unvisited
	for (int i =0 ; i < n ; i++)
		visited[i] = 0;


	enQueue (&Q , start);
	visited[start] = 1;

	int counter = 0;		//for the levels of the node from the start node

	while (QueueisEmpty (Q) == 0)
	{
		int vertex = deQueue (&Q);

		//checking all the neighbours
		for (int i =0 ; i < n ; i++)
		{
			counter++;

			if (graph -> a[vertex][i] == 1)
			{

				//if i is not visited
				if (visited[i] != 1)
				{
					value[i] = value[vertex] + 1;

					visited[i] = 1;
					enQueue(&Q , i);
				}
			}
		}
	}

	return value;

}


int * pathFinder(struct Graph *graph , int start , int goal )
//this function takes the graph , and finds the shortest path between the start and the goal in the connected graph
//note the path returned  is reversed
{
	
	int n = graph -> vc;
	Queue Q = newQueue ();
	int visited[n];

	//for storing the previous value of the nodes
	int previous[n];

	//setting value to -2 if they are not visited at all
	for (int i =0 ; i < n ; i++)
		previous[i] = -2;


	//making all the nodes unvisited
	for (int i =0 ; i < n ; i++)
		visited[i] = 0;


	enQueue (&Q , start);
	visited[start] = 1;

	//making the previous value of start as one as it does not have the previous values
	previous[start] = -1;


	while (QueueisEmpty (Q) == 0)
	{
		int vertex = deQueue (&Q);

		//checking all the neighbours
		for (int i =0 ; i < n ; i++)
		{
			if (graph -> a[vertex][i] == 1)
			{

				//if i is not visited
				if (visited[i] != 1)
				{
					//storing the previous value
					previous[i] = vertex;

					visited[i] = 1;
					enQueue(&Q , i);
				}
			}
		}
	}

		
		int current = goal;
		int dis = 0;		//to mention the distance

		//for storing the answer
		int *shortest = (int*)malloc(n * sizeof(int)); 	//this is to store the shortest path in correct order
		while (previous[current] != -1)
		{
			shortest[dis] = current;
			current = previous[current];
			dis++;
		}

		shortest[dis] = current;
		

		return shortest;

}

int inside (int *shortest , int x , int distance)
//returns 1 if x is in shortest
{
	int n = distance + 1;
	for (int i = 0 ; i< n ;i++)
		if (shortest[i] == x)
			return 1;

	return 0;
}

void makeGraph (struct Graph *graph , FILE *file , int *shortest , int distance)
//This function prints the graph taking in mind the shortest path between two nodes and higlight that in the red color
{
	//asking for the name of the output file
		char output[100];
		printf("Enter the name of the output file in which you want to show the longest shortest path\n");
		scanf("%s",output);

	//opening the output file
		file = fopen (output , "w");

	

	
	//printing the necesssary details
		fprintf(file , "graph one\n");
		fprintf(file , "{\n");


		int n = graph -> vc;
		for (int i =0 ; i < n ; i++)
		{
			for (int j = i ; j < n ; j++)
			{
				if (graph ->a[i][j] == 1 )
					if (inside(shortest , i , distance) == 0 || inside(shortest , j , distance) == 0)
						fprintf(file , "%d -- %d;\n" , i , j);
					else
						fprintf(file , "%d -- %d [color = red];\n" , i , j);
			}
		}

		//printing the isolated vertices
		int flag;

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

	//declaring 2D matrix for distance between each nodes
		int **distances;

		distances = (int**)malloc(n * sizeof(int*));
		for (int i =0 ; i < n ; i++)
			distances[i] = (int*)malloc (n * sizeof(int));


	//finding the distances
	for (int i =0 ; i< n ; i++)
		distances[i] = BFS (&graph , i);


	int start , goal;	//for the longest shortest path
	int diameter = 0 ;

	for (int i =0 ; i< n ; i++)
		for (int j =0 ; j < n ; j++)
		{
			if (distances[i][j] >= diameter)
			{
				diameter = distances[i][j];
				start = i;
				goal = j;
			}
		}

	printf("The diameter of the graph is %d\n",diameter);

	//finding the longest shortest and printing it in the file
	int *shortest = pathFinder (&graph , start , goal);

	//for the output file
		FILE *file;
		makeGraph (&graph , file , shortest , diameter);

	return 0;

}