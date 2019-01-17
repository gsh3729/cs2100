/*
	PROGRAMMER'S NAME : G SRIHARSHA
	ROLLNO:111601005
	PROGRAM DESCRIPTION : 
	PROGRAM NAME :stack.c
	*/
#include<stdio.h>
#include<stdlib.h>
#include "stack.h"


void pushStack(stack **top,int value)//function to push the element in to stack
{
	stack *temp;
	temp=(stack *)malloc(sizeof(stack));
	temp->data=value;
	temp->next=*top;
	*top=temp;
}
int popStack(stack **top)//function to pop out the element
{
	int x;
	stack *temp;	
	if( isEmpty(top) )
	{
		temp=*top;
		x=temp->data;
		*top=(*top)->next;
		free(temp);
		return x;
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