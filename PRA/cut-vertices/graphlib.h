//Header file for graphlib.c

#include "dll.h"

struct graph{                           //structure to store info for graph
    char a[50][50];
    char name[50],type[20];
    int n,path[50];
    char input_graph[40],output_dot[40];
};
typedef struct graph Graph;

void readAdj( Graph *g);				//function to read a graph file and store the adjacency matrix in array a

void makeDot( Graph *g);					//function to make the dot file

void find_ham(Graph *g);
