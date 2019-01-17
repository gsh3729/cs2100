#include <stdio.h>
#include <limits.h>
#include <stdlib.h>


//This is declaring the struct containing the data and the pointer of struct type itself
struct node 
{
	int data;
	struct node *next;
};

int main()
{

	int N;
	printf("Enter the value of n: \n");
	scanf("%d",&N);

	struct node *head = (struct node*)malloc(sizeof(struct node));
	struct node *current = NULL;
	struct node *temp = NULL;

	current = head; 
	int i = 0;
	for (i =0 ; i < N - 1; i++)
	{
		temp = (struct node*)malloc(sizeof(struct node));
		current->next = temp;
		current->data = i;

		current = current->next;


	}
	current->next = NULL;
	current->data = i;


	current = head;
	while (current != NULL )
	{
		printf("%d\n",current->data);
		current = current->next;
	}

	
	
	
}