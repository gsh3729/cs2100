#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node;
void AddNode(node *n); 

node *head=NULL; 
node *temp;
void main()
{
	int i,no;
	printf("\n Enter the number n :");
	scanf("%d",&no);
	
	node *n;
	head = n;
	for(i=0;i<no;i++)
	{
		AddNode(n);
	}	
		
	
		
	free(n);
}

void AddNode(node *n)
{
	n=(node *)malloc(sizeof(node));
	scanf("%d",&(n->data));
	temp = n;
	n->next = NULL;

	
}		





























