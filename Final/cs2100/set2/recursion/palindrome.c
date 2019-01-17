/*
	PROGRAMMER'S NAME : G SRIHARSHA
	PROGRAM NAME : palindrome.c
	PROGRAM DESCRIPTION : To check whether the given string is palindrome or not
	DATE=26/08/17   				*/
#include <stdio.h>
int palindrome(char *,int );
void main()
{
	char str[20];
	int i=0,len,f;
	printf("\n Enter the string: ");//entering the input string
	scanf("%s",str);
	while(str[i]!='\0')//finding the length of the string
	{
		i++;
	}
	len=i;
	
	f=palindrome(str,len);//calling the recursion function
	if(f==1)
	{
		printf("\n The entered string is palindrome\n");
	}
	else if(f==0)
	{
		printf("\n The entered string is not palindrome\n");
	}

}
int palindrome(char *str,int len)
{
	if(len==0 || len==1) //terminating conditions for the recursion function
	{
		return 1;
	}
	else if(str[0]==str[len-1]) //checking whether first and last elements are equal or not
	{
		palindrome(str+1,len-2); //If above condition is satisfied then it will again call function to check next elements
	}
	else //If above condition is not satisfied then function going to return 0 and recursion will terminate
	{
		return 0;
	}
}

