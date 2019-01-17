#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node 
{
	int data;
	struct node* next;
};

int main()
{
	int N;
	printf("Enter the value of N: \n");
	scanf("%d",&N);

	//creating the link list in the reverse order
	//This link list starts with the head pointer and ends with the tail pointer

	struct node *tail = (struct node*)malloc(sizeof(struct node));
	struct node *temp = NULL;
	struct node *current = NULL;
	struct node *head = NULL;

	tail->next = NULL;
	current = tail;
	int i = 0;
	for (i =0 ; i<N-1 ; i++)
	{
		temp = (struct node*)malloc(sizeof(struct node));
		temp->next = current;
		current->data = i;
		current = temp;
	}
	current->data = i;
	head = current;


	//Entering the element in between the link list after the required node
	struct node *after = NULL;
	current = head;
	while (current != NULL)
	{
		if (current->data == 5)
		{
			temp = (struct node*)malloc(sizeof(struct node));
			after = current->next;
			current->next = temp;
			temp->next = after;
			temp->data = 1000000;
			break;
		}
		current = current->next;

	}
	if (current == NULL)
		printf("The value is not found\n");

	printf("After\n");
	current = head;
	while(current != NULL)
	{
		printf("%d\n",current->data);
		current = current->next;
	}

	//Entering the node before the required node
	struct node *previous = NULL;
	current = head;
	previous = current;

	while(current != NULL)
	{
		if (current->data == 5)
		{
			temp = (struct node*)malloc(sizeof(struct node));
			//for the first elements
			if (current == head)
			{
				temp->data = 1000;
				temp->next = current;
				head = temp;
				break;
			}
			else
			{
				temp->data = 2000;
				temp->next = current;
				previous->next = temp;
				break;
			}

		}
		previous = current;
		current = current->next;
	}

	printf("Before");
	//accesing the values in the nodes
	current = head;
	while(current != NULL)
	{
		printf("%d\n",current->data);
		current = current->next;
	}



	//deleting the elements
	current = head;
	previous = current;
	while(current!= NULL)
	{
		if (current->data == 5)
		{
			previous->next = current->next;
			break;
		}
		previous = current;
		current = current->next;
	}

	printf("Deleted");
	//accesing the values in the nodes
	current = head;
	while(current != NULL)
	{
		printf("%d\n",current->data);
		current = current->next;
	}

	return 0;
}