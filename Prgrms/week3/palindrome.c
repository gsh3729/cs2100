/*
	Name - Arpit Singh
	Roll number - 111601031
	Exercise Homework 2
	Program Description - This progrma checks wether the given array and the string are palindrome or not
*/

//Declaring all the necesarry library
	#include <stdio.h>
	#include <stdlib.h>
	#include <limits.h>
	#include <string.h>

int palindromestring (char * a , int n)
//checking wether the string is palindrome
{
	if (n == 1 || n == 0) //terminating condition if the n == 1 and n == 0
		return 0;

	else if (n == 2 && a[0] == a[1]) // if n == 2 check wether both elements are same or not if same then returning 0 meaning it is a palindrome
		return 0;

	else if ( a[0]  ==  a[n-1]) //check first and last elements are same or not ; if same then call it again
		palindromestring (a + 1 , n -2);
	else
		return -1; //else return -1 indicating it is not a palindrome
}



int main ()
{


	//declaring the string and initialising it
		char string[100];
		printf("Enter the string : \n");
		scanf("%s",string);


	//checking if the string is palindrome or not
		if (palindromestring( string , strlen(string)) == 0)
			printf("Yes it is a palindrome\n");
		
		else
			printf("No it is not a palindrome\n");


	return 0;
}