//This program checks wether the element in the matrix is zero or not and then make the whole row or col zero
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

void scan2Darray (int rows , int cols , int a[][cols]);
void print2Darray (int rows , int cols , int a[][cols]);

int main ()
{
	int rows, cols;
	printf("Enter the number of rows\n");
	scanf ("%d",&rows);

	printf("Enter the number of cols\n");
	scanf("%d",&cols);

	int a[rows][cols];

	scan2Darray (rows,cols , a);
	print2Darray (rows , cols , a );


	int b[rows];
	int c[cols];

	for (int i =0 ; i< rows ; i++)
		b[i] = -1;

	for (int i =0 ; i < cols ; i++)
		c[i] = -1;

	int count1 = 0;
	//Main solution
	for (int  i =0 ; i < rows ; i++)
	{
		for (int j =0 ; j < cols ; j++)
		{
			if (a[i][j] == 0)
			{
				b[count1] = i;
				c[count1] = j;
				count1++;
			}
		}
	}

	for (int i =0 ; i<count1 ; i++)
	{
		//making row 0
		for (int k = 0 ; k < cols ; k++)
			a[b[i]][k] = 0;

		for (int k =0 ; k<rows ; k++ )
			a[k][c[i]] = 0;
	}

	print2Darray (rows , cols , a);


}

void scan2Darray (int rows , int cols , int a[][cols])
//This function scans the matrix
{
	printf("Enter the elements of the 2D matrix\n");
	for (int i =0 ; i < rows ; i++)
	{
		for (int j = 0 ; j < cols ; j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
}

void print2Darray (int rows , int cols , int a[][cols])
//This function prints the matrix 
{
	printf("The updaetd matrix is\n");
	for (int i =0 ; i<rows ; i++)
	{
		for (int j =0 ; j<cols ; j++)
		{
			printf("%d  ",a[i][j]);
		}
		printf("\n");
	}
}
