/*
	PROGRAMMER'S NAME : G SRIHARSHA
	PROGRAM NAME : printNumbers.c
	PROGRAM DESCRIPTION : printing the numbers from given number to 0
	DATE=26/08/17   				*/
#include <stdio.h>
void print(int n);
void main()
{
	int n;
	printf("\n Enter the number");//entering the input number
	scanf("%d",&n);
	print(n);//calling recursion function to print numbers
}
void print(int n)
{
	if(n>=0) //checking whether the number is greater than zero or not to print that number
	{
		printf("%d\n",n);
		print(n-1);
	}
}
	
	
