/*
	PROGRAMMER'S NAME : G SRIHARSHA
	ROLLNO:111601005
	PROGRAM DESCRIPTION : infix to postfix conversion
	DATE=1/09/17   				*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct stack
{
	char data;
	struct stack *next;
	
}stack;

void push(stack **, char );//declaring function prototypes
char pop(stack **);
int isEmpty(stack **);
char stackTop(stack **);
int isOperator(char e);
int checkPriority(char e);

void main()
{
	int i=0,e;
	char exp[20];
	stack *top=NULL;
	printf("\n Enter the infix expression to convert it in to postfix expression :");
	scanf("%s",exp);//enter the required expression
	while(exp[i]!='\0')//algorithm to convert infix to postfix
	{
		if(isdigit(exp[i]))
		{
			printf("%c",exp[i]);
			i++;
			continue;
		}
		
		if(exp[i]=='(')
		{
			push(&top,exp[i]);
			i++;
			continue;
		}
		
		if(isOperator(exp[i]))
		{
			if(!isEmpty(&top))
			{
				push(&top,exp[i]);
			}
			else if(stackTop(&top)=='(')
			{
				push(&top,exp[i]);
			}
			else if(checkPriority(exp[i]) > checkPriority(stackTop(&top)))
			{
				push(&top,exp[i]);
			}
			else
			{
				printf("%c",pop(&top));
				continue;
			}
			i++;
		}
		if(exp[i]==')')
		{
			while(stackTop(&top)!='(')
			{
				printf("%c",pop(&top));
			}
			pop(&top);
			i++;
		}


		if(exp[i]=='(')
   		{
     
     			push(&top,exp[i]);
     			i++;
     			continue;  
   		}
	}
	while(isEmpty(&top))
  	{
    		printf("%c",pop(&top));
	}
	printf("\n");	
}
int isOperator(char c)//to check whether it is operator or not
{
	if(c=='+'||c=='*'||c=='-'||c=='/')
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}
int checkPriority(char c)//to give priority to the operators
{
 	if(c=='+' || c=='-')
    	{
        	return 1;
 	}
	else if(c=='*' || c=='/')
    	{
        	return 2;
 	}
	else if(c=='^')
    	{
        	return 3;
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
char stackTop(stack **top)//function to return top of the stack
{
  	return (*top)->data;
}
void push(stack **top,char c)//push function
{
  	stack *temp;
	temp=(struct stack *)(malloc(sizeof(struct stack)));
  	temp->data=c;
  	temp->next=*top;
  	*top=temp;
}
char pop(stack **top)//pop function
{
  	char c;
  	stack *temp;
  	temp=*top;
  	(*top)=(*top)->next;
  	c=temp->data;
  	return c; 
}
		



















