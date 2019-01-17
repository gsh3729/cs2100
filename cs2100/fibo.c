/*
	PROGRAMMER'S NAME : G SRIHARSHA
	PROGRAM NAME : fibo.c
	PROGRAM DESCRIPTION : printing the fibonacci numbers up to given number
	DATE=22/08/17   				*/
#include <stdio.h>
int fibo(int n)
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
	printf("\n Enter the number N:");
	scanf("%d",&n);
	printf("\n Fibonacci series is ");
	for(i=0;i<n;i++)
	{
		f=fibo(i);
		printf("%d",f);
		if(i!=n-1)
		{
		 printf(",");
		}
	}
	printf("\n");
}

	
