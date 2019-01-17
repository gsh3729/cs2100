/*
	Name - Arpit Singh
	Roll Number - 111601031	
	exercise 2b - question1
	Date - 29 - 08 - 2017
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

typedef struct stack* stack;

//Main struct

	struct stack
	{
		char data[100];
		stack next;
	};
//declaring all the functions

	stack newStack ();
	int stackIsEmpty (stack stk);
	void stackPush (stack* stk , char x[]);
	char* stackPop (stack* stk);
	void stackTop (stack stk);

//main function
int main()
{	

	stack myStack = newStack();
	int length = 0;
	char str[100];

	
	while (1)
	{
	printf("Enter the choice that you want to do\n");
	printf("--------------\n");
	printf("	1. Push the element into the stack \n");
	printf("	2. Pop the element from the stack\n");
	printf("	3. Read the top element of the stack\n");
	printf("	4. Print the whole stack \n");
	printf("	5. Print the length of the array\n");
	printf("	6. Exit the program\n");
	
		int choice ;
		printf("Enter your choice \n");
		scanf("%d",&choice);

		switch (choice)
{
		case(1):
			{
				printf("Enter the string you want to add into the array\n");
				scanf("%s",str);
				stackPush(&myStack , str);
				length++;
				break;
			}
		case(2):
			{
				char* x;
				x = stackPop(&myStack);
				if (x != NULL)length--;
				printf ("The data of the popped element is %s\n",x);
				break;
			}
		case(3):
			{
				stackTop(myStack);
				break;
			}
		case (4):
			{
				printf("The stack is \n");
				while (length>0)
				{
					char *x;
					x = stackPop(&myStack);
					length--;
					printf("%s\n",x);
						
				}
				break;
			}
		case(5):
			{
				printf("%d\n",length);
				break;
			}
		case(6):
			{
				return 0;
				break;
			}
		default:
			{
				printf("The value entered is not in the choice \n");
				continue;
			}
}
	}
	
	return 0;

}

stack newStack ()
//this function do not take any parameter it just returns the pointer to create the stack
{
	stack top = NULL;
	return top;
}

int stackIsEmpty (stack stk)
//this returns 0 if the string is not empty and return 1 if the string is empty
{
	if (stk == NULL)
		return 1;
	else 
		return 0;
}


void stackPush (stack* stk , char x[])
//this function pases the top of the head and add a node to it
{
	stack temp = (stack)malloc(sizeof(struct stack));
	strcpy (temp->data , x);
	temp -> next = *stk;
    *stk = temp;
}

char* stackPop (stack* stk)
//this function takes the top of the stack and then return the string that is stored in that stack and then also delete that node
{
	
	if (stackIsEmpty(*stk))
	{
		printf("The stack is empty\n");
		return NULL;
	}

	static char y[100];
	strcpy (y , (*stk)->data);
	*stk = (*stk)->next;
	return y;	
}


void stackTop (stack stk)
//this function simply prints the top element of the stack
{	
	printf("%s\n",stk->data);
}

