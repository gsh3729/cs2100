#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node;
void main()
{	
	int i,n,value,j=0;
	
	printf("\n Enter the value of n:");
	scanf("%d",&n);

        node *ne;
	ne = ( node *) malloc (n * sizeof ( node));
	
	for(i=0;i<n;i++)
	{
		printf("\n Enter the data of node %d:",i+1);
		scanf("%d",&((ne+i)->data));
	}
	
	for(i=0;i<n;i++)
	{
		((*(ne+i)).next)=&((ne+i+1)->data);
		if(i==(n-1))
		{	
			(ne+i)->next=NULL;
		}
	}
	
	for(i=0;i<n;i++)
	{
		printf("\n Data of node %d is %d \n",i+1,(ne+i)->data);
		printf(" Next pointer in node %d %p",i+1,(ne+i)->next);
	}
	
	printf("\n Enter the value of your required node");
	scanf("%d",&value);
	for(i=0;i<n;i++)
	{
	  	if(value == (ne+i)->data )
	  	{
			j=i+1;
	  	}
	}
	
	
}	

	
	


	
