//The program is only evaluating the division as division of two integers in c
/*
	Name - Arpit Singh
	Roll Number - 111601031	
	homework 2
*/
//declaring all the libraries
	#include <stdio.h>
	#include <stdlib.h>
	#include <limits.h>
	#include <string.h>

typedef struct stack* stack;

//Main struct

	struct stack
	{
		int data;
		stack next;
	};
//declaring all the functions

	stack newStack ();
	int stackIsEmpty (stack stk);
	void stackPush (stack* stk , int x);
	int stackPop (stack* stk);
	void stackTop (stack stk);


int main ()
{
	//declaring the necessary variables
		int x , y;
		char temp;
		int ans;


	//scanning the expression
		char expression[100];
		printf("Enter the postFix expression\n");
		scanf("%[^\n]s",expression);

	//declaring the queue
		stack number = newStack();

	//evaluating the expression
		for (int i =0 ; i < strlen(expression) ; i++)
		{

			if (expression[i] <= '9' && expression[i] >= '0' )
			{
				x = expression[i] - 48; //converting the character into integer
				stackPush(&number , x); //pushing all the numbers into the stack

			}
			else
			{
				switch(expression[i]) //if the character is any operator
				{

					case '+': //for sum
						x = stackPop(&number) ; //popping the element
						y = stackPop(&number) ;	//popping the second element
						ans = x + y;
					
						stackPush(&number , ans); //pushing the answer
						break;

					case ('-'): //for subtraction
						x = stackPop(&number) ;
						y = stackPop(&number) ;
						ans = y-x; 					//note it is y - x not x - y as the stack is returning value in reverse order
						stackPush(&number , ans);
						break;

					case ('*'): //for multipication
						x = stackPop(&number) ;
						y = stackPop(&number) ;
						ans = x * y;
						stackPush(&number , ans);
						break;


					case('/'): //for division
					x = stackPop(&number) ;
						y = stackPop(&number) ;
						ans = y/x; 					//note it is integer by integer division so ans is also integer
						
						stackPush(&number , ans);
						break;

					default: //for invalid character
						printf("Invalid expression");
						break;
				}


			}
						
		}
	printf("The value of the expression is : %d\n",stackPop(&number)); //final answer
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


void stackPush (stack* stk , int x)
//this function pases the top of the head and add a node to it
{
	stack temp = (stack)malloc(sizeof(struct stack));
	temp -> data = x;
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


void stackTop (stack stk)
//this function simply prints the top element of the stack
{	
	printf("%d\n",stk->data);
}

