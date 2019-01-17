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
    (*counter)++;

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




void makeGraph (int **a , FILE *file , int n)
//This function takes the output file open it and make the dot file of the graph
{

	int deleted;
	//finding the deleted vertices
	for (int i= 0 ; i < n ; i++)
	{
		int flag =1 ;
		for (int j = 0 ; j <n ; j++ )
		{
			if (a[i][j] != -1)
			{
				flag = 0;
				break;
			}
		}

		if (flag == 1)
		{
			deleted = i;
			break;
		}
	}


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
				if (a[i][j] > 0)
					fprintf(file , "%d -- %d ;\n" , i , j );
			}
		}

		//printing the isolated vertices
		for (int i =0 ; i < n ; i++)
		{
			flag = 0;

			for (int j =0 ; j < n ; j++)
				if (a[i][j] == 1 )
					flag = 1;

			if (flag == 0 && i != deleted )
			{	
				fprintf( file , "%d;\n", i );
			}
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
	      // FILE *file;
	      // makeSimpleGraph (&graph , file);

	
	//for checking which are the nodes that are cut vertices
		int *cutVertices = (int *)malloc (n * sizeof (int));
		for (int i =0 ; i < n ; i++)
			cutVertices[i] = -1;

	//counter for storing the number of cut vertices
		int counter = 0;
	//applying DFS on every node and finding which of them are cut vertex
	
	for ( int vertex = 0 ; vertex < n ; vertex++)
	{
		int *previous = DFS_previous (&graph ,vertex);


		
		int temp =0;
		for (int i =0 ; i <n ; i++)
		{
			if (previous[i] == vertex)
				temp++;
			
		}



		if (temp >= 2)
		{
			cutVertices[counter] = vertex;
			counter++;
		}

	}

	/*

	//finding the DFS search using only DFS
	//this is valid for connected graphs
	int verticesTravelled ;
	int * order = DFS_order (&graph , 0 , &verticesTravelled);
	int *previous = DFS_previous (&graph ,0);


	//for checking which are the nodes that are cut vertices
		int *cutVertices2 = (int *)malloc (n * sizeof (int));

		for (int i =0 ; i < n ; i++)
			cutVertices2[i] = -1;

		//for keeping track of number of cut vertices obtained by another method
		int counter2 = 0 ;



	//making the DFS tree
				int ** DFSTree = (int **)malloc (n * sizeof (int*));
				for (int i =0 ; i < n ; i++)
					DFSTree[i] = (int *)malloc (n * sizeof (int ));


				for (int i =0 ; i <n ; i++)
					for(int j =0 ; j < n ; j++)
						DFSTree[i][j] = 0;

			//filling the matrices for the DFStree
				for (int i =0 ; i < n ; i++)
					for (int j =0 ; j < n ; j++)
						if (previous[i] == j || previous[j] == i)
						{
							DFSTree[i][j] = 1;
						} 
			//making the graph
				struct Graph DFSgraph ;
				DFSgraph.vc = n;
				DFSgraph.a = DFSTree;
				strcpy (DFSgraph.graphName , "DFSgraph" );


			//making the DFS graph
			//	FILE *DFSfile ;
			//	makeSimpleGraph (&DFSgraph , DFSfile);


	//checking wether the vertex 0 is cut vertice or not
		
		int temp =0;
		for (int i =0 ; i <n ; i++)
		{
			if (previous[i] == 0)
				temp++;
			
		}



		if (temp >= 2)
		{
			cutVertices[counter2] = 0;
			counter2++;
		}
		*/

/*
		int *level = (int *)malloc (n * sizeof(int));
		for (int i =0 ; i < n ; i++)
			level[i] = -1;				//the level will be -1 if it is not at all traversed


		level[0] = 0;		//setting the level of the root node to be zero


		for (int i = 1 ; i < verticesTravelled ; i++)
		{
			int vertex = order[i];
			level[vertex] = level[previous[vertex]] + 1;
		}

		*/

/*
		

	//finding cut vertice using second approach
		for (int i = 1 ; i < n; i++)
		{
			int vertex = i;
			int flag1 = 0; 			//to check that the vertices must have atleast two edges in the graph althose with one edge are leaves and are not a part of cut vertices
			for (int j =0 ; j < n ; j++)
			{
				if (DFSgraph.a[vertex][j] == 1)
					flag1++;
			}

			int k=0;
			if (flag1 < 2)
				continue;

			else				//checking back edge
			{	
				
				int flag2 = 0;
				for (int j =0 ; j < n ; j++)
				{
					

					
					if (DFSgraph.a[vertex][order[j]] == 1)
					{
						flag2 = 0;
						int temp = order[j];
						printf("%d %d\n" , vertex , temp);
						
						for (int k = 0 ; k < n ; k++)
						{

							if (graph.a[temp][k] == 1 && k != vertex)
							{	
								flag2++;
								
								printf("   %d %d  %d \n", temp , k , flag2);
								break;
							}
							
						}
						printf("%d\n",flag2 );
							if (flag2 == 0)
							{
							
							break;							
						}
				}

					
				}
				if (flag2 == 0)
						{
							cutVertices2[counter2] = vertex;
							counter2++;
							break;
						}

				

			}

			

		}


		*/


	//checking if there are no cut vertices
	if (counter == 0)
	{
		printf("There is no cut vertex in the graph\n");
		return 0;
	}


	//if there are cut vertices then printing all those cut verices
	printf("The cut vertices by First approach (DFS on each vertex) are : \n");
	for (int i= 0 ; i < counter ; i++)
	{
		printf("%d   ",cutVertices[i]);
	}
	printf("\n");


	//printing the cut_vertices by the second method
	/*
	printf("The cut vertices by Second approach (DFS on only vertex ; Note : the graph before must be connected) are : \n");
	for (int  i= 0 ; i < counter2 ;i++)
		printf("%d   ",cutVertices2[i]);

	printf("\n");
	*/
	//this block is to remove one of the cut vertex if there is and then print the graph
	//just removing one of the vertex and making the graph

	//now this is commented out ; if you want to see just remove the comments 
			/*
			int **a = graph.a;

			for (int i =0 ; i < n ; i++)
			{
				a[cutVertices[1]][i] = -1;
				a[i][cutVertices[1]] = -1;
			}

			FILE *fileOutput;
			makeGraph (a , fileOutput , n );
			*/

	return 0;




}
