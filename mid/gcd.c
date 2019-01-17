/*
	PROGRAMMER'S NAME : G SRIHARSHA
	ROLLNO:111601005
	SYSTEM IP:130
	SET:A
	Q:1
	PROGRAM NAME : gcd.c
	PROGRAM DESCRIPTION : finding gcd of two  numbers
	
	   				*/
#include <stdio.h>
int gcd(int a,int b);//function to calculate gcd of two numbers

void main()
{
  	int a, b, result;
  	printf("\n Enter the two positive integer numbers to find their GCD:\n");//enter the inputs
  	scanf("%d%d", &a, &b);

  	result = gcd(a, b);//calling gcd function

  	printf("The GCD of %d and %d is %d\n", a, b, result);

}

int gcd(int a, int b)
{
  	int f;
 	while (a != b) //condition for recursion termination
  	{
        	if(a > b) //when a is greater than b we call gcd(a-b,a)
        	{
	  		f=gcd(a-b, b);
          		return f;
        	}
        	else	//when b is greater than a we call gcd(a,b-a)
        	{
	 		f=gcd(a, b-a);//recursive call
	 		return  f;
		}	
   	}
   	return a;
}	
