/*
Name - Arpit Singh
Roll number - 111601031
program - This program colors the vertices of the planar graph using a maximum of 6 colors
*/




//including all the libraries
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

//including all the necesarry header files
#include "graph.h"
#include "queue.h"

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


int * creatingDegeneracy (int n ,int a[][n]  )
//this function returns the degeneracy order
{
	int minDegree = 0;		//for vertex of minimum degree

	//finding the number of vertices in the graph
	int flag = 0;
	int numberOfVertices = 0;
	for (int i = 0; i < n ; i++)
	{	
		for (int j =0 ; j < n ; j++)
		{
			if (a[i][j] != -1)
			{
				numberOfVertices++;
				minDegree = i;
				break;
			}
		}
	}


	if (numberOfVertices == 0)		//if the graph has no vertices i.e. the terminating condition
	{
		int *temp = (int*)malloc (n * sizeof(int));
		for (int i =0 ; i < n ; i++)
			temp[i] = -1;				//this is an empty degeneracy order i.e. no vertice is in this order

/*
	for (int i =0 ; i < n ; i++)
		printf("%d  ",temp[i]);

		printf("\n");*/
	
		return temp;
	}

	//taking the degree of the current graph
	int *degrees = findDegrees (n, a);


	//finding vertex with minimum degree
	
	for (int i =0 ; i < n ; i++)
	{
		if (degrees[i] != -1 && degrees[minDegree] >= degrees[i])
			minDegree = i;


	}

	//deleting a vertex in the graph
	for (int i = 0 ; i < n ; i++)
		a[minDegree][i] = -1;

	for (int i =0 ; i < n ; i++)
		a[i][minDegree] = -1;


 	int *degeneracy = creatingDegeneracy (n ,a);
 	degeneracy[numberOfVertices-1] = minDegree;				//putting the vertex in the order  


 	return degeneracy;
}

int checker (int * a, int value , int n)
//checks if the color is already  or not
{
	for (int i =0 ; i < n ; i++)
		if (a[i] == value)
			return 1;

	return 0;


}

int * coloringTheGraph (struct Graph * graph , int * degeneracy )
//this function returns the array that stores the color of the vertices given to it
{
	int n = graph->vc;



	//note the colors are denoted by 1 , 2, 3, 4, 5 , 6
	int*colors = (int*)malloc (n * sizeof(int));
	for (int i =0 ; i < n ; i++)
		colors[i] = -1;


	//assignign 6 colors to all
	for (int i =0 ; i < 6 ; i++ )
		colors[degeneracy[i]] = i;



	//for the rest of the graph
	for (int i =6 ; i < n ; i++)
	{
		int *colorBeingUsed = (int*)malloc(6 * sizeof(int));
		for (int k =0 ; k < 6 ; k++)
			colorBeingUsed[k] = -1;

		//noting the current vertice and finding color of the adjacent vertices if already colored
			int current = degeneracy[i];
			int counter=0;

			for (int j =0 ; j < n ; j++)
				if (graph->a[current][j] == 1)
				{
					if (colors[j] != -1)
					{	
						colorBeingUsed[counter] = colors[j];
						counter++;
					}
				}

		//assigning the color to the current
		for (int j =0 ; j < 6 ; j++)
		{
			if (checker (colorBeingUsed , j , counter ) == 0)	//if adjacent matrix do not have the same color
			{
				colors[current] = j;
				break;
			}
		}

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
		
	
	//finding the degeneracy order
		int * degeneracy = (int *)malloc(n * sizeof (int));
		degeneracy = creatingDegeneracy(n , copy);

	//coloring the graph
		int *colors = (int*)malloc(n *sizeof(int));

		colors = coloringTheGraph(&graph , degeneracy);

	//making the final graph
		FILE *file;
		makeGraph (&graph , file , colors);

}