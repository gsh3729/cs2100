/*
	Name - Arpit Singh
	Roll number - 111601031
	Exercise 3 homework - set 2
	Program Description - It  prints n numbers given by the user
*/

//declaring the libraries
#include <stdio.h>


void printNumbers (int n)
//This function prints the n numbers using recursion
{
	if (n>=0)//recursive condition
	{		
		printf("%d\n",n); //printing the value
		printNumbers(n-1); //recursive call
	}
}

int main ()
{
	//declaring and scanning the value of n
		int n;
		printf("Enter the values of n\n");
		scanf("%d",&n);

	//printing the numbers	
		printf("The numbers are \n");
		printNumbers(n);

	return 0;
}