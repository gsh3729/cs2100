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
	//int *parent = DFS_previous (&graph , 0);


	return 0;
}