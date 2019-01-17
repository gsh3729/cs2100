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

/*

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
*/


