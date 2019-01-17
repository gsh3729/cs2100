#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

//declaring the struct node that is used to create the palindrome
struct node 
{
	int data;
	struct node *next;
};

int main()
{
	//printing and taking the value of N;
	int N;
	printf("Enter the value of N\n");
	scanf("%d",&N);

	struct node *head = (struct node*)malloc(sizeof(struct node));
	struct node *current = (struct node*)malloc(sizeof(struct node));

	head->data = 0;
	current = head;
	int i ;

	for (i = 0 ; i < N ; i++)
	{
		struct node *temp = (struct node*)malloc(sizeof(struct node));
		temp->data = i;
		current->next = temp;
		current = temp;
	}

	current->next = NULL;

	//printing the link list
	current = head;
	while(current != NULL)
	{
		printf("%d\n",current->data);
		current = current->next;
	}

	return 0;

}