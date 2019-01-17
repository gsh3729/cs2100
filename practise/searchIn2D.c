/*
	Name - Arpit Singh
	Roll number - 111601031
	Date - 17 September 2017
	This program is suppose to search an element in the sorted 2D array
*/

/*
	complexity of the program is O(n*log(m)) where n corresponds to the number of rows and m corresponds to the coloumns 
	since binary search is applied on each of the rows ; since number of rows = n and worst case length of binary search in each of the coloumns is log(m)
	Note the above complexity is with regard with the search operation only 
	if consider the whole code
*/
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int sortCheckAsscending ( int rows  , int cols , int a[][cols] , int value , int i , int j)
//This function returns 1 if adjacent elements to the given element are either greater or equal to the given given element
//return -1 ; if no element is to be compared
//It may be noted that this function compares the value of the element with the previous element in the same row and the same coloumn if they exist
//return 0 ; otherwise

{
	
	
	if (i -1 < 0  &&  j- 1 < 0)
		return -1;

	else if (i-1>=0 && j -1 < 0)
	{
		if (value < a[i-1][j] )
		return 0;
	}
	else if (i-1<0 && j -1 >= 0)
	{
		if (value < a[i][j-1])
		return 0;
	}
	else	
	{
		if (value < a[i][j-1] || value < a[i-1][j])
		return 0;
	}
	return 1;
}

int sortCheckDescending (int rows  , int cols , int a[][cols] , int value , int i , int j)
//This function returns 1 if adjacent elements to the given element are either greater or equal to the given given element
//return -1 ; if no element is to be compared
//It may be noted that this function compares the value of the element with the previous element in the same row and the same coloumn if they exist
//return 0 ; otherwise
{
	
	
	if (i -1 < 0  && j - 1 < 0)
		return -1;

	else if (i-1>=0 && j -1 < 0)
	{	
		if (value > a[i-1][j] )
		return 0;
	}

	else if (i-1<0 && j -1 >= 0)	
	{
		if (value > a[i][j-1])
		return 0;
	}
	else
	{
		if (value > a[i][j-1] || value > a[i-1][j])
		return 0;
	}
	return 1;
}

int binarySearch1 (int a[] , int p , int r , int target)
//This function searches for the value of target in the given array returns 0 if not found else return 1
// it may be noted that this works if the array is in ascending array
{
	
	if (r<p)  			//terminating condition as this signifies left is less than the right which is not poosible
		return 0;
	

	int mid =p + (r-p)/2;	//finding middle index

	if (a[mid] == target) 	//if the value is found
		return 1;
	

	if (a[mid] > target)	//if target is smaller ; go for the left elements
		return binarySearch1 (a , p , mid-1 , target);

	if (a[mid] < target)	//if target is greater ; go for the right elements
		return binarySearch1 (a , mid+1 , r , target);
}
 
int binarySearch2 (int a[] , int p , int r , int target)
//This function searches for the value of target in the given array returns 0 if not found else return 1
// it may be noted that this works if the array is in descending array
{
	
	if (r<p)  			//terminating condition as this signifies left is less than the right which is not poosible
		return 0;
	

	int mid =p + (r-p)/2;	//finding middle index

	if (a[mid] == target) 	//if the value is found
		return 1;
	

	if (a[mid] < target)	//if target is smaller ; go for the right elements
		return binarySearch2 (a , p , mid-1 , target);

	if (a[mid] > target)	//if target is greater ; go for the left elements
		return binarySearch2 (a , mid+1 , r , target);
}
 



int main ()
{
	int rows , cols;
	printf("Enter the number of rows\n");
	scanf("%d",&rows);

	printf("Enter the number of coloumns\n");
	scanf("%d",&cols);

	int a[rows][cols];
	printf("Enter the elements in the array\n Note the 2D array must be sorted\n");

	int flag1 = 0;
	int flag2 = 0;

	for (int i =0 ; i< rows ;i ++)
	{
		for (int j = 0 ; j < cols ; j++)
		{
			scanf("%d",&a[i][j]);
			int temp1 = sortCheckAsscending(rows , cols , a,  a[i][j] , i , j ); //taking the value of ascending function in temp1
			int temp2 = sortCheckDescending(rows , cols , a,  a[i][j] , i , j ); // taking the value of descending function in temp2
			if (temp1 == 1 && temp2 == 0) 				//i.e. the current element is strictly greater than the adjacent element
				flag1++;



			if  (temp2 == 1 && temp1 == 0)				//i.e. the current element is strictly less than the adjacent element //adjacent element means element just above or left of the given element
				flag2++;

			
			if (flag1 != 0 && flag2 != 0)				//if both are non zero that means atleast once the matrix has both ascended or descended
			{											//which is not possible so return after printing the error message
				printf ("Invalid entry ; The entered 2 dimensional array is not sorted\n");
				return 0;
			}

		}
	}
	//Asking for the value of the target
	int target;
	printf("Enter the value of the target that you want to find in the matrix\n");
	scanf("%d",&target);

	//finding the element in 2 D dimensional array
	//It may be noted that this calls the binary search in each of the rows since each of the rows is sorted
	//So the complexity of the program is O(rows * log(cols)) as the complexity of binary search in cols is log(cols) and it is repeated rows number of times
	
	//if the sorted matrix is ascending
	if (flag1 != 0)
	{	
		for (int i =0 ; i< rows ; i++)
		{
				if (binarySearch1 (a[i] , 0 , cols-1 , target )==1)
				{
					printf("Yes ; The value is found in the matrix\n");
					return 0;										//Since the value is found so end of the program
				}
		}
	}

	if (flag2 != 0)
	{
		for (int i =0 ; i< rows ; i++)
		{
				if (binarySearch2 (a[i] , 0 , cols-1 , target )==1)
				{
					printf("Yes ; The value is found in the matrix\n");
					return 0;										//Since the value is found so end of the program
				}
		}

	}
	//If the value  is not found then it will be out of the loop so
	printf("The target value is not in the matrix\n");
	return 0;
}
