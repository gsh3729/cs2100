/*
Name = Arpit singh
Roll number = 111601031
Assignment 1 (Exercise 1)

*/
#include <stdio.h>
#include <string.h>

struct student
{
	char name[100];
	int ID;
};
void PrintStruc (struct student *stu)
//This program simply prints the details of the students
{
	printf("%s\n%d\n",stu->name,stu->ID);
	
}

void Change (struct student *strptr)
//change the details of the students
{
	strcpy(strptr->name , "abc");
	strptr->ID = 123;
}

int main()
{
	struct student stu1;
	strcpy(stu1.name , "Arpit Singh");
	stu1.ID = 10;

	printf("Old Information\n");
	PrintStruc(&stu1);
	Change(&stu1);

	printf("New Information\n");
	printf("%s\n%d\n",stu1.name , stu1.ID);
	return 0;
}
