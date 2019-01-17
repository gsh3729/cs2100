/*
	Name = Arpit Singh
	Roll.No = 111601031
	Assignment = 2 (Exercise 1)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct student
{
	char name[100];
	int ID;
};

int main()
{
	int N;
	int maxIndex = 0;
	printf("Enter the value of N: \n");
	scanf("%d",&N);
	
	//allocating the memory
	struct student *list = (struct student*) malloc (N * sizeof(struct student));
	//taking the input
	int i;
	printf("Enter the details of the students : \n");
	for (i = 0 ; i < N ; i++)
	{
		scanf("%s",(list+i)->name);
		scanf("%d",&(list+i)->ID);
		
		//finding out the largest ID
		if ((list+i)->ID >= (list+maxIndex)->ID)
			maxIndex = i;

	}

	//printing the name with the largest ID
	printf("The name with the largest Id is: \n");
	printf("%s -- %d\n",(list+maxIndex)->name , (list+maxIndex)->ID);
	free(list);
}

