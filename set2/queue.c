#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
	int data;
	struct stack *front;
	struct stack *rear;
}queue;
void main()
{
	int opt,data,value,size=0;
	queue *front=NULL,*rear=NULL;
	do
        {
	 	printf("\n Menu : \n 1.EnQueue \n 2.DeQueue \n 3.QueueTop \n 4.Exit \n"); 
		printf("\n Enter your option :");
		scanf("\n %d",&opt);
		if(opt == 1)
		{
			if(size!=10)
			{
				printf("\n Enter the data :");
				scanf("%d",value);
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
			deQueue(&front,&rear);
		}
		else if(opt == 3)
		{
			stackTop(&front);
		}
		else if(opt!=4)
		{
			printf("\n Entered option is invalid.please give another \n");
		}
	}while(opt!=4);	
}
enQueue(queue **front,queue **rear,int value)
{

}
int isEmpty(queue **rear);
{
	if (*rear == NULL)
	{
	return 0;
	}
	else
	{
	return 1;
	}
}
	







	
