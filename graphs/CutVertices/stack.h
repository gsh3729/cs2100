/*
	PROGRAMMER'S NAME : G SRIHARSHA
	ROLLNO:111601005
	PROGRAM DESCRIPTION : 
	PROGRAM NAME :stack.h
	*/


typedef struct stack
{
	int data;
	struct stack *next;
	
}stack;

void pushStack(stack **top,int value);
int popStack(stack **top);
int isEmpty(stack **top);