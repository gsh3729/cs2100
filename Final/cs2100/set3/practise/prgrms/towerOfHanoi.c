//This program is suppose to solve the famous tower of hanoi problem
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

void Tower (int n , int p1 , int p2 , int p3);

int main ()
{
	int n;
	printf("Enter the number of discs in the towers \n");
	scanf("%d",&n);


	printf("The solution to the problem is : \n");
	printf("__________________________________\n");
	Tower (n , 1 , 2 , 3);
	printf("__________________________________\n");
}

void Tower (int n , int p1 , int p2 , int p3)
//This function moves the discs from p1 t0 p3 using p2 as the intermediate
{
	if (n == 1)
		printf("Move disc %d from %d to %d\n", n , p1 ,p3);

	else 
	{
		Tower (n-1 , p1 , p3 , p2);
		printf("Move disc %d from %d to %d\n", n , p1 , p3);
		Tower (n -1 ,p2 , p1 , p3);
	}
}