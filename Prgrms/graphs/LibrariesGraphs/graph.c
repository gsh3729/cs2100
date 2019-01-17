#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//including the headers
#include "graph.h"
#include "queue.h"
#include "stack.h"


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


void makeSimpleGraph (struct Graph *graph , FILE *file)
//This function takes the output file open it and make the dot file of the graph
{
	//asking for the name of the output file
		char output[100];
		printf("Enter the name of the output file where you want to make the simple graph\n");
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
				if (graph ->a[i][j] != 0)
					fprintf(file , "%d -- %d ;\n" , i , j );
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


int inside (int *array , int x , int distance)
//returns -1 if i is not in array otherwise return index where it is found;
{
	int n = distance +1;
	for (int i = 0 ; i< n ;i++)
		if (array[i] == x)
			return i;

	return -1;
}

void makeGraph_RED_PATH (struct Graph *graph , FILE *file , int *path , int distance)
{
	//asking for the name of the output file
		char output[100];
		printf("Enter the name of the output file in which you want the path to be red\n");
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
				{
					int x = inside(path , i , distance);
					int y =  inside(path , j , distance);
					if ( x != -1 && y != -1 && ( (x-y) == 1 || (y -x) == 1 )  )
						fprintf(file , "%d -- %d [color = red , label = %d];\n" , i , j , graph->a[i][j]);

					else
						fprintf(file , "%d -- %d [color = black , label = %d];\n" , i , j , graph->a[i][j]);
				}
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



void color_graph (struct Graph *graph , FILE *file , int *colors)
//This function takes the output file open it and make the dot file of the graph and also proper colors the vertices
{
	//asking for the name of the output file
		char output[100];
		printf("Enter the name of the output file that colors the graph with the given color\n");
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


int * shortest_in_weighted_graph (struct Graph *graph , int start ,int goal , int * path , int *distance)
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
			path[dis] = current;
			current = previous[current];
			dis++;
		}

		path[dis] = current;
		*distance = dis;


	return wTree;



}




int * DFS_previous (struct Graph * graph ,  int start  )
//this function implements the DFS search starting from the start node
{
        int n = graph->vc;
        int * visited = (int *)malloc (n * sizeof (int));
        int *previous = (int *)malloc (n * sizeof (int));
        int *order = (int *)malloc(n * sizeof (int));


        for (int i =0 ; i < n ; i ++)
                previous[i] = -2;

        for (int i =0 ; i < n ; i ++)
                visited[i] = 0;

        for (int i= 0 ; i < n ; i++)
        	order[i] = -1;
        stack  s = newStack ();
        int counter = 0;


        stackPush(&s , start);

        while (stackIsEmpty(s) == 0)
        {
                int vertex = stackPop(&s);
                //printf("%d hiii",vertex);

                if (visited[vertex] == 0)
                {
                		//printf("%d  ",vertex);
                        visited[vertex] = 1;
                        order[counter] = vertex;
                        counter++;

                        for (int i = n-1 ; i >= 0 ; i--)
                        {
                                if (graph->a[i][vertex] != 0 )
                                {
                                        stackPush (&s , i);
                                        
                                 }
                        
                        }
                }
        }    
        //this block makes up the previous values
        previous[start] = -1;
        if (counter>1)
        for (int i =1 ; i<counter ; i++)
        {
        	for (int j =i-1 ; j >= 0 ; j--)
        		if (graph->a[order[i]][order[j]] != 0)
        		{
        			previous[order[i]] = order[j];
        			break;
        		}
        }


        return previous;
}


void DFSrecursive (struct Graph *graph , int vertex , int *visited , int *order , int *counter)
//this function do DFS in recursive fashion
{

    int n = graph -> vc;

    visited[vertex] = 1;
    order[*(counter)] = vertex;
    *(counter)++;

    for (int i =0 ; i < n ; i++)
        if (graph -> a[i][vertex] != 0)
            if (visited[i] == 0)
                 DFSrecursive (graph , i , visited , order , counter);

}

int * DFS_order (struct Graph *graph , int start , int *counter)
//this function applies DFS search and returns the order in which they are visited
{
        int n = graph -> vc;
        int *visited = (int *)malloc (n * sizeof (int));
        for (int i =0 ; i < n ; i++)
            visited[i] = 0;

        int *order = (int *)malloc (n * sizeof (int ));
        for (int i =0; i <n ; i++)
            order[i] = -1;

        *(counter) = 0;

        DFSrecursive (graph , start , visited , order , counter);
        return order;
}


void makeGraph_withSubGraph (struct Graph *graph , FILE *file ,int n ,int cycle[][n])
//This function takes the output file open it and make the dot file of the graph and also proper colors the edges that are there in the subGraph
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
		for (int i =0 ; i < n ; i++)
		{
			for (int j = i ; j < n ; j++)
			{
				if (cycle[i][j] == 1)
					fprintf(file , "%d -- %d [color = red];\n" , i , j);

				else if (graph->a[i][j] == 1)
					fprintf(file , "%d -- %d ;\n", i , j);
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


int * BFS (struct Graph *graph , int start , int goal , int*distance)
//this function takes the graph , root value and the goal to see wether both are connected or not and returns a path if connected and updates the value of the
{
	
	int n = graph -> vc;
	Queue Q = newQueue ();
	int visited[n];

	//for storing the previous value of the nodes
	int previous[n];

	//for level
	int * level = (int *)malloc (n * sizeof(int));
	for (int i =0 ; i < n ; i++)
		level[i] = -1;

	//setting value to -2 if they are not visited at all
	for (int i =0 ; i < n ; i++)
		previous[i] = -2;


	//making all the nodes unvisited
	for (int i =0 ; i < n ; i++)
		visited[i] = 0;


	enQueue (&Q , start);
	visited[start] = 1;
	level[start] = 0;

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
					level[i] = level[vertex] + 1;
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
