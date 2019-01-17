/*
	PROGRAMMER'S NAME : G SRIHARSHA
	ROLLNO:111601005
	SYSTEM IP:130
	SET:A
	Q:3
	PROGRAM DESCRIPTION : palindrome permutations
	
	   				*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct stack
{
	char data;
	struct stack *next;
	
}stack;

void push(stack **, char );//declaring function prototypes
char pop(stack **);
int isEmpty(stack **);
int isPalindrome(char *str,int len);
void permutations(char *str,int len);

void main()
{
	char a[30];
	int len,i=0;
	stack *top=NULL;
	printf("\n Enter the string(<30) :");
	scanf("%s",a);
	len=strlen(a);
	permutations(a,len);
	
}
int isPalindrome(char *str,int len)
{
	if(len==0 || len==1) //terminating conditions for the recursion function
	{
		return 1;
	}
	else if(str[0]==str[len-1]) //checking whether first and last elements are equal or not
	{
		isPalindrome(str+1,len-2); //If above condition is satisfied then it will again call function to check next elements
	}
	else //If above condition is not satisfied then function going to return 0 and recursion will terminate
	{
		return 0;
	}
}
void permutations(char *str,int len)
{
	//printf("HAO");
	if(isPalindrome(str,len))
	{
		printf("\n %s\n",str);
	}
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






	

	

