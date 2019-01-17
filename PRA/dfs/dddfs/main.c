//Programmer Name: Prabhjot Singh
//DATE:31-10-2017
//Program Name :    DFS

#include<stdio.h>
#include<string.h>
#include "dll.h"

int main()
{
  Graph graph1;
  Graph *g = &graph1;

  printf("Graph file name: ");				//take input for graph file name
  scanf("%s",g->input_graph);
  printf("Output dot file name: ");			//take input for output dot file name
  scanf("%s",g->output_dot);
  //strcpy(g->input_graph,"Graph08.txt");
  //strcpy(g->output_dot,"g.dot");

  readAdj(g);

  int x=0,y=9,i;
  int visited[50];
  printf("start = ");				//take input for graph file name
  scanf("%d",&x);

  struct q_int *stack;
  stack=create_q();          //this queue "path" will store the shortest path

  for(i=0;i<g->n;i++)
  {
    visited[i]=0;
    g->path[i]=0;
  }
  g->path[x]=1;
  //dijkstra(g,x,y);
  DFS(g,x,stack,visited);       //calling DFS function to find tree
  makeDot(g);
//print_q(stack);
  return 0;

}
