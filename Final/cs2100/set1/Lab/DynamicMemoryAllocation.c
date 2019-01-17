/*
NAME : G.SRIHARSHA;
ROLL : 111601005;
*/
#include<stdio.h>
#include<stdlib.h>
struct student //Defining structure
{
	char name[30];//Declaring member variables of structure student
	int id;
};

void main()
{
	int i,n,max=0,j;
	printf("\n Enter the number N:");//Enter the no of students
	scanf("%d",&n);
	struct student *list ; // Creating a structure pointer
	list = ( struct student *) malloc (n * sizeof(struct student)); //Allocating the memory dynamically
	printf("\n Enter the names and id's of students:");
	for (i=0;i<n;i++) //Enter the data of students
	{
		printf("\n student:%d",i+1);
		scanf("%s",(list+i)->name);
		scanf("%d",&(list+i)->id);
	}
	/*
	for (i=0;i<n;i++) //printing the data of students
	{
		printf("\n %s \t %d \n ",((list+i)->name), ((list+i)->id));
	}*/

	max = (list->id);
	for(i=0;i<n;i++) //checking the max position
	{
		if(((list+i)->id)>max)
		{
		 max=((list+i)->id);
		 j=i;
		}
	}
 
	printf("\n the student with largest id is %s and his id is %d \n" , ((list+j)->name),max);// printing the largest student id
	free(list); //Deallocating the memory
}		
 



























































