#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void createNodes(node **head,int value)
{
	node *temp,*a;
	temp=*head;
	a= (node *)malloc(sizeof(node)); //Dynamically allocating memory to the node
	a->data=value;

	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	
	a->pre=temp;
	a->next=NULL;
		
	

}



void printNodes(node **head) // printing linked list data using pointers in it
{
	node *temp;
	temp=*head;

	while((temp->next)!=NULL)
	{
		printf("\n %d",temp->data);
		temp=temp->next;
	}

}

void linkedlist(node **head,int value)
{
	int i;
	node *a,*temp;
	temp=*head;
	a = (node*)malloc(sizeof(node));
	a->data=value;
	if(temp->next==NULL)
	{
		a->next=a;
	}
	
	while((temp->next)!=*head)
	{
		temp=(temp->next);
	}
	temp->next=a;
	a->next=*head;
}
