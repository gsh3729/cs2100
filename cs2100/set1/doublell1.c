/*
	PROGRAMMER'S NAME : G SRIHARSHA
	PROGRAM DESCRIPTION : To find the largest student “name” with largest “ID” in a double linked list 
	DATE=6/08/17   				*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct student //creating a structure student and giving alias name 'node'
{
	char name[30];
	int id;
	struct student *next;
	struct student *pre;
}student;
void CreateList(student **,int n);
void LargeId(student **,int n);
void PrintList(student **,int n);
void main()
{
	student *list=NULL;
	int n;
	printf("\n Enter the number of students :");
	scanf("%d",&n);
	
	CreateList(&list,n);//calling function to create the list by dynamic memory allocation
	PrintList(&list,n);//calling function to print the list of students name's and id's  
	LargeId(&list,n);//calling function to get student having largest id
}
void CreateList(student **list,int n)
{
	student *temp,*a;
	int i;
	char name[30];
	for(i=0;i<n;i++)
	{
		temp = (student *)malloc(sizeof(student));//allocating memory
		printf("\n Enter the name of student %d :",i+1);
		scanf("%s",name);
		strcpy(temp->name,name);
		
		printf("\n Enter the id of student %d :",i+1);
		scanf("%d",&(temp->id));
		
		if(i==0) //giving connections to double linked list
		{
			*list = temp;
			temp->next=NULL;
			temp->pre=NULL;
			a=temp;
		}
		else
		{
			temp->pre=a;
			temp->next=NULL;
			a->next=temp;
			a=temp;
		}
		
	}
}	
void LargeId(student **list,int n)
{
	student *temp;
	temp = *list;
	int i,max=0;
	char n1[30];
	while(temp!=NULL) //finding which is the largest id
	{
		if((temp->id) >= max)
		{
			max = temp->id;
			strcpy(n1,temp->name);
		}
	    temp=temp->next;
	}	
	printf("\n student having largest Id is %s\n",n1); 
}
void PrintList(student **list,int n)
{
	student *temp;
	temp= *list;
	int i=1;
	while(temp!=NULL) //printing details of students
	{	
		printf("\n Details of student %d ",i);
		printf("\n Name : %s",temp->name);
		printf("\n Id : %d\n",temp->id);		
		temp = temp->next;
		i++;
	}
}






			
	
		
			
