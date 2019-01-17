/*
Name = Arpit singh
roll number = 111601031
exercise 4
*/


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node{
	int data;
	struct node * next;
};

int main ()
{
	//taking the value of n
		int N;
		printf("Enter the value of n\n");
		scanf("%d",&N);

	//Creating the linear link list which starts at head and end at tail
		struct node *head = (struct node*)malloc(sizeof(struct node));
		struct node *tail = (struct node*)malloc(sizeof(struct node));
		struct node *current = NULL;

		current = head;
		printf("Enter the values of the elements of the link list\n");
		int i ;
		for (i = 0 ; i < N -1 ; i++)
		{
			struct node* temp = (struct node*)malloc(sizeof(struct node));
			scanf("%d",&current -> data);
			current -> next = temp;
			 current = temp;
			 free(temp);
		}

	//Giving the values to the last node in the list
		current -> next = NULL;
		scanf("%d",&current -> data);

		tail = current; // making the tail
		//Making the link list into the circular link list
		tail -> next = head;



	//Taking the value to be searched
		int x;
		printf("Enter the value that you want to search in the link list\n");
		scanf("%d",&x);


	//searching for the value in the link list
		int flag = 0;
		current = head;
		while(current -> next != head)
		{
			
			if (current -> data == x)
			{
				printf("The value is found\n");
				flag = 1;
				break;
			}
			current = current -> next;
		}

	//if the entered value is not found in the link list then flag == 0 so;

		if (flag == 0)
		{
			printf("The value is not found in the given link list\n");
		}

	//freeing the memory 
		free(head);
		free(tail);


	return 0;
}