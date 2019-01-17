/*
	PROGRAMMER'S NAME : G SRIHARSHA
	PROGRAM NAME : LINKED LIST
	PROGRAM DESCRIPTION : searching the list
	DATE=8/08/17   				*/
#include <stdio.h>
#include <stdlib.h>
typedef struct node//creating a structure node and giving alias name 'node'
{
	int data;
	struct node *next;
}node;
void CreateList(node **,int );
void PrintNodes(node **);
void SearchList(node **,int);
void main()
{
	node *head =NULL;
	int n,value;

	printf("\n Enter N:");//Enter the number of nodes
	scanf("%d",&n);
	
	CreateList(&head,n);//creating the nodes and taking input data from the user
	PrintNodes(&head);// printing the data in the linked list
	
	printf("\n Enter the element you want to search in linked list :");
	scanf("%d",&value);

	SearchList(&head,value);//function to search for the element in the linked list 
}
void CreateList(node **headRef,int n)//creating the nodes and taking input data from the user
{
	int i;
	node *a,*b;
	
	for(i=0;i<n;i++)
	{
		a = ( node*)malloc(sizeof(node));//allocating dynamic memory
		printf("\n Enter data in node %d : ",i+1);
		scanf("%d",&(a->data));
		
		if(i==0) //giving proper connections to head
		{
			*headRef = a;
			a->next = *headRef;
			b=a;
		}
		else//giving proper connections to remaining nodes
		{
			b->next=a;
			a->next = *headRef;
			b=a;
		}
	}
}

void PrintNodes(node **headRef) // printing linked list data using pointers in it
{
	node *temp;
	temp=*headRef;

	do //do while loop to print the list
	{
		printf("\n %d",temp->data);
		temp=temp->next;
	}while(temp!= *headRef);

}
void SearchList(node **headRef,int value)//function to search for the element in the linked list 
{
	int j=0;
	node *temp;
	temp =*headRef;
	do  //do while loop to search the list
	{  	
		if(value == temp->data)
		{   
		 	printf("\n Yes. The value you entered is there in list \n");
			j=1;
		}
		
	   temp=temp->next;
	}while(temp!= *headRef);
	
	if(j==0)
	{
		printf("\n The value you entered is not there in list \n");
	}
}	







	
