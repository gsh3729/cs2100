/*
Name = Arpit Singh
Roll number = 111601031
Homework 1
*/

//Declaring all the required libraries
	#include <stdio.h>
	#include <limits.h>
	#include <stdlib.h>

//Defining the struct node
	struct node 
	{
		int data ;
		struct node *next;
		struct node *previous;
	};

//This functon prints the list with the given head

	void printListHead(struct node* head)
	{
		struct node *current = (struct node*)malloc(sizeof(struct node));
		current = head; 				//initialising the current node

		while (current != NULL)
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

//Start of the main function
		
	int main()
	{	
		//initialising and taking the value of N
			int N;
			printf("Enter the number of nodes you want to have\n");
			scanf("%d",&N);

		//declaring the initial nodes and initialising the tale node
			struct node* tale = (struct node*)malloc(sizeof(struct node)); //initialising the tail
			struct node* head;											//declaring head 
			struct node* current;										
		
		//start taking the values in the node ; taking value in tail then in other nodes as they are created
			printf("Enter the number of the elements of the list\n");
			scanf("%d",&tale->data);

			tale -> next = NULL;  //setting tail next to NULL
			current = tale;		//initialising current from the tail

		//building up the link list
			int i;
			for (i =0 ; i < N-1 ; i++)
			{
				struct node* temp = (struct node*)malloc(sizeof(struct node)); //creating a temporary node
				scanf("%d",&temp->data);			//scanning the values
				temp -> next = current;				//setting up the pointers to point in direction
				current -> previous = temp;
				current = temp;						//updating current


			}

			current -> previous = NULL;				//setting head previous to be NULL
			head = current;

		//printing the list
			printf("The list the forward direction (from head) is  as : \n");
			printListHead(head);
			printf("The list in the reverse direction (from tale) is as : \n");
			printListTale(tale);

		//adding the node after a given value of the node
			//asing for the value of the node and setting the flag to 0
				int x , flag = 0;
				printf("Enter the value of the node after which you want to add the node\n");
				scanf("%d",&x);	

			//asking for the value of the node to be added
				int add;
				printf("Enter the value of the node you want to add\n");
				scanf("%d",&add);

			//adding the node
				current = head;	//initialising head
				while (current != NULL)	
				{	//note that after all value of x a node is added with value add
					if (current -> data == x)	//if the value of the node matches x
					{
						struct node* temp = (struct node*)malloc (sizeof(struct node)); //creting a temporary node
						temp -> data = add;					//assigning it the value

						temp -> next = current -> next;		//setting up the pointers correctly
						current -> next = temp;				
						temp -> previous = current;
						current = temp -> next;	//updating the value of the current
						if (current != NULL) //if the current is not equal to NULL then setting the pointer of the current's previous to temp
							current -> previous = temp;
						else
							tale = temp; //this means when the is added at the end of the list
 						
						flag = 1;	//setting value of falg oto be 1 indicating the value is found
						continue;

					}
					current = current -> next;	//if value is not found then updating the current 
				}
			//Printing the message if value is not found in the list	
				if (flag == 0)
					printf("The node with the value entered is not found\n");

			//printing the updated list
				printf("The updated link list in the forward direction \n");
				printListHead(head);

		//Deleting the  node of the given value
			//decaring the necessary pointers
				struct node* before;
				struct node* after;

			//Taking the value of the node to be deleted ; Note it delete all ocurrences of that node
				printf("Enter the value of the node you want to delete\n");
				scanf("%d",&x);


			flag = 0; 	//setting flag = 0 indicating that value is not found yet
			current = head;	
			//If the node to be deleted is the head;
				while (head -> data == x)
				{
					flag = 1; 	//indicating the value is found
					head = current -> next;	//updating head to the next level
					head -> previous = NULL;
					current = head;
				}
				current = head;

			//if the node to deleted is not the head
				while (current != NULL)
				{
					if (current -> data == x)		//checking for the value
					{	
						flag = 1;					//indicating the value is found
						before -> next = after;		//setting up the pointer such that current node is deleted
						if (after != NULL)			//if the after is not NULL
							after -> previous = before;
						free(current);
						current = after;	//updating current
						if (current != NULL)	//updating after
							after = current -> next;
					
					}
					
					
					else
					{
						before = current;	//if the value is not found then setting up after and before
						current = current -> next;
					
						if (current != NULL)	//if the current is NULL ; than there is no next
						{
							after = current -> next;
						}
					}
				}
			tale = before; 	//setting tale to be at end ; this happens if the element is added at the end
			
			//printing message if the value is not found
				if (flag == 0)
					printf("The node with the entered value is not found\n");

			//printing updated list
				printf("The updated link list in the straight order\n");
				printListHead(head);

		//reversing the list
			//reversing the valus of the head and the tale
				struct node * temp;
				temp = head;
				head = tale;
				tale = temp;

			//reversing the directions of all the next
				current = tale;
				before = NULL;
				after = current;

				while (current != NULL)
				{
					after = current -> next;
					current -> next = before;
					before = current;
					current = after; 
				}

			//reversing the direction of all the previous

				current = head;
				before = NULL;
				after = current;
				while(current != NULL)
				{
					after = current -> previous;
					current -> previous = before;
					before = current;
					current = after;
				}

			//printing the updated list
				printf("The reverse list in forward direction is \n");
				printListHead(head);




			return 0;

}
