/*
	Name - Arpit Singh
	Roll number - 111601031
	Exercise 1 - week 3 - set 2
	Program Description - This is used to find the fibonacci numbers
*/


#include <stdio.h>

long long int fibonacci (int n)
//this function calculates the nth fibonacci numbe
{	
	if (n == 0 ) //if n == 0 return 0 terminating condition
		return 0;

	else if (n == 1)  //if n == 1 return 1
		return 1;

	else 
		return fibonacci(n-1) + fibonacci(n -2); //recursive call
}


int main()
{
	//declaring and taking the value of n
		int n;
		printf("Enter the value of n : \n");
		scanf("%d",&n);

	//printing the n starting fibonacci numbers	
		printf("The n fibonacci numbers are\n");
		for (int i =0 ; i < n -1; i++)
		printf("%d fibonacci number is - %lld\n",i+1,fibonacci(i)); //calling the fibonacci number to find the ith fibonacci number

	return 0; //ending of the program


}