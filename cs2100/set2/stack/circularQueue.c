/*
	PROGRAMMER'S NAME : G SRIHARSHA
	ROLLNO:111601005
	PROGRAM DESCRIPTION : circular queue
	DATE=1/09/17   				*/
#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
	int data;
	struct queue *next;
}queue;

void enQueue(queue **front,queue **rear,int value);//declaring function prototypes
int deQueue(queue **front,queue **rear);
int isEmpty(queue **front);
void queueFront(queue **front);

void main()
{
	int opt,data,value,size=0;
	queue *front=NULL,*rear=NULL;
	do
        {
	 	printf("\n Menu : \n 1.EnQueue \n 2.DeQueue \n 3.QueueTop \n 4.Size \n 5.Exit \n"); //menu options
		printf("\n Enter your option :");
		scanf("\n %d",&opt);
		if(opt == 1)//checking the options given
		{
			if(size!=10)
			{
				printf("\n Enter the data :");
				scanf("%d",&value);
				enQueue(&front,&rear,value);
				size++;
			}
			else
			{
				printf("\n Queue size is 10 now.So you can't insert the elements in to queue");
			}
		}
		else if(opt == 2)
		{
			if(isEmpty(&front))
			{
				printf("\n Data is %d",deQueue(&front,&rear));
				size--;
			}
			else
			{
				printf("\n pop operation is not valid. Since stack is empty\n");
			} 
		}
		else if(opt == 3)
		{
			queueFront(&front);
		}
		else if(opt == 4)
 		{
			printf("\n Size of stack is %d\n",size);
		}
		else if(opt!=5)
		{
			printf("\n Entered option is invalid.please give another \n");
		}
	}while(opt!=5);	
	
	if(opt == 5)//to print final list of queue
	{
		if( isEmpty(&front) )
		{	
			printf("\n Final list of data in the queue"); 
			while(size!=0)
			{
				if(isEmpty(&front ))
				{
					printf("\n %d",deQueue(&front,&rear));
					size--;
				}
			}
			printf("\n");
		}
		else
		{
			printf("\n Queue is empty.No elements are there in stack to print\n");
		}
	}
	
}
void enQueue(queue **front,queue **rear,int value)//enqueue function
{
	queue *newnode;
	newnode=(queue *)malloc(sizeof(queue));
	newnode->data=value;
	if(isEmpty(front))
	{
		(*rear)->next=newnode;
	}
	else
	{
		*front=newnode;	
	}
	*rear=newnode;
	newnode->next=*front;	
}
int deQueue(queue **front,queue **rear)//dequeue function
{
	int value;
	if(!isEmpty(front))
	{
		printf("\n queue is empty");
		return -1;
	}
	else if(*front==*rear)
	{
		value=(*front)->data;
		*front = NULL;
		*rear = NULL;
		return value;
	}
	else
	{
		value=(*front)->data;
		*front=(*front)->next;
		(*rear)->next=*front;
		return value;
	}


}
void queueFront(queue **front) //to print data in the front of the queue
{
	if(isEmpty(front))
	{
		printf("\n Data in the front of the queue is %d \n",(*front)->data);

	}
	else
	{
		printf("\n queue is empty.So Data in the front of the queue can't be displayed");
	} 

}
int isEmpty(queue **front)//checking whether queue is empty or not
{
	if (*front == NULL)
	{
	return 0;
	}
	else
	{
	return 1;
	}
}
	







	
