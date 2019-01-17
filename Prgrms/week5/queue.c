//this program shows the implementation of the circular queue
/*
	Name - Arpit singh
	Roll Number - 111601031
	Homework = 2a
	The problem is the general problem of the queue
*/

//declaring all the libraries
	#include <stdio.h>
	#include <stdlib.h>
	#include <limits.h>
	#include <string.h>

//defining the queue
	struct queue 
	{
		int data;
		struct queue * next;

	};

//typedefing the stack queue*
	typedef struct queue* Queue;

//declaration of all the important functions
	Queue newQueue ();
	Queue rear(Queue q);
	void enQueue (Queue* q , int x);
	void deQueue (Queue *q);
	int QueueSize (Queue q);
	int QueueisEmpty (Queue q);
	void QueueFront (Queue q);


//Main function
	int main()
	{
		Queue myQueue = newQueue (); //declaring new queue
		int x , size;
		while (1)
		{
			//instruction to make the choice
				int choice ;
				printf("===================\n");
				printf("Enter your choice \n");
				printf("1. EnQueue the Queue i.e add an element at the end of the queue\n");
				printf("2. deQueue the Queue\n");
				printf("3. Print the size of the queue\n");
				printf("4. Print the front element of the queue\n");
				printf("5. Print the Queue ; this process will make the queue empty\n");
				printf("6. End the program\n");
				printf("===================\n");


			//scanning the value of choice
				scanf ("%d",&choice);

			//condition for terminating the program
				if (choice == 6)
					break;

			switch (choice) //switch statement for various choices
			{
				case(1):
					size = QueueSize(myQueue);
					if (size >= 10) //if the queue size is greater or equal to 10 then queue is full
					{
						printf("The Queue is full\n");

					}
					//otherwise taking the value and enqueue it into the queue
						else
						{
							printf("Enter the element that you want to enQueue\n");
							scanf("%d",&x);
							enQueue(&myQueue , x);
						
						}

					break;

				case(2): //dequing
					deQueue (&myQueue);
					break;

				case(3): //printing the size
					printf("The size of the queue is : %d\n",QueueSize(myQueue));
					break;

				case(4): //printing the first element
					printf("The front element of the queue is\n");;
					QueueFront(myQueue);
					break;

				case(5): //printing all the values in the queue
					if (myQueue == NULL) //checking wether the queue is empty or not
						printf("The queue is empty \n");

					//otherwise printing the value one by one
					else
					{

						printf("The queue is \n");
						while (myQueue != NULL)
						{
							QueueFront(myQueue);
							deQueue(&myQueue);
						}

					}
					break;

				default: //if the choice entered is incorrect
					printf("The choice entered is invalid\n");
					break;
				
			}
		}

		return 0; //end of the main function
	}


Queue newQueue ()
//This function is suppose to return pointer after creating a new empty circular queue
{
	Queue q = NULL;
	return q; //returnin a NULL pointer
}

Queue rear (Queue q)
//This program returns the pointer to the end of the queue
{
	Queue current = NULL;
	current = q;
	while (current -> next != q)
	{
		current = current -> next; //updating the current step by step until it reaches to the end
	}
	return current;

}

void enQueue (Queue *q , int x)
//This program is suppose to enqueue the queue
{
	//declaring the new pointer and taking the value
		Queue temp = (Queue)malloc(sizeof(struct queue));
		temp -> data = x;

	if (*q == NULL)			//that is the queue is empty then add a node
	{
		temp -> next = temp;
		*q =  temp;

	}

	else //if the queue is not empty then add the node and connect its rear end to the front 
	{
		Queue tail = rear (*q);
		tail -> next = temp;
		temp -> next = *q;
	}

}

void deQueue (Queue *q)
//This function is suppose to deQueue an element from the cicluar Queue
{
	//if  the queue is empty
	if (*q == NULL)
		printf("The Queue is empty !!!\n");

	
	else
	{
		Queue tail = rear (*q);
		if (tail == *q) //if there is only one element in the queue
		{
			*q = NULL;
		}



		else //if more than one element in the node
		{
			(*q) = (*q)-> next; //updating the front 
			tail -> next = *q;	//connecting the rear to the new front
		}
	}
}

int QueueSize (Queue q)
//This function return the size of the queue
{
	if (q == NULL)
		return 0;

	int size = 0;
	Queue current = NULL;
	current = q;


	size = 1;
	//updating the queue as well as updating the size which is the size of the queue
	while (current -> next != q)
	{
		current = current -> next;
		size++;

	}
	return size;
}



int QueueisEmpty (Queue q)
//This function tells wether the queue is empty or not
{
	if (q == NULL)
		return 1;
	else
		return 0; 
}

void QueueFront (Queue q)
//This function prints the front element of the queue 
{
	printf("%d\n",q -> data);

}

