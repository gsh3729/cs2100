/*
	PROGRAMMER'S NAME : G SRIHARSHA
	ROLLNO:111601005
	PROGRAM DESCRIPTION : This program is suppose to take 2D - matrix as the input and create a sorted list from that matrix
	DATE=12/09/17   				*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int scan2Darray (int n , int a[][n]);
void print2Darray (int n , int a[][n]);
int isAscending (int n , int a[][n] , int i , int j , int value);
void generatingArray (int b[] , int n , int a[][n]);
int merge (int b[] , int c[] , int n1 , int n );
void printArray (int a[] , int n);

int main ()
{
	int n;
	printf("\n Enter the number of rows and columns");
	scanf("%d",&n);
	int a[n][n];

	int flag;
	flag = scan2Darray ( n , a);

	if (flag == 1)
	{
		printf("The array entered is not ascending \n");
		return 0;
	}

	print2Darray ( n , a);
	int b[n*n];
	generatingArray (b , n , a);
	printArray (b , n*n);


}

int isAscending (int n , int a[][n] , int i , int j , int value)
//This function checks wether the 2D array entered is ascending or not
//This returns 1 if the 2D array is ascending otherwise returns 0
{
	if (i-1 < 0 && j - 1 < 0)
		return 1;

	else if (i-1>=0 && j-1 < 0)
	{
		if (a[i-1][j] > value)
			return 0;
	}

	else if (i - 1 < 0 && j -1 >= 0)
	{
		if (a[i][j-1] > value)
			return 0;
	}

	else 
	{
		if (a[i-1][j] > value || a[i][j-1] > value)
			return 0;
	}

	return 1;
}

int scan2Darray (int n , int a[][n])
//This function scans the 2D array keeping in mind that it must be ascending
{
	printf("Enter the elements of the 2D matrix\n");
	for (int i =0 ; i < n ; i++)
	{
		for (int j = 0 ; j < n ; j++)
		{
			scanf ("%d",&a[i][j]);

			if (isAscending (n , a , i , j , a[i][j]) == 0)
				return 1;
		}
	}
	return 0;
}

void print2Darray (int n , int a[][n])
//This function prints the updated array
{
	printf("The updated matrix is \n");
	for (int i = 0 ; i < n ; i++)
	{
		for (int j =0 ; j < n ; j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}

}

void generatingArray (int b[] , int n , int a[][n])
//This function generates the sorted one dimensional array from the given array
{
	int n1 = 0; 		//length of b;
	int n2 = n; 		//length of each of the rows and coloumns of a

	for (int i =0 ; i< n ; i++)		//Copying first row to b
		b[i] = a[0][i];

	n1 = n; 				//length of B is updated

	for (int i = 1 ; i < n ; i++)
	{

		n1 = merge (b , a[i] , n1 , n);
	}


}

int merge (int b[] , int c[] , int n1 , int n )
//This function takes b as the input which is the final array
//c as the input which is the array to be merged in b
//n1 updated length of b array;
//length of c array
//return updated length of b
{
	int d[n1];
	int n2 = n;

	for (int i = 0 ; i < n1 ; i++)		//copying the updated array into the new array ; Note both of them are ascending
		d[i] = b[i];



	int i = 0;		//i for c //length is n2
	int j = 0;		//j for d //length is n1
	int k = 0;		//k for updated b


	while (i != n2 && j!= n1)
	{
		if (d[j] >= c[i])
			b[k++] = c[i++];

		else
			b[k++] = d[j++];
	}

	if (i == n2)
		while (j < n1)
			b[k++] = c[j++];

	if (j == n1)
		while( i < n2)
			b[k++] = c[i++];

		//printArray (b , n1);


	return k;

}

void printArray (int a[] , int n)
{
	printf("The array is \n");
	for (int i =0 ; i< n ; i++)
		printf("%d  ",a[i]);

	printf("\n");
}



