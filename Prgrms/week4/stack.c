#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct stack* stack;

typedef struct stack 
{
	char data[50];
	stack prev;
};

stack newStack ()
//this is a fnction that takes no parameter and creates a new stack
{
	stack head = NULL;
	return head;
}

void stackPush (stack stk , string x)
//this function takes the stack pointer and the string x as the parameter and then creates a new node ahead of it
{
	stack node = (stack)malloc(sizeof(struct stack));
	strcpy (node->data,x);
	
}


int main()
{

}


