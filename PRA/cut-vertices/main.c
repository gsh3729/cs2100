//Programmer Name: Prabhjot Singh
//DATE:31-10-2017
//Program Name :    Cut- verticees

#include<stdio.h>
#include<string.h>
#include "dll.h"

int main()
{
  Graph graph1;
  Graph *g = &graph1;

  printf("Graph file name: ");				//take input for graph file name
  scanf("%s",g->input_graph);
  //printf("Output dot file name: ");			//take input for output dot file name
  //scanf("%s",g->output_dot);
  //strcpy(g->input_graph,"Graph09.txt");
  strcpy(g->output_dot,"g.dot");

  readAdj(g);

  int x=4,y=9,i,j,nc[50];
  int visited[50];
  //printf("start , end = ");				//take input for graph file name
  //scanf("%d %d",&x,&y);
  struct q_int *stack;
  stack=create_q();          //this queue "path" will store the shortest path
  push(stack,x);

  for(j=0;j<g->n;j++)     // loop to check no. of children for every vertex
  {
    for(i=0;i<g->n;i++)
    {
      visited[i]=0;
      g->path[i]=0;
    }
    g->path[j]=1;

    nc[j]=DFS(g,j,visited);
  }
  printf("The cut-vertices are:\n" );
  j=0;
  for(i=0;i<g->n;i++)                   //print the vertices with no. of children != 1
  {
    if(nc[i]!=1)
    {
      printf(" %d ",i);
      j=1;
    }
  }
  if(j==0)
    printf("--NONE--" );
  printf("\n");

  makeDot(g);

  return 0;

}
