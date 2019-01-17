

#include<stdio.h>
#include <stdlib.h>
#include<string.h>

#include "graphlib.h"
//#include "dll.h"


void readAdj( Graph *g)				//function to read a graph file and store the adjacency matrix in array a
{
    int success,i,j;
	char c;
    FILE *p ;

    p = fopen(g->input_graph, "r");
    if (p == 0)   /* Check if the file was opened correctly */
    {
   		printf("Error in opening the file\n");
   		return;
  	}

    success = fscanf(p, "%[^\n] ", g->name );     		//scanning name
	success = fscanf(p, "%[^\n]", g->type );     		//scanning type
	success = fscanf(p, "%d", &g->n );
	c=getc(p);
	for(i=0;i<=g->n;i++)							// loop to make the matrix
	{
		for(j=0;j<g->n;j++)
		{
				c = getc(p);
				g->a[i][j] = c ;
		}
		c=getc(p);
	}
    fclose(p);
	return ;
}

void makeDot( Graph *g)					//function to make the dot file
{
	int i,j,k;
    FILE *f;
	f=fopen( g->output_dot ,"w");
	if(f==NULL)
	{
		printf("error in opening file to write...!\n");
		return;
	}
	fprintf(f,"graph %s{\n",g->name);
	for(i=0;i<g->n;i++)
	{
		for(j=i;j<g->n;j++)					//j is initialised to i to avoid repetition
		{
			if(g->a[i][j]!='0')				//if a[ij] is 1 then connect vertices by an edge
			{
                if(g->path[i]==1 && g->path[j]==1)
                    fprintf(f,"\t %d -- %d [color=red];\n",i,j);
                else
                    fprintf(f,"\t %d -- %d ;\n",i,j);
			}
		}

		k=0;
        for(j=0;j<g->n;j++)					//loop to print isolated vertices
		{
			if(g->a[i][j]!='0')
			{
				k=1;
                break;
			}
		}
        if(k==0)
		{
                fprintf(f,"\t %d ;\n",i);
		}
	}

	fprintf(f,"}");
	fclose(f);
	return;

}

int visited[50];
void find_ham(Graph *g)
{

  int i=0,j=0;
  if(q->length==0)
  {

      for(i=0;i<g->n;i++)
      {
          visited[i]=0;
      }
  }
 // int visited[50];
 // struct q_int *queue;
  //queue= create_q();
  i=q->head->data;
  do
  {
    flag=0;
    for(j=0;j<g->n;j++)
    {
      if(g->a[i][j]=='1' && visited[j]!=1)
      {
        enqueue_rev(queue,j);
        visited[j]=1;
        i=j;
        flag=1;
        break;
      }
    }
  }while(flag==1)
  i=q->tail->data;
  do
  {
    flag=0;
    for(j=0;j<g->n;j++)
    {
      if(g->a[i][j]=='1' && visited[j]!=1)
      {
        enqueue(queue,j);
        visited[j]=1;
        i=j;
        flag=1;
        break;
      }
    }
  }while(flag==1)
  print_q(q);
}
