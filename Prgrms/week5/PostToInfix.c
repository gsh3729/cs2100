/*
	Name - Arpit Singh
	Roll Number - 111601031	
	Homework question - 3
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
		char data;
		stack next;
	};
//declaring all the functions

	stack newStack ();
	int stackIsEmpty (stack stk);
	void stackPush (stack* stk , char x);
	char stackPop (stack* stk);
	char stackTop (stack stk);
	int precedence (char a);

//main function
	int main()
	{
		//scanning the infix expression
			char infix[100];
			char temp;
			printf("Enter the infix expression\n");
			scanf("%s",infix);

		//asking the associativity
			printf("Determine associativity\n");
			printf("1. Left associative \n");
			printf("2. Right associative \n");
			int associativity;
			scanf("%d",&associativity);

		//declaring the stack to store operators
			stack operators = newStack();
			
		//implementing the logic
			for (int i =0 ; i < strlen(infix) ; i++) //this for loop runs until all character are evaluated
			{
				//if the character is number then printing the number
					if (infix[i] <= '9' && infix[i] >= '0')
						printf("%c",infix[i]);


				//if the character is left paranthesis
					else if (infix[i] == '(')
					{
						stackPush(&operators , infix[i]);
					}

				// if the character is right paranthesis
					else if (infix[i] == ')')
					{	

						while (stackTop(operators) != '(')
							printf("%c",stackPop(&operators) );

						temp = stackPop(&operators);


					}

				//if the characters are operators

					else 
					{
						//stack is empty
						if (stackIsEmpty(operators))
							stackPush(&operators , infix[i]);


						//when stack is not empty
						else
						{ 	//for higher precedence
							if (precedence(infix[i]) > precedence(stackTop(operators)) )
							{
								stackPush(&operators , infix[i]);
							}

							//for equal precedence

							else if (precedence(infix[i]) == precedence(stackTop(operators)))
							{

								if (associativity == 1) // left associative
								{
									printf("%c",stackPop(&operators));
									stackPush(&operators , infix[i]);
								}

								else if (associativity == 2) // Right associative
								{
									stackPush(&operators , infix[i]);

								}

							}

							//for lower precedence
							else if (precedence(infix[i]) < precedence(stackTop(operators)))
							{
								while (precedence(infix[i])  > precedence(stackTop(operators)))
								{
									printf("%c",stackPop(&operators));
								}
								stackPush(&operators , infix[i]);
							}
						}
					}

			}

		//printing the remaining operators
			while (operators != NULL)
			{
				printf("%c",stackPop(&operators));
			}
			

		printf("\n");
		return 0; //end of the main function
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


void stackPush (stack* stk , char x)
//this function pases the top of the head and add a node to it
{
	stack temp = (stack)malloc(sizeof(struct stack));
	temp->data = x;
	temp -> next = *stk;
    *stk = temp;
}

char stackPop (stack* stk)
//this function takes the top of the stack and then return the string that is stored in that stack and then also delete that node
{
	
	if (stackIsEmpty(*stk))
	{
		printf("The stack is empty\n");
		return ' ';
	}
	int y;

	y = (*stk)->data;
	*stk = (*stk)->next;
	return y;	
}


char stackTop (stack stk)
//this function simply prints the top element of the stack
{	
	return stk->data;
}

int precedence (char a)
//This function returns the integer according to the precedence
{
	if (a == '+' || a == '-')
		return 1;

	else if (a == '*' || a == '/')
		return 2; 
}

