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
#include "stack.h"




int * DFS (struct Graph * graph ,  int start  )
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

void makeGraph (struct Graph *graph , FILE *file , int *previous )
{
	//asking for the name of the output file
		char output[100];
		printf("Enter the name of the output file that contains DFS path\n");
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

					if ( previous[i] == j  || previous[j] == i )
						fprintf(file , "%d -- %d [color = red ];\n" , i , j );

					else
						fprintf(file , "%d -- %d [color = black ];\n" , i , j );
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

        int start;
        printf("Enter the value of the root\n");
        scanf("%d",&start);

         int * previous = DFS (&graph , start);


       	//printing the file with red color and  labeled weights
       	FILE *finalfile;
       	makeGraph (&graph , finalfile , previous );

        return 0;

}
