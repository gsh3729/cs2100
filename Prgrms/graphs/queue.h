
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
	int deQueue (Queue *q);
	int QueueSize (Queue q);
	int QueueisEmpty (Queue q);
	int QueueFront (Queue q);


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

int deQueue (Queue *q)
//This function is suppose to deQueue an element from the cicluar Queue
{
	//if  the queue is empty
	if (*q == NULL)
	{
		printf("The Queue is empty !!!\n");
		return -1;
	}

	
	else
	{
		int value = (*q)->data;
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

		return value;
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

int QueueFront (Queue q)
//This function prints the front element of the queue 
{
	return q -> data;

}
