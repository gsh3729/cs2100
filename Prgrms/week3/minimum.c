/*
	Name - Arpit Singh
	Roll number - 111601031
	Exercise 2 - set 2
	Program Description - It  finds the minimum of 10 numbers given by the user
*/

//declaring all the necesarry library
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>


int minimum (int * a , int n)
//This function finds the minimum in the given array
{
	int x = *a;
	int flag = 0; //for checking wether a number smaller than this is found in the next part of the array
	
	//finding a number smaller than the present minimum in the next part of the array
		for (int i = 0 ; i < n ; i++)
		{
			if (a[i] < x) //comparing the values
			{
				flag = 1;
				break;
			}
		}

	//if it is the mimimum value
	if (flag == 0)
		return x;

	//If it is not then recursively calling the function again with array leaving the first element
	else
		minimum ( a + 1 , n - 1); //recursive call
}


int main()
{
	int n = 10; //declaration of n

	//decalring array and scanning it's values
		int * a = (int *)malloc (n * sizeof(int));
		printf("Enter the elements of the array \n");
		
		for (int i =0 ; i < n; i++)
		{
			scanf("%d",&a[i]);
		}

	int min = minimum(a , n); //calling the function
	printf("The smallest value is : %d\n",min); // printing the smallest value

	free (a);
	return 0;


}