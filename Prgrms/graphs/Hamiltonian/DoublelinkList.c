#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

//including all the necesarry header files
#include "graph.h"
#include "DoublelinkList.h"


//This functon prints the list with the given head

	void printListHead(struct node* head)
	{
		struct node *current = (struct node*)malloc(sizeof(struct node));
		current = head; 				//initialising the current node

		while (current != NULL )
		{
			printf("%d   ",current->data); //printing each values
			current = current -> next; //incrementing the current node
		}
		printf("\n");
	}


//This functon prints the list with the given tale
	void printListTale(struct node* tale)
	{
		struct node *current = (struct node*)malloc(sizeof(struct node));
		current = tale; 					//initialising the current node

		while (current != NULL)
		{
			printf("%d   ",current->data);  	//printing each values
			current = current -> previous;		//decrementing the current node
		}
		printf("\n");
	}



void addNodeForward (struct node ** tale , int x )
//this function takes the tale of the link list and add the node at the end of the double link list
{
	struct node *temp = (struct node *)malloc (sizeof(struct node));
	temp -> data = x;	//assigning the value

	//making all the necesarry pointers
		(*tale) -> next = temp;
		temp ->previous = (*tale);
		temp -> next = NULL;
		(*tale) = temp;


}


void addNodeBack (struct node ** head , int x )
//this function takes the head of the double link list and add the node at the starting of the double link list
{
	struct node *temp = (struct node *)malloc (sizeof(struct node));
	temp -> data = x;	//assigning the value

	//making all the necesarry pointers
		(*head) -> previous  = temp;
		temp -> next = (*head);
		temp -> previous = NULL;
		(*head) = temp;
}