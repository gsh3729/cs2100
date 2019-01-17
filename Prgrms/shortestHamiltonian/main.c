/*
Name - Arpit Singh
Roll number - 111601031
Program : This program is suppose to find the shortest path between x and y in the graph 
*/


//including the important libraries
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>


//including the header files
#include "graph.h"
#include "queue.h"

int allAreVisited (int * visited , int n)
//this function returns 1 if all are visited
{
	for (int i = 0; i < n ; i++)
		if (visited[i] == 0)
			return -1;

	return 1;
}

int minVertexSet (int * wTree , int *visited , int n)
//returns vertex that is unvisited and have the min distance
{
	int min = 10000;
	int minIndex = 0;
	for (int i =0 ; i< n ; i++)
		if (visited[i] == 0 && wTree [i] <= min)
		{
			min = wTree[i];
			minIndex = i;
		}

	return minIndex;
}


int * BFS (struct Graph *graph , int start ,int goal , int * shortest , int *distance)
//this function takes the graph ,start value and return the min distance of each vertex from the start vertex , it also returns the nodes that are visited
{
	

	int n = graph -> vc;
	int* wTree = (int *) malloc (n * sizeof(int));	
	int visited[n];

	//making all the nodes unvisited
	for (int i =0 ; i < n ; i++)
		visited[i] = 0;


	for (int i =0 ; i < n ; i++)
		wTree[i] = 100000;

	int *previous = (int *)malloc (n * sizeof(int));

	for (int i= 0 ; i < n ; i ++)
		previous[i] = -2;





	
	wTree[start] = 0;			//set distance of the starting node from itself to be equal to zero
	previous[start] = -1;



	while (allAreVisited(visited , n) == -1)
	{
		int vertex = minVertexSet (wTree , visited , n);

		visited[vertex] = 1;

		//checking all the neighbours
		for (int i =0 ; i < n ; i++)
		{

			if (visited[i] == 0 && graph->a[vertex][i] != 0 &&  wTree[i] > wTree[vertex] + graph->a[i][vertex])
			{
				wTree[i] = wTree[vertex] + graph->a[vertex][i];
			

			if (i != start)
				previous[i] = vertex;
		}
		}
	}



		
		int current = goal;
		int dis = 0;		//to mention the distance

		//for storing the answer
		//int *shortest = (int*)malloc(n * sizeof(int)); 	//this is to store the shortest path in correct order
		while (previous[current] != -1)
		{
			//printf("hi");
			shortest[dis] = current;
			current = previous[current];
			dis++;
		}

		shortest[dis] = current;
		*distance = dis;


	return wTree;



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
				if (graph ->a[i][j] != 0 )
					if (inside(shortest , i , distance) == 0 || inside(shortest , j , distance) == 0)
						fprintf(file , "%d -- %d [color = black , label = %d];\n" , i , j , graph->a[i][j]);
					else
						fprintf(file , "%d -- %d [color = red , label = %d];\n" , i , j , graph->a[i][j]);
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
	char filename[100];
	printf("Enter the name of the file \n");
	scanf("%s",filename);

	struct Graph graph;
	int check = readGraph (filename , &graph);

	if (check == 0)
		return 0;

	int n = graph.vc;

	//making the graph 
	FILE *file;
	makeSimpleGraph (&graph , file);

	//scanning the values of the starting and the ending vertex
	int start , goal;
	printf("Enter the starting and the ending vertexn\n");
	scanf("%d %d", &start , &goal);

	int numberOfVertices = 0;
	int *path = (int *)malloc (n * sizeof (int ));

	int *wTree = BFS (&graph , start ,goal, path , &numberOfVertices);


	if (wTree[goal] == 100000)
	{
		printf("There is no path between the starting and the ending vertex\n");
		return 0;
	}
	//finding the distance
	int distance = wTree[goal];

/*
	for (int i =0 ; i < n ; i++)
		printf("%d  ",wTree[i]);

	printf("\n"); */




	

	

//	path[level[goal] - level[start]] = goal;
/*
	for (int currentLevel = level[goal] - 1 ; currentLevel >= 0 ; currentLevel--)
	{
			int min = wTree[path[currentLevel + 1]];
			int minVertex = path[currentLevel + 1];
		for (int i = 0 ; i < n ; i++)
		{
	
			if (level[i] == currentLevel && graph.a[i][path[currentLevel + 1]] != 0 && min >= wTree[i] )
			{
				min = wTree[i];
				minVertex = i;
			}
	}
					path[currentLevel] = minVertex;
					distance += wTree[path[currentLevel + 1]] - wTree[minVertex]; 
	}*/

	//printing the distance between the starting and the closing node
	printf("The distance between the starting and goal vertex is %d\n",distance);


	//printing the file with red color and  labeled weights
	FILE *finalfile;
	makeGraph (&graph , finalfile , path , numberOfVertices);



	//end of the program
	return 0;








}