/*
NAME : G.SRIHARSHA;
ROLL : 111601005;
*/
#include<stdio.h>
#include<string.h>

struct student //Defining structure
{
	char name[30];//Declaring member variables of structure student
	int id;
};
 

void PrintStruc(struct student); 
void ChangingData(struct student *);

void main()
{
	struct student stu1; //Creating a structure 
	struct student *strptr; // Creating a structure pointer
	strptr = &stu1;
	strcpy(stu1.name,"SRIHARSHA");
	stu1.id = 111601005; //Initializing the structure variables
	
	PrintStruc(stu1);
	ChangingData(strptr);
	printf("\nUpdated Name:%s",strptr->name); // printing information after updating data
	printf("\nUpdated ID:%d \n",strptr->id);

}
 
void PrintStruc(struct student s1)//Printing the data
{
	printf("\nStudent name: %s",s1.name);
	printf("\nStudent id: %d",s1.id);
}

void ChangingData(struct student *p)//Changing the data of the structure
{
	strcpy(p->name,"abc");
	p->id=123;
}




















