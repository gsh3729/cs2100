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

/*
int isInlinkList (struct node *head , int intermediate)
//sees if the intermediate value is in the node or not //returns 1 if it is in the node
{
        struct node * current = head;
        while (current != NULL)
        {
                if (current->data == intermediate)
                        return 1;
                
                current = current->next;
        }

        return 0;


}
*/

/*
int lenOfCycle (struct node * head)
//this function returns the len of cycle
{
	struct node *current = head;
	int counter = 1;

	while (current -> next != head)
	{
		counter++;
		current = current -> next;
	} 

	return counter;
}*/


//path from a single link list (double link list is also going to work)
/*
		struct node *current = (struct node *)malloc (sizeof (struct node));
		current = head;
		while (current != tale)
		{
			int x = current -> data;
			current = current -> next;
			int y = current -> data;
			
			 a[x][y] = 1;
			 a[y][x] = 1;
		}
*/

//if you are making graph this way then use make_graph_using_subgraph for coloring
//for the path in a circular link list (may be noted that it is for circular also going to work for both linear and circular)
/*
struct node *current = head;
	while (current -> next != head )
	{

		int x = current -> data;
		current = current -> next;
		int y = current -> data;
		a[x][y] = 1;
		a[y][x] = 1;

	}


		
	int x = head -> data;
	current = head -> previous;
	int y = current -> data;
	a[x][y] = 1;
	a[y][x] = 1;

	*/






/*
void scan2Darray (int rows , int cols , int a[][cols])
//This function scans the matrix
{
	printf("Enter the elements of the 2D matrix\n");
	for (int i =0 ; i < rows ; i++)
	{
		for (int j = 0 ; j < cols ; j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
}

void print2Darray (int rows , int cols , int a[][cols])
//This function prints the matrix 
{
	printf("The updaetd matrix is\n");
	for (int i =0 ; i<rows ; i++)
	{
		for (int j =0 ; j<cols ; j++)
		{
			printf("%d  ",a[i][j]);
		}
		printf("\n");
	}
}*/