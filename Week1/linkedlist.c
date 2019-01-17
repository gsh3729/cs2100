/*
	PROGRAMMER'S NAME : G SRIHARSHA
	PROGRAM NAME : LINKED LIST
	PROGRAM DESCRIPTION : CREATING A LINKED LIST AND INSERTING AND DELETING THE NODE
	DATE=8/08/17   				*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node //creating a structure node and giving alias name 'node'
{
	int data;
	struct node *next;
}node;

void CreateNodes(int n);
void PrintNodes();
void InsertNode(int n);
void DeleteNode(int value);
void ReverseList(node **);
int CheckValue(int);

node *head=NULL; //declaring global pointer variable

void main()
{
	int n,value,i=0;
	
	printf("\n Enter number of nodes required:");
	scanf("%d",&n); 

	CreateNodes(n); //creating the nodes and taking input data from the user
	
	printf("\n Data in the list is"); 
	PrintNodes(); // printing the data in the linked list
	
	printf("\n\n Enter the value:");
	scanf("%d",&value); // Enter the value to insert node after node containing that value
	
	i = CheckValue(value);
   	if(i==1) //checking whether the enterd value is there or not in the linked list
   	{
		InsertNode(value); // Inserting the node
		printf("\n Data in the list after inserting a  node is");
		PrintNodes();
	
		DeleteNode(value); //Deleting the node 
		printf("\n Data in the list after deleting a  node is");
		PrintNodes();
   	}
  	else
   	{
		printf("\n The value you entered is not there in the linked list.So inserting and deleting the node can't be performed\n");
   	}

	ReverseList(&head); //Reversing the linked list
	printf("\n Data in the list after reversing the list is");
	PrintNodes();
	free(head);

	printf("\n");
	
}
void CreateNodes(int n)
{
	node *b,*a;
	int i;

	for(i=0;i<n;i++)
	{
		a = (node *)malloc(sizeof(node)); //Dynamically allocating memory to the node

		printf("\n Enter the data of node %d :",i+1);
		scanf("%d",&(a->data));
		
		if(i==0) //giving proper connections to the linked list
		{
			head=a;	
			a->next = NULL;
			b=a;	
       		}
		else 
		{
			head=a;
			a->next = b;		
			b=a;
		}
	}
}
void PrintNodes() // printing linked list data using pointers in it
{
	node *temp;
	temp=head;

	while(temp!=NULL)
	{
		printf("\n %d",temp->data);
		temp=temp->next;
	}

}
void InsertNode(int value) //function to insert a node in the linked list
{
	node *temp,*newnode;
	temp=head;

	while(temp!=NULL)
	{
		if(value == (temp->data))
		{
			newnode  = (node *)malloc(sizeof(node));//creating a new node

			printf("\n Enter the data of new node  :");
			scanf("%d",&(newnode->data)); 

			newnode->next = temp->next; //inserting the newnode
			temp->next = newnode;
			break;

		}
		temp=temp->next;
	}
		
}	
	
void DeleteNode(int value) //function to delete the node
{	
	node *temp,*q;
	temp=head;

	while(temp!=NULL)
	{ 
		if(value == head->data)//deleting the node and giving proper connections 
		{
			head = temp->next;
			
			break;
		}

		if(value == (temp->data))
		{
			q->next = temp->next;
			
			break;	
		}

		q=temp;
		temp=temp->next;
	}

}

void ReverseList(node **head) //passing the head to get  update from the reversed list 
{
	node *a=NULL,*b,*c;
	b= *head;

	while(b!=NULL)
	{ 
		c=b->next  ; //giving proper connections such that linked list is reversed
		b->next=a;
		a=b;
		b=c;
		
	}
	*head=a;
}
int CheckValue(int value) //checking whether the enterd value is there or not in the linked list
{
	node *temp;
	int i=0;
	temp=head;

	while(temp!=NULL)
	{
		if(value == (temp->data))
		{	
			i=1;
			break;
		}
		temp=temp->next;
	}
  return i;
}
