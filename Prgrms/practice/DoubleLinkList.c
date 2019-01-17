#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node 
{
	int data;
	struct node * next;
	struct node * previous;
};

void printLinkListHead (struct node * head)
{
	struct node *current = (struct node*)malloc (sizeof(struct node));
	current = head;
	while (current != NULL)
	{
		printf("%d  ", current -> data);
		current = current -> next;
	}
	printf("\n");
}


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

int main ()
{
	int N;
	printf("Enter the number of nodes\n");
	scanf("%d",&N);

	struct node * tale = (struct node *)malloc (sizeof(struct node));
	struct node *head;
	struct node *current;


	printf("Enter the value in the node ; Note the list is constructed in reverse order\n");
	scanf ("%d",&tale->data);
	tale -> next = NULL;
	current = tale;

	for (int i = 0 ; i < N-1 ; i++)
	{
		struct node *temp = (struct node *)malloc (sizeof (struct node));
		scanf ("%d",&temp->data);
		temp -> next = current;
		current ->previous = temp ;
		current = temp;

	}

	head = current;
	head -> previous = NULL;

	printLinkListHead(head);

	int x , flag = 0;
	printf("Enter the value after which you want to add a node\n");
	scanf("%d",&x);

	current = head;
	while (current != NULL)
	{
		if (current -> data == x)
		{
			flag = 1;
			struct node *temp = (struct node*)malloc (sizeof(struct node));
			temp -> data = 1000;
			temp ->next = current -> next;
			current -> next = temp;
			temp ->previous = current;
			current = temp -> next;
			if (current!=NULL)
				current -> previous = temp;
			else
				tale = current;

		}

		else 
			current = current -> next;

	}

	if (flag == 0)
		printf("The entered value is not found\n");

	printLinkListHead(head);
	flag = 0;
	printf("Enter the node that you want to delete\n");
	scanf("%d",&x);

	//if head is the node to be deleted
	current = head;
	while (head -> data == x)
	{
		flag = 1;
		current = current -> next;
		head = current;
		head -> previous = NULL;
	}

	struct node* after ;
	struct node* before ;

	current = head;
	while (current != NULL)
	{
		if (current -> data == x)
		{
			flag = 1;
			struct node *temp = (struct node*)malloc(sizeof(struct node));
			before -> next = after;
			if (after != NULL)
				after -> previous = before;
			
			current = after;
			if (after != NULL)
				after = after -> next;

		}
		else
		{
			before = current;
			current = current -> next;
			if (current != NULL)
				after = current -> next;
		}
	}

	tale = before;

	printLinkListHead(head);

	//Reversing the link list 
	//Interchanging the head and the tale
	struct node *temp;
	temp = head;
	head = tale;
	tale = temp;

	//for the next;
	current = tale;
	after = current;
	before = NULL;
	while (current != NULL)
	{
		after = current->next;
		current -> next = before;
		before = current;
		current = after;
	}

	current = head;
	after = current;
	before = NULL;
	while (current != NULL)
	{
		after = current -> previous;
		current ->previous = before;
		before = current;
		current = after;
	}

	printLinkListHead(head);
	return 0;












}
