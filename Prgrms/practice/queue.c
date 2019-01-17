#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct queue 
{
	int data;
	struct queue * next;
}

typedef struct queue * Queue;

Queue newQueue ()
//This function returns an empty queue
{
	Queue temp = NULL;
	return temp;
}

Queue rear (Queue q)
{
	Queue current = NULL;
	current = q;
	while (current -> next == q)
	{
		current = current -> next;
	}
	return current;
}

void enQueue (Queue *q , int x)
{
	Queue temp = (Queue)malloc(sizeof (struct queue));
	temp -> data = x;

	if (*q == NULL)
	{
		temp ->next = temp;
		*q = temp;
	}

	else
	{
		Queue tail = rear (Queue *q);
		tail -> next = temp;
		temp -> next = *q;
	}
}

void deQueue (Queue *q)
{
	if (*q == NULL)
	{
		printf("The Queue is empty\n");
	}

	else 
	{

		Queue tail = rear(*q);
		if (tail == *q)
		{
			*q = NULL;
		}

		else
		{
			tail -> next = (*q) -> next;
			*q = (*q) -> next;
		}
	}
}

int QueueSize (Queue q)
{
	if (q == NULL)
		return 0;

	else
	{
		int size = 0;
		Queue current = NULL;
		current = q;
		size = 1;

		while (current -> next != q)
		{
			size++;
			current = current -> next;
		}

		return size;
	}
}

int queueIsEmpty (Queue q)
{
	if (q == NULL)
		return 1;
	else
		return 0;
}

void QueueFront (Queue q)
{
	printf("%d", q->data);
}



int main ()
{

}
