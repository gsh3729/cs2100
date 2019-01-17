/*
Name = Arpit Singh
Roll no. = 111601031
Week 2 = exercise 3
*/


#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

struct node 
{
	int data;
	struct node* next;

};

void printLinkList (struct node* head)
//given the head this prints the given link list
{
	struct node * current = (struct node*)malloc(sizeof(struct node));
	current = head; // initialising the current
	while (current != NULL)
	{
		
		printf("%d  ",current->data);
		current = current -> next; //updating the current
	}
	printf("\n");
}

int main()
{
	//Taking n as the input
		int N;
		printf("Enter the value of N : \n");
		scanf("%d",&N);

	//creating head and tail in reverse order
		struct node *head = (struct node*)malloc(sizeof(struct node));
		struct node *tale = (struct node*)malloc(sizeof(struct node));
		struct node *current = NULL;
		struct node *temp = NULL;
		current = tale;
		current -> next = NULL;


		printf("Enter the values in the link list\n");
		int i;
		for (i =0 ; i < N -1 ; i++)
		{
			temp = (struct node*)malloc(sizeof(struct node));
			scanf("%d", &current->data);
			temp -> next = current;
			current = temp;
			// freeing the memory

		}
		scanf("%d",&current -> data);
		head = current;

	//Printing the elements of the link list

		printf("The elements in the link list are as follows\n");
		printLinkList(head);
		

		//adding the node after the given value in the link list
		int x;
		printf("Enter the value of the data after which you want to add a node\n");
		scanf("%d",&x);

				int y;
		printf("Enter the value of the node\n");
		scanf("%d",&y);

	//adding the data
		current = head;
		int flag = 1;
		while (current != NULL)
		{
			if (current->data == x)
			{
				temp = (struct node*)malloc(sizeof(struct node));
				temp -> data = y; // value for the additional node
				temp -> next = current -> next;
				current -> next = temp;
				flag = 0;
				
				break;
			}
			current = current-> next;
		}
	//checking wether the value is found or not
		if (flag == 1)
		{
			printf("The value entered is not in the list\n");
		}

	//printing the values again
		printf("The updated elements in the link list are as follows\n");
		printLinkList(head);


	//deleting the node with the values 
		printf("Enter the value of the node that you want to delete\n");
		scanf("%d",&x);
		
		
		flag = 1;
		// if the first node is to be deleted
		while(1)
		{
			if (head -> data == x) 
			{
				head = head -> next;
				flag = 0;
			}
			else
				break;
		}	
		
	   // if the node in between is to be deleted
	   		current = head -> next;	
			struct node *previous = head;
			while(current != NULL)
			{
				//If the value is found deleting the current 
				if (current -> data == x)
				{

					previous -> next = current -> next;
					free(current); // freeing current after deleting
					current = previous -> next; //giving new value to the current
					flag = 0;
					
				}

				else
				{
					//updating current and previous if value not found
					previous = current;
					current = current -> next;
				}
			}


			
			//if the value is not found
			if (flag == 1)
			{
				printf("The value entered is not found \n");

			}

	//printing the values again
		printf("The updated elements in the link list are as follows\n");
		printLinkList(head);

	
	//reversing the link list
		previous = NULL;
		current = head;
		struct node *after = NULL;
		while (current != NULL)
		{
			after = current -> next; //updating after
			current -> next = previous; 
			previous = current;
			current = after; 
		}

		head = previous;

	//Printing the updated list
		printf("The updated and the reversed list \n");
		printLinkList(head);
		



	return 0;


}