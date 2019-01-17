/*
	PROGRAMMER'S NAME : G SRIHARSHA
	ROLLNO:111601005
	PROGRAM NAME : fibo.c
	PROGRAM DESCRIPTION : printing the fibonacci numbers up to given number
	DATE=22/08/17   				*/
#include <stdio.h>
int fibo(int n)//function to calculate fibonacci numbers
{
	if(n==0)
      	return 0;
   	else if(n==1)
      	return 1;
   	else
	return fibo(n-1)+fibo(n-2);
}
void main()
{
	int n,i,f;
	printf("\n Enter the number N:"); //taking input of the number of finonacci numbers required
	scanf("%d",&n);
	printf("\n Fibonacci series is ");
	for(i=0;i<n;i++)
	{
		f=fibo(i);//calling recursion function to get numbers
		printf("%d",f);
		if(i!=n-1)
		{
		 printf(",");
		}
	}
	printf("\n");
}

	
