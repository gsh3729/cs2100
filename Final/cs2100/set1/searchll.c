#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node;
void CreateList(node **,int );
void PrintNodes(node **);
void SearchList(node **,int);
void main()
{
	node *head =NULL;
	int n,value;

	printf("\n Enter N:");
	scanf("%d",&n);
	
	CreateList(&head,n);
	PrintNodes(&head);
	
	printf("\n Enter the element you want to search in linked list :");
	scanf("%d",&value);

	SearchList(&head,value);
}
void CreateList(node **headRef,int n)
{
	int i;
	node *a,*b;
	
	for(i=0;i<n;i++)
	{
		a = ( node*)malloc(sizeof(node));
		printf("\n Enter data in node %d : ",i+1);
		scanf("%d",&(a->data));
		
		if(i==0)
		{
			*headRef = a;
			a->next = *headRef;
			b=a;
		}
		else
		{
			b->next=a;
			a->next = *headRef;
			b=a;
		}
	}
}

void PrintNodes(node **headRef) // printing linked list data using pointers in it
{
	node *temp;
	temp=*headRef;

	do 
	{
		printf("\n %d",temp->data);
		temp=temp->next;
	}while(temp!= *headRef);

}
void SearchList(node **headRef,int value)
{
	int j=0;
	node *temp;
	temp =*headRef;
	do 
	{  	
		if(value == temp->data)
		{   
		 	printf("\n Yes. The value you entered is there in list \n");
			j=1;
		}
		
	   temp=temp->next;
	}while(temp!= *headRef);
	
	if(j==0)
	{
		printf("\n The value you entered is not there in list \n");
	}
}	







	
