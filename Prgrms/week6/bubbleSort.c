/*
	Name - Arpit Singh 
	Roll number - 111601031
	Program Details = This program sorts the given array (of integers only both positive and negative )using bubble sort technique in descending order
	Date - 12 August , 2018
*/


//Declaration of all the libraries
	#include <stdio.h>
	#include <stdlib.h>
	#include <limits.h>

//Declaration of all the functions 

	void printArray (int * a , int n);
	void bubbleSort (int *a , int n);
	void swap (int *a , int * b);


//Main function
	int main ()
	{
		//declaring and scanning the value of n
			int n;
			printf("Enter the number of elements in the array\n");
			scanf("%d",&n);

		//Declaration and scanning of the array
			int a[n];
			printf("Enter the elements in the array\n");
			for (int i =0 ; i < n ; i++)
				scanf("%d",&a[i]);

		//printing the given array

		printf("The entered array is \n");
		printArray (a , n);

		//Calliing the function to sort the array using merge sort
		bubbleSort (a , n);

		//printing the updated array
		printf("The updated array is \n");
		printArray (a , n);

		//end of the main function
		return 0;
	
	}


void printArray (int a[] , int n)
//This function prints the given array
{
	//printing the elements one by one 
	for (int i =0 ; i< n ; i++)
		printf("%2d\n",a[i]);


	printf("\n"); //newLine

}

void bubbleSort (int *a , int n)
//This function sort the given array of integers in the ascending order
{	
	int flag;
	do 
	{
		flag = 0;
		for (int i =0 ; i< n-1 ; i++)
		{
			if (a[i] < a[i+1])
			{
				swap (&a[i] , &a[i+1]);
				flag ++;
			}
		}
		
	}while (flag != 0);
}

void swap (int *a , int *b)
//This function swap two given elements
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
