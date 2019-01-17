/*
	Name - Arpit Singh 
	Roll number - 111601031
	Program Details = This program sorts the given array (of integers only both positive and negative )using merge sort technique
	Date - 12 August , 2018
*/


//Declaration of all the libraries
	#include <stdio.h>
	#include <stdlib.h>
	#include <limits.h>

//Declaration of all the functions 

	void printArray (int * a , int n);
	void mergeSort (int *a , int p , int r);
	void merge (int *a , int p , int q , int r);

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
		mergeSort (a , 0 , n-1);

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

void mergeSort (int a[] , int p ,int r)
//This is one of the main function of the merge sort technique ; it basically divides the given array into two subarrays and merge their sorted vesion
{
	if (p<r) 		//This is the terminating condition as p >= r then the function will be terminated
	{
	int q = (p+r)/2;		//Finding the mid point 
	mergeSort (a , p , q);		//calling merge Sort again for the first sub Array
	mergeSort (a , q+1 , r);	//Calling merge sort again for the second subarray	
	merge (a , p , q , r);		//merging the two sorted arrays
	}
}

void merge (int a[] , int p , int q , int r)
//This function merges the two sorted arrays
{
	int n1 = q - p + 1; 		//Length of the first and the second sorted subarray
	int n2 = r - q;
	
	//Declaring Both the sub-Arrays 
	int L[n1] ;			
	int R[n2] ;
	
	//declaring the iterators
	int i;	
	int j;

	//Taking value in the first subArray
	for (i = 0 ; i < n1 ; i++)
		L[i] = a[p+i];

	//Taking value in the second subArray
	for (j =0 ; j < n2 ; j++)
		R[j] = a[q+ j + 1];

	//Setting the iterators once again
	i = 0 ;
	j = 0 ;
	int k = p; 
	
	
	//Checking if the which sub - Array elements is smaller and then scanning it to the given input array 
	while (i != n1 && j != n2)
	{
		if (L[i] <= R[j]) 		//if the element of the left array is smaller then copying it to the array a; and incrementing the value of i;
		{
			a[k] = L[i];
			i++;		 
		}

		else 
		{
			a[k] = R[j];		//if the element of the righ array is smaller then copying it to the array a; and incrementing the value of j;
			j++;
		}
		k++;
		
	} 

	//If the first sub array is exhausted then copying the remaining right array to a;
	if (i == n1)
	while (j != n2)  		//copying the elements until whole right array is copied to a
	{
		a[k] = R[j];
		k++;	
		j++;
	}

	//If the second sub array is exhausted then copying the remaining left array to a
	if (j == n2)
	while (i != n1)			//copying the elements until whole left array is copied to a
	{
		a[k] = L[i];
		k++;	
		i++;
	}

}
