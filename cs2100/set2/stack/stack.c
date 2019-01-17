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
char* pop(stack **);
int isEmpty(stack **);
void stackTop(stack **);


void main()
{
	int opt;
	int size = 0;
	char movie[20];
	stack *top=NULL;//assigning top pointer null
	do
        {
	 	printf("\n Menu : \n 1.Push \n 2.Pop \n 3.StackTop \n 4.Size \n 5.Exit \n"); //enter the options
		printf("\n Enter your option :");
		scanf("%d",&opt);
		if(opt == 1)//checking the conditions and performing required actions
		{
			printf("\n Enter the movie :");
			scanf("%s",movie);
			push(&top,movie);
			size ++;
		}
		else if(opt == 2)
		{
			if(isEmpty(&top))
			{
				printf("\n Movie is %s",pop(&top));
				size--;
			}
			else
			{
				printf("\n pop operation is not valid. Since stack is empty\n");
			}   
		}
		else if(opt == 3)
		{
			stackTop(&top);
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

	if(opt == 5)//To print the final list in the stack
	{
		if(isEmpty(&top))
		{	
			printf("\n Size of stack is  %d",size);
			printf("\n Final list of movies in the stack"); 
			while(size!=0)
			{
				if(isEmpty(&top))
				{
					printf("\n %s",pop(&top));
					size--;
				}	
			}
			printf("\n");
		}
		else
		{
			printf("\n Stack is empty.No elements are there in stack to print\n");
		}
	}
}
void push(stack **top,char b[])//function to push the element in to stack
{
	stack *temp;
	temp=(stack *)malloc(sizeof(stack));
	strcpy(temp->name,b);
	temp->next=*top;
	*top=temp;
}
char* pop(stack **top)//function to pop out the element
{
	static char a[20];
	stack *temp;	
	if( isEmpty(top) )
	{
		temp=*top;
		strcpy(a,temp->name);
		*top=(*top)->next;
		free(temp);
		return a;
	}
	else
	{
		printf("\n Stack is empty");
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
void stackTop(stack **top)
{	
	if(isEmpty(top))
	{
		printf("\n Movie in the top of the list is %s \n",(*top)->name);

	}
	else
	{
		printf("\n Stack is empty.So movie in the top of the stack can't be displayed");
	} 
}

