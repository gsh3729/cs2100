#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#include "stack.h"

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


void stackPush (stack* stk , int  x)
//this function pases the top of the head and add a node to it
{
	stack temp = (stack)malloc(sizeof(struct stack));
	temp->data = x;
	temp -> next = *stk;
    *stk = temp;
}

int stackPop (stack* stk)
//this function takes the top of the stack and then return the string that is stored in that stack and then also delete that node
{

	if (stackIsEmpty(*stk))
	{
		printf("The stack is empty\n");
		return -1;
	}
	int y;
	y = (*stk)->data;
	*stk = (*stk)->next;
	return y;
}


int  stackTop (stack stk)
//this function simply prints the top element of the stack
{
	return stk->data;
}
