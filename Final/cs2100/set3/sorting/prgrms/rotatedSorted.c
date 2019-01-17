/*
	Name - Arpit Singh
	Date - 18 September , 2017
	Roll Number - 111601031
	This program is suppose to find the element in the rotated sorted array
*/

//Declaration of the necessary libraries
	#include <stdio.h>
	#include <stdlib.h>
	#include <limits.h>

//Declaration of the global variables
int pivot;

int binarySearch (int a[] , int p , int r , int target)
//This function searches for the value of target in the given array returns 0 if not found else return 1
// it may be noted that this works if the array is in ascending array
{
	
	if (r<p)  			//terminating condition as this signifies left is less than the right which is not poosible
		return 0;
	

	int mid =p + (r-p)/2;	//finding middle index

	if (a[mid] == target) 	//if the value is found
		return mid;
	

	if (a[mid] > target)	//if target is smaller ; go for the left elements
		return binarySearch (a , p , mid-1 , target);

	if (a[mid] < target)	//if target is greater ; go for the right elements
		return binarySearch (a , mid+1 , r , target);
}
  
//complexity of the program is O(logn) as two times binary search is called on two different subArrays so O(log n) + O(log n) = O(log n)
int findRotate (int a[] , int n , int target)
//This function finds wether the element is in the array or not
{
	//Checking if the value is found in the first subArray or in the second sub Array
		int temp1 = binarySearch (a , 0 , pivot -1 , target);
		int temp2 = binarySearch (a , pivot , n-1 , target);

	//If it is found in the first subArray
		if (temp1!=0)
		{
			return temp1;
		}

	//If value is found in the second sub Array
		if (temp2!=0)	{
			return temp2;
		}

	//else returning -1
		return -1;
}


int main ()
{
	int n;
	printf("Enter number of elements in the array\n");
	scanf("%d",&n);

	pivot = -1; 			//initially the pivot is set to be negative one as upto now no pivot is found in the array 

	int a[n];
	printf("Enter the number of elements in the arrayn\n");
	//Note that it is also going to find the pivot i.e. the point about which the array is rotated

	//Scanning the elements in the  array and also looking for the pivot
		for (int i =0 ; i< n ; i++)
		{
			scanf("%d",&a[i]);
			if (i-1>=0 && a[i-1] > a[i])		//if the value of the previously scanned element is greater then the elements scanned now then that index is the pivot	
				pivot = i;
		}

	//Scanning for the value of the target
		int target;
		printf("Enter the value of the target\n");
		scanf("%d",&target);

	
	int index = findRotate (a , n  , target);

	//if value is not found in any of the sub Arrays
	if (index!=-1)
		printf("The element is found at index %d\n",index);

	else
		printf("The value is not found in the array\n");
		
		return 0;
}