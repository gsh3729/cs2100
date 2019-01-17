/*
	PROGRAMMER'S NAME : G SRIHARSHA
	PROGRAM DESCRIPTION : 
	DATE=6/08/17   				*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node //creating a structure node and giving alias name 'node'
{
	int data;
	struct student *next;
	struct student *pre;
}node;
void CreateList(node **,int n);
void PrintList(node **,int n);
void main()
{
	student *head=NULL;
	int n;
	printf("\n Enter the number of nodes :");
	scanf("%d",&n);
	
	CreateList(&head,n);//calling function to create the list by dynamic memory allocation
	PrintList(&head,n);//calling function to print the list of students name's and id's  
	LargeId(&head,n);//calling function to get student having largest id
}
void CreateList(node **head,int n)
{
	node *temp,*a;
	int i;
	for(i=0;i<n;i++)
	{
		temp = (node *)malloc(sizeof(node));//allocating memory
		printf("\n Enter the data of node %d :",i+1);
		scanf("%d",&temp->data);
				
		if(i==0) //giving connections to double linked list
		{
			*head = temp;
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
void PrintList(node **list,int n)
{
	node *temp;
	temp = *head;
	int i=1;
	while(temp!=NULL) //printing details of students
	{	
		printf("\n Data in node %d is %d",i,temp->data);
		temp = temp->next;
		i++;
	}
}






			
	
		
			
