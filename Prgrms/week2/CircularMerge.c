/*
Name = Arpit Singh
Roll number = 111601031
Homework = 2 (set1)
*/

//declaring all the required libraries

	#include <stdio.h>
	#include <limits.h>
	#include <stdlib.h>


//declaring the node
	struct node 
	{
		int data;
		struct node* next;
	};

//a Function to print the circular list
	void printList(struct node * head)
	{
		struct node * current; //initialising and declaring the current
		current = head;
		
		do
		{
			printf("%d   ",current->data);		//printing the values
			current = current -> next;
		}while (current != head);				//checkinkg wether the comes to head again

		printf("\n");
	}
	
//start of the main function
	int main ()
	{	
		//declaring and initilisin the variables
			int n1 , n2;
			printf("Enter the values of n1 and n2 such that n1 >= n2\n");
			scanf("%d %d",&n1 , &n2);

		//checking if the value entered is wrond ; if that is so end of the program
			if (n1 < n2)
			{
				printf("The value entered are wrong\n");
				return 0;
			}	

		//declaring the first cicular list with head1 and number of nodes n1
			
			//initialising the nodes and declaring it
				struct node * head1 = (struct node *)malloc(sizeof(struct node));
				struct node * tale1 = (struct node *)malloc(sizeof(struct node));
				struct node *current;

			//start scanning the values in the node
				printf("Enter the values of the element of the 1st link list\n");
				scanf("%d",&head1->data);


			current = head1; //initialising the current
			int i;

			for (i =0 ; i < n1 -1 ; i++)
			{
				struct node *temp = (struct node*)malloc(sizeof(struct node)); //creating a temporary node and assigning the value
				scanf("%d",&temp-> data);
				current -> next = temp;
				current = temp;

			}

			//making the loop circular
				current -> next = NULL;
				tale1 = current;
				tale1 -> next =  head1;
			
			//printing the 1st lisn list
				printf("The first link list is \n");
				printList(head1);


		//declaring the first cicular list with head2 and number of nodes n2

			//initialising the nodes and declaring it
				struct node * head2 = (struct node *)malloc(sizeof(struct node));
				struct node * tale2 = (struct node *)malloc(sizeof(struct node));


			//start scanning the values in the node
				printf("Enter the values of the element of the 2nd link list\n");
				scanf("%d",&head2->data);

			current = head2;
			
			for (i =0 ; i < n2 -1 ; i++)
			{
				struct node *temp = (struct node*)malloc(sizeof(struct node));//creating a temporary node and assigning the value
				scanf("%d",&temp-> data);
				current -> next = temp;
				current = temp;

			}

			//making the loop circular
				current -> next = NULL;
				tale2 = current;
				tale2 -> next =  head2;
			
			//printing the 1st lisn list
				printf("The second link list is \n");
				printList(head2);

	    //merging two link list
			//initialising the nodes and declaring it
				struct node * current1;
				struct node * current2;
				struct node * head;
				head = head1;	//copying the first list
				current1 = head;
				current2 = head2;

			do
			{
				struct node * after1;	//initialisng and delcaring the after1 for 1st list and after2 for second link 2
				struct node * after2;
				after1 = current1 -> next;	
				after2 = current2 -> next;

				current1 -> next = current2;	//inserting node of 2 list in 1st one
				current2 -> next = after1;
				current1 = after1;	//updating the current values
				current2 = after2;

			}while (current2 != head2); //this condition looks for all the nodes in the list 2


		//printing the merge list
			printf("The merge Circular list is\n");
			printList(head);


		return 0;

	}
