/*
	PROGRAMMER'S NAME : G SRIHARSHA
	ROLLNO:111601005
	PROGRAM DESCRIPTION : creating a stack and using it
	DATE=29/08/17   				*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack
{
	char name[20];
	struct stack *next;
	
}stack;

void push(stack **, char []);//declaring functions prototypes
void pop(stack **);
int  isEmpty(stack **);
void stackTop(stack **);


void main()
{
	int opt;
	char movie[20];
	stack *top=NULL;//assigning top pointer null
	do
        {
	 	printf("\n Menu : \n 1.Push \n 2.Pop \n 3.StackTop \n 4.Exit \n"); //enter the options
		printf("\n Enter your option :");
		scanf("%d",&opt);
		if(opt == 1)//checking the conditions and performing required actions
		{
			printf("\n Enter the movie :");
			scanf("%s",movie);
			push(&top,movie);
		}
		else if(opt == 2)
		{
			pop(&top);
		}
		else if(opt == 3)
		{
			stackTop(&top);
		}
		else if(opt!=4)
		{
			printf("\n Entered option is invalid.please give another \n");
		}
	}while(opt!=4);	
}
void push(stack **top,char a[])//function to push the element in to stack
{
	stack *temp;
	temp=(stack *)malloc(sizeof(stack));
	strcpy(temp->name,a);
	temp->next=*top;
	*top=temp;
}
void pop(stack **top)//function to pop out the element
{
	stack *temp;	
	if(*top != NULL)
	{
		temp=*top;
		printf("\n Movie name is %s",temp->name); 
		*top=(*top)->next;
	}
	else
	{
		printf("\n Stack is empty");
	}
}	
int isEmpty(stack **top)//checking whether the stack is empty or not
{
	if (*top == NULL)
	return 1;
	else
	return 0;
}
void stackTop(stack **top)
{	
	if(*top!=NULL)
	{
		printf("\n Movie in the top of the list is %s \n",(*top)->name);
	}
	else
	{
		printf("\n Stack is empty.So movie in the top of the stack can't be displayed");
	} 
}

