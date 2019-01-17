#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct stack * stack;

struct stack 
{
	char data[100];
	stack next;
}

stack newStack ();
int stackIsEmpty (stack stk);
void stackPush (stack *stk , char x[]);
char * stackPop (stack * stk);
void stackTop (stack stk);


int main ()
{

}

stack newStack ()
//This creates the new stack and returns it

{
	stack temp = NULL;
	return temp;
}

int stackIsEmpty (stack stk)
{
	if (stk == NULL)
		return 1;
	else
		return 0;
}

void stackPush (stack *stk , char x[])
//push the element on the stack
{
	stack temp = (stack)malloc (sizeof(struct stack));
	strcpy (temp->data , x);
	temp -> next = *stk;
	*stk = temp; 
}

char *stackPop (stack *stk)
{
	if (stackIsEmpty (*stk) == NULL)
	{	
		printf("The stack is empty\n");
		return NULL;
	}

	else
	{
		static char y[1000];
		strcpy(y , (*stk)->data );
		*stk = (*stk) -> next;
		return y;
	}
}

void stackTop (stack stk)
{
	printf("The top element is %s",stk->data);
}
