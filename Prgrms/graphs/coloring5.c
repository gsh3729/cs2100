/*

Name - Arpit Singh
Roll number - 111601031
program - This program colors the vertices of the planar graph using a maximum of 5 colors
*/



//including all the libraries
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

//including all the necesarry header files
#include "graph.h"
#include "queue.h"


int BFS (int n , int a[][n] , int start , int goal)
//this function takes the graph , root value and the goal to see wether both are connected or not
{
	
	Queue Q = newQueue ();
	int visited[n];

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
			if (a[vertex][i] == 1 || a[i][vertex] == 1)
			{
				//if i is not visited
				if (visited[i] != 1)
				{
					visited[i] = 1;
					enQueue(&Q , i);
				}
			}
		}
	}

	
	//if the return value is found then return it
	return visited[goal];

}

int* BFSforVistits (int n , int a[][n] , int start )
//this function takes the graph , root value and the goal to see wether both are connected or not
{
	
	Queue Q = newQueue ();
	int *visited = (int*)malloc(n * sizeof(int));

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
			if (a[vertex][i] == 1 || a[i][vertex] == 1)
			{
				//if i is not visited
				if (visited[i] != 1)
				{
					visited[i] = 1;
					enQueue(&Q , i);
				}
			}
		}
	}

	
	//if the return value is found then return it
	return visited;

}

int isPlanar (struct Graph *graph)
//checking if the graph is planar or not
{
	int edges = 0;
	int n = graph->vc;

	//calculating the number of edges

	for (int i =0 ; i<n ; i++)
	{
		for (int j =i ; j < n ; j++)
		{
			if (graph->a[i][j] == 1)
				edges++;
		}
	}
 
	//checking just the basic condition
	if (edges <= 3*n - 6)
		return 1;

	else
		return 0;
}

int * findDegrees (int n , int a[][n])
//this function takes the current adjacency matrix and the number of vertices as the input and returns the array of degrees
{
	int *degrees = (int *)malloc(n * sizeof(int));

	//initialising the degrees to 0
	for (int i =0 ; i < n ;i++)
		degrees[i] = 0;

	for (int i =0 ; i < n ; i++)
	{
		if (a[i][0] == -1)			//i.e. the vertex is being Deleted
		{	
			degrees[i] = -1;
			continue;
		}
		for (int j =0 ; j < n ; j++)
			if (a[i][j] == 1)
				degrees[i]++;

	}

	return degrees;
}
int check (int * a , int n , int value)
//checking if the value that is given is in the array or not
{
	for (int i =0 ; i<n ; i++)
		if (a[i]== value)
			return 1;

	return 0;
}


int * findColor (int n , int a[][n])
//this function assigns the color to the graph
{
	int vertex = -1;
	//finding the number of vertices in the graph
	int flag = 0;
	int numberOfVertices = 0;
	for (int i = 0; i < n ; i++)
	{	
		for (int j =0 ; j < n ; j++)
		{
			if (a[i][j] != -1)
			{
				//printf("%d  ",i);
				numberOfVertices++;
				vertex = i;
				break;
			}

		}

	}
		//printf("\n");

	if (numberOfVertices == 1)
	{
		int *temp = (int*)malloc (n * sizeof(int));
		for (int i =0 ; i < n ; i++)
			temp[i] = -1;				//this is an empty array for the colors 

		temp[vertex] = 0;				//assigning the colors to the graph consisting only one node

		return temp;

	}

	//test
	//printf("%d %d \n",numberOfVertices , vertex);

	//taking the degree of the current graph
	int *degrees = findDegrees (n, a);




	//finding vertex with minimum degree
	//after this step vertex is the vertice of the graph with smallest degree
	for (int i =0 ; i < n ; i++)
	{
		if (degrees[i] != -1 && degrees[vertex] >= degrees[i])
			vertex = i;
	}

	//finding the adjacent vertices in the graph
	int *adjacentVertices = (int*)malloc(n * sizeof(int));
		for (int k =0 ; k < n ; k++)
			adjacentVertices[k] = -1;

	//noting the current vertice and finding color of the adjacent vertices if already colored
		int counter=0;

		for (int j =0 ; j < n ; j++)
			if (a[vertex][j] == 1 || a[j][vertex] == 1)
			{
				
					adjacentVertices[counter] = j;
					counter++;
				
			}


	//deleting a vertex in the graph
	for (int i = 0 ; i < n ; i++)
		a[vertex][i] = -1;

	for (int i =0 ; i < n ; i++)
		a[i][vertex] = -1;

	//coloring the graph that is obtained by deleting one vertex with minimum degree
	int *colors = findColor (n , a);


	


	//noting the colors used to color the adjacent vertice
		int *colorBeingUsed = (int*)malloc(counter * sizeof(int));
		for (int k =0 ; k < counter ; k++)
			colorBeingUsed[k] = -1;

			//noting the current vertice and finding color of the adjacent vertices if already colored
			
			int counter2=0;

			for (int j =0 ; j < n ; j++)
			{
				if (check (adjacentVertices , n , j ))
				{
					colorBeingUsed[counter2] = colors[j];
					counter2++;
				}	
			}


	if (counter <= 4)		//if the number of adjacent vertices are less than or equla to 4
	{
		for (int j =0 ; j < 5 ; j++)
		{
			if (check (colorBeingUsed , counter , j) == 0)	//if adjacent matrix do not have the same color
			{
				colors[vertex] = j;
				break;
			}
		}
	}

	else
	{	
		//if any two vertices have the same color
		for (int j =0 ; j < 5 ; j++)
		{
			if (check (colorBeingUsed , counter , j) == 0)	//if adjacent matrix do not have the same color
			{
				colors[vertex] = j;

				return colors;

				break;
			}
		}	
	
		int unconnected1 = -1;
		int unconnected2 = -1;

		//finding two unconnected vertices that are adjacent to the given vertex
		for (int i = 0 ; i< counter ; i++)
			for (int j =i+1 ; j< counter ; j++)
				if (BFS (n , a , adjacentVertices[i] , adjacentVertices[j]) == 0)
				{
					unconnected1 = adjacentVertices[i];
					unconnected2 = adjacentVertices[j];
					break;
				}

		//finding the vertex connected to the first unconnected vertex
		int *visited = BFSforVistits (n , a, unconnected1);

		//changing the color of the unconnected vertices
		int color1 = colors[unconnected1];
		int color2 = colors[unconnected2];



		//changing the color of all the unconnected vertices
		for (int i =0 ; i< n ; i++)
		{
			//if the vertex is connected to the unconnected1
			if (visited[i] == 1)
			{
				if (colors[i] == color1)
					colors[i] = color2;

				if (colors[i] == color2)
					colors[i] = color1;

			}
		}

		//changing the color of the 1st unconnected vertex
		colors[unconnected1] = color2;
		colors[vertex] = color1;


	}

	return colors;






}


char* chooseColor (int components)
{
	if (components%6 == 0)
		return "red";

	else if (components%6 == 1)
		return "green";

	else if (components%6 == 2)
		return "blue";

	else if (components%6 == 3)
		return "orange";

	else if(components%6 == 4)
		return "black";

	else if(components%6 == 5)
		return "brown";

}



void makeGraph (struct Graph *graph , FILE *file , int *colors)
//This function takes the output file open it and make the dot file of the graph and also proper colors the vertices
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



		//coloring the graph
		for (int i =0 ; i < n ; i++)
		{
			char *c = chooseColor (colors[i]);
			fprintf(file , "%d  [color = %s , style = filled] ;\n", i , c );
		}

		fprintf(file , "}\n");
}

int main ()
{
	//asking for the name of the file
		char filename[1000];
		printf("Enter the name of the file \n");
		scanf("%s",filename);

	//declaring and initialising the graph
		struct Graph graph;
		int check = readGraph (filename , &graph);

	//checking if the filename is incorrect or not
		if (check == 0)
			return 0;

		int n = graph.vc;

	//checking if the graph is planar or not
		if (isPlanar(&graph) == 0)
		{
			printf("The given graph is not planar.\n");
			return 0;
		}

	//creating a new graph
	
		
		int copy[n][n];
		
		
		for (int i =0 ; i < n ; i++)
		 	for (int j= 0 ; j < n ; j++)
		 		copy[i][j] = graph.a[i][j]; 



//coloring the graph
		int *colors = (int*)malloc(n *sizeof(int));

		colors = findColor( n, copy);

	//making the final graph
		FILE *file;
		makeGraph (&graph , file , colors);


}