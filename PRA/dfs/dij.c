
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "dll.h"

int BFS( Graph *g , int x , int y)          //breadth first search function to check if x and y are connected
{
    int visited[50];  //To keep track of the visited vertices
	int i,j,dist=0;                //dist stores the distance b/w conncted edges
	int parent[50];                    // parent(i) stores the parent of i in BFS
	for(i = 0;i < g->n;i++)
	{
		parent[i] = -1;
		g->path[i] = 0;                   //g->path[] stores if the element is in the shortest path
        visited[i] = 0;
	}
	g->path[x] = 1;
	enqueue(x);

	int flag = 0,temp;
	for(  temp = dequeue() ; temp != -1 ;temp = dequeue() )
	{
		for(j = 0;j < g->n;j++)
		{
			if((visited[j]==0) && (g->a[temp][j]!='0'))
			{
				if(parent[j] == -1)
				parent[j] = temp;
				if(j == y)
				{
					printf("The nodes are connected.\n");
					flag = 1;
          return 1;
					break;
				}
				visited[j] = 1;
				enqueue(j);
			}
		}
		if(flag == 1)
		break;
	}
	i =0;
	j = y;
	if(flag != 1)
	{
    printf("The nodes are not connected.\n");
    return 0;
  }
}
