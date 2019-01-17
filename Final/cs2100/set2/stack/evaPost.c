/*
	PROGRAMMER'S NAME : G SRIHARSHA
	ROLLNO:111601005
	PROGRAM DESCRIPTION : evaluating a postfix expression
	DATE=1/09/17   				*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack
{
	int data;
	struct stack *next;
}stack;

void push(stack **,char);//declaring function prototypes
char pop(stack **);
int isEmpty(stack **);
char stackTop(stack **);

void main()
{
	int i=0;
	char n1,n2,e,result;
	char exp[20];
	stack *top=NULL;
	printf("\n Enter the postfix expression to evaluate :");
	scanf("%s",exp);
	while(exp[i]!='\0')
	{	
		if(isdigit(exp[i]))//if it is a digit we are pushing it in to stack
		{
			push(&top,exp[i]-'0');
		}
		else //doing calculations 
		{
			n1=pop(&top);
			n2=pop(&top);
			if(exp[i]=='+')
			{
				e=n1+n2;
				push(&top,e);
			}
			else if(exp[i]=='*')
			{
				e=n1*n2;
				push(&top,e);
			}		
			else if(exp[i]=='-')
			{
				e=n2-n1;
				push(&top,e);
			}
			else if(exp[i]=='/')
			{
				e=n2/n1;
				push(&top,e);
			}
		}
		i++;
	}
	result=pop(&top);
	printf("\n Evaluated value of the postfix expression is %d\n",result);
}
void push(stack **top,char a)//push function
{
	stack *temp;
	temp=(stack *)malloc(sizeof(stack));
	temp->data=a;
	temp->next=*top;
	*top=temp;
}


char pop(stack **top)//pop function
{
	char x;
	stack *temp;	
	if( isEmpty(top) )
	{
		temp=*top;
		x=temp->data; 
		(*top)=(*top)->next;
		free(temp);
		return x;
	}
	else
	{
		printf("\n Stack is empty");
		return 0;
	}
}

int isEmpty(stack **top)//checking whether stack is empty or not
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































