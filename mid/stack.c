/*
	PROGRAMMER'S NAME : G SRIHARSHA
	ROLLNO:111601005
	SYSTEM IP:130
	SET:A
	Q:2
	PROGRAM DESCRIPTION : auto mobile service register

	   				*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack
{
	int num;
	struct stack *next;

}stack;

void push(stack **, int );//declaring functions prototypes
int pop(stack **);
int isEmpty(stack **);

void main()
{
	int opt;
	int size = 0;
	int num,k,a;
	stack *top1=NULL,*top2=NULL;//assigning top pointers null
	do
        {
	 	printf("\n Menu : \n 1.Insert \n 2.Next \n 3.Display \n 4.Exit \n"); //enter the options
		printf("\n Enter your option :");
		scanf("%d",&opt);
		if(opt == 1)//checking the conditions and performing required actions
		{
			if(isEmpty(&top1)==0) //when the stack is empty
			{
				printf("\n Enter the new licence plate number :");
				scanf("%d",&num);
				push(&top1,num);
				size++;
			}
			else//when stack is not empty
			{
				printf("\n Enter the new licence plate number :");
				scanf("%d",&num);
				k=size;
				while(k!=0)
				{
					push(&top2,pop(&top1)); //shifting all elements in stack 1 to stack 2
					k--;
				}
				push(&top1,num);//pushing the new element to the bottom of the stack
				while(k!=size)
				{
					push(&top1,pop(&top2));//bringing back from stack 2 to stack 1
					k++;
				}
				size++;
			}

		}
		else if(opt == 2)
		{
			if(isEmpty(&top1))
			{
				printf("\n Next car licence number is %d",pop(&top1));//printing next car waiting for service
				size--;
			}
			else
			{
				printf("\n No next cars are available (stack is empty)\n");
			}
		}
		else if(opt == 3)
		{

			if(isEmpty(&top1))
			{
				printf("\n list of cars that are waiting to be serviced\n");
				k=size;
				while(k!=0) //we will pop the first element in stack 1 and push it to stack 2  till stack 1 is empty
				{
					a=pop(&top1);
					printf(" %d\n",a); //displaying the list of car numbers
					push(&top2,a);
					k--;
				}

				while(k!=size) //bringing back from stack 2 to stack 1
				{
					push(&top1,pop(&top2));
					k++;
				}
			}
			else				
			{
				printf("\n No cars are waiting to get serviced\n");
			}
		}
		else if(opt!=4)
		{
			printf("\n Entered option is invalid.please give another \n");
		}
	}while(opt!=4);


}
void push(stack **top,int b)//function to push the element in to stack
{
	stack *temp;
	temp=(stack *)malloc(sizeof(stack));
	(temp->num)=b;
	temp->next=*top;
	*top=temp;
}
int pop(stack **top)//function to pop out the element
{
	int a;
	stack *temp;
	if( isEmpty(top) )
	{
		temp=*top;
		a=temp->num;
		*top=(*top)->next;
		free(temp);
		return a;
	}
	else
	{
		printf("\n Stack is empty(pop)");
		return 0;
	}
}
int isEmpty(stack **top)//checking whether the stack is empty or not
{
	if (*top == NULL)
	{
	return 0;
	}
	else
	{
	return 1;
	}
}
