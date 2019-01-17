
//doubly linked list functions

#include<stdio.h>
#include<stdlib.h>
#include "dll.h"



struct q_int* create_q()
{
  struct q_int *p;
  p=(struct q_int *) malloc(sizeof(struct q_int));
  p->head=NULL;
  //p->tail=NULL;
  p->length=0;
  return p;
}

void push(struct q_int *q , int value)
{
  struct s_int *p;
  p = (struct s_int *) malloc(sizeof(struct s_int));
  p->data=value;
  p->next=NULL;

  if(q->length==0)
  {
    q->head=p;
    q->length=1;
  }
  else
  {
    p->next=q->head;
    q->head=p;
    q->length++;
  }
}

int pop(struct q_int *q )
{
  int x;

  struct s_int *s;
  if(q->length==0)
  {
    return -1;
  }
  else
  {
    s=q->head;
    x=q->head->data;
    q->head=q->head->next;
    q->length--;
    free(s);
  }
  return x;
}

int top(struct q_int *q )
{
  int x;
  if(q->length==0)
  {
    return -1;
  }
  else
  {
    x=q->head->data;
  }
  return x;
}


void print_q(struct q_int *queue)
{
    struct s_int *current;

    current = queue->head;

    printf("contents:\t");
    if(queue->length!=0)
    {
        do
        {
            printf("%d, ", current->data);
            current = current->next;
        }while(current != NULL);
        printf("\n\n");
    }
    else
        printf("EMPTY\n");
}


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
                if((g->path[i]==1 && g->path[j]==1))
                    fprintf(f,"\t %d -- %d [color=red];\n",i,j);
                else
                {
                    //fprintf(f,"\t %d -- %d [label=%c];\n",i,j,g->a[i][j]);
                    fprintf(f,"\t %d -- %d \n",i,j);//
                }
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

int min(Graph *g,int *w,int x,int *vis)         // this function returns the vertex closest to x in graph
{
  int i,j,min;
  min=9999;
  int pos;
  for(i=0;i<g->n;i++)
  {
      if(w[i]<min && vis[i]!=1)
      {
        min=w[i];
        pos=i;
      }
  }
  return pos;
}

int DFS(Graph *g,int x,int *visited)      //DFS function that returns the number of children of x
{
  int i,j,flag=0;
  visited[x]=1;
  int nc;
  nc=0;

      for(j=0;j<g->n;j++)
      {
        if( g->a[x][j]!='0' && visited[j]!=1 )
        {
          g->path[j]=1;
          i=DFS(g,j,visited);
          nc++;
        }
      }
      return nc;
}
