/*
	Name - Arpit Singh 
	Roll number - 111601031
	Program Details = This program sorts the given array (of integers only both positive and negative )using quick sort technique in ascending order most eficient
	Date - 12 August , 2017
*/


//Declaration of all the libraries
	#include <stdio.h>
	#include <stdlib.h>
	#include <limits.h>

//Declaration of all the functions 

	void printArray (int * a , int n);
	void quickSort (int *a , int p , int r);
	int partition (int *a , int p , int r);
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
		quickSort (a , 0 ,  n-1);

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
			printf("%d  ",a[i]);


		printf("\n"); //newLine

	}

void swap (int *a , int *b)
//This function swap two given elements
	{
		int temp = *a;
		*a = *b;
		*b = temp;
	}

void quickSort (int *a , int p , int r)
//This function finds the pivot and then break the array in two sub - arrays ; which further calls quickSort
	{
		if (p<r)
		{
			int q = partition (a , p , r);		//This gets the int q as the point where the pivot is placed
			quickSort (a , p , q-1 );		//This furher sorts the element to the 
			quickSort (a , q+1 , r);
		}
	}

int  partition (int *a , int p , int r)
//This function arranges the array in such a way that all the elements to the left are smaller or equal to pivot and to the right are greater than the pivot
//It may be noted that the pivot selected is from the left
	{
		int pivot = a[p]; 		//This selects the pivot to be the left most element in the array
		int i = p;			//initialising the array with i = p

		//This loop makes the element smaller than the pivot to the left and element larger than or equal to the pivot to the right
			for (int j = p+1 ; j <= r ; j++)
			{
				if (a[j] < pivot)						//if element is smaller than the array then the element is exchanged with the element corresponding to i
				{
					i++;
					swap (&a[i] , &a[j]);
				}
			}

		int j;											//This process shifts all elements smaller than pivot to one position left so as to make room for pivot in between
		for ( j = p+1 ; j <= i ; j++)
			a[j-1] = a[j];

		a[i] = pivot;

		return i;
	}



