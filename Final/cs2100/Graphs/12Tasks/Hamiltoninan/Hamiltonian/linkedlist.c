#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"


void doublelinkedlist(node **head,int i)
{
	node *temp=*head,*newnode;

	if(*head==NULL)
	{
		newnode=(node*)malloc(sizeof(node));
		newnode->data=i;
		
		*head=newnode;
		newnode->pre=NULL;
		newnode->next=NULL;
	}
	else
	{
		newnode=(node*)malloc(sizeof(node));
		newnode->data=i;
		
		while((temp->next)!=NULL)
		{
			temp=temp->next;
		}

		temp->next=newnode;
		newnode->pre=temp;
		newnode->next=NULL;

	}
}

void printCircular(node **head)
{
	node *temp;
	temp=*head;
	do
	{
		printf(" %d",temp->data);
		temp=temp->next;
	}while((temp)!=(*head));
	
	printf(" %d",(*head)->data);
	printf("\n");
	
	return;
}

void printDLL(node **head)
{
	node *temp;
	temp=*head;
	while((temp)!=NULL)
	{
		printf(" %d",temp->data);
		temp=temp->next;
	}
	
	printf("\n");
	
	return;
}
node* goToLastVertex(node **head)
{
	node *temp=*head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	return temp;
}



