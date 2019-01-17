/*
Name - Arpit Singh
Roll number - 111601031
Program : It is supposed to tell wether the starting and the goal node is connected or not 
			if it is connected then print the path and show that path with red color on the xdot graph  
*/


//including the important libraries
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

//including the header files
#include "graph.h"
#include "queue.h"

int * BFS (struct Graph *graph , int start , int goal , int*distance)
//this function takes the graph , root value and the goal to see wether both are connected or not and returns a path if connected and updates the value of the
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

	

	//if the return value is found then printing it
	if (visited[goal] == 1)
	{
		printf("%d and %d are connected\n",start , goal);

		
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
		*distance = dis;

		return shortest;
	}

	//if the values are not connected
	else
	{
		printf("%d and %d are not connected\n",start , goal);
		return NULL;
	}



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


//main function
int main ()
{
	char filename[1000];
	printf("Enter the name of the file \n");
	scanf("%s",filename);

	struct Graph graph;
	int check = readGraph (filename , &graph);

	if (check == 0)
		return 0;

	//asking for the values of the start and the goal
	int start , goal;
	printf("Enter the values of the root and the node respectively\n");
	scanf("%d %d",&start ,&goal);

	int distance=0;

	int *shortest = BFS (&graph , start , goal , &distance);

	if (shortest == NULL)
		return 0;

	
		//printing the shortest path
		for(int i = distance; i >= 0 ; i--)
			printf(" - %d - ",shortest[i]);

		printf("\n");

		//printing the distance
		printf("The distance in between the nodes is %d\n",distance);

	//for the output file
	FILE *file;
	makeGraph (&graph , file , shortest , distance);

	return 0;

}