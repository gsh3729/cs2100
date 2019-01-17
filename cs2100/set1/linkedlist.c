#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
};
 
void main()
{
	int n,i,value,j=0;

	printf("Enter N:");
	scanf("%d",&n);

	struct node *ne,*head;

	ne = (struct node *) malloc (n*sizeof(struct node));
	head=ne;
	for(i=0;i<n;i++)
	{
		printf("Enter the data of node of %d:",i+1);
		scanf("%d",&((ne+i)->data));
		if(i!=n-1)
		{
			(ne+i)->next = ne+i+1;
		}
		if(i==n-1)
		{
 			(ne+i)->next=NULL;
		}
		/*	printf("%d\n",(ne+i)->data);
			printf("%p\n",(ne+i)->next);*/
	
	}	 
	
	printf("\n Enter the value:");
	scanf("%d",&value);
	
	for(i=0;i<n;i++)
	{
		if(value == (ne+i)->data)
		{
			j=i+1;
		}
	}
	if(j!=0)
 	{
		struct node *add;
		printf("\n Enter the data in node to be added:");
		scanf("%d",&(add->data));
		add->next = ne+j;
		(ne+j-1)->next = add;
	}
	struct node *temp;
	temp=ne;	
	while(temp!=NULL)
	{
		printf(" %d\n",temp->data);
		temp=temp->next;
        }
	
	
	free(ne);
}
















