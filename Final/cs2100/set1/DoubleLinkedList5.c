/*
	PROGRAMMER'S NAME : G SRIHARSHA
	PROGRAM NAME : DOUBLE LINKED LIST
	PROGRAM DESCRIPTION : CREATING A DOUBLE LINKED LIST AND INSERTING AND DELETING THE NODE
	DATE=13/08/17   				*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node //creating a structure node and giving alias name 'node'
{
	int data;
	struct node *next;
	struct node *pre;
}node;

void CreateNodes(int n);
void PrintNodes();
void InsertNode(int n);
void DeleteNode(int value);
void ReverseList(node **);
int CheckValue(int);
void FreeMemory();

node *head=NULL; //declaring global pointer variable

void main()
{
	int n,value,i=0;
	
	printf("\n Enter number of nodes required:");
	scanf("%d",&n); 

	if(n!=0)
	{

		CreateNodes(n); //creating the nodes and taking input data from the user
	
		printf("\n Data in the list is"); 
		PrintNodes(); // printing the data in the doublelinked list
	
		printf("\n\n Enter the value:");
		scanf("%d",&value); // Enter the value to insert node after node containing that value
	
		i = CheckValue(value);
   		if(i==1) //checking whether the enterd value is there or not in the linked list
   		{
			InsertNode(value); // Inserting the node
			printf("\n Data in the list after inserting a  node is");
			PrintNodes();
	
			DeleteNode(value); //Deleting the node 
			if(head!=NULL)
			{
				printf("\n Data in the list after deleting a  node is");
				PrintNodes();
   			}
			else
			{
				printf("\n After deleting the nodes the list is empty\n");
				return;
			}
		}
  		else
   		{
			printf("\n The value you entered is not there in the linked list.So inserting and deleting the node can't be performed\n");
   		}

		ReverseList(&head); //Reversing the linked list
		printf("\n Data in the list after reversing the list is");
		PrintNodes();
		FreeMemory();

		printf("\n");
	}
	else
	{
		printf("\n please enter the number of nodes greater than zero\n");
	}
	
}
void CreateNodes(int n)
{
	node *temp,*a;
	int i;

	for(i=0;i<n;i++)
	{
		temp = (node *)malloc(sizeof(node)); //Dynamically allocating memory to the node

		printf("\n Enter the data of node %d :",i+1);
		scanf("%d",&(temp->data));

		if(i==0) //giving connections to double linked list
		{
			head = temp;
			temp->next=NULL;
			temp->pre=NULL;
			a=temp;
		}
		else
		{
			temp->pre=NULL;
			head=temp;
			temp->next=a;
			a->pre=temp;
			a=temp;
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
			newnode->pre=temp;
			if(newnode->next !=NULL)
			newnode->next->pre=newnode;
			break;

		}
		temp=temp->next;
	}
		
}	
	
void DeleteNode(int value) //function to delete the node
{	
	int i=0;
	node *temp,*q;
	temp=head;

	while(temp!=NULL)
	{ 
		if(value == head->data && temp==head)//deleting the node and giving proper connections 
		{
			head = temp->next;
			if(temp->next!=NULL)
			{
				temp->next->pre=NULL;
			}
			temp=head;
			continue;
		}

		if(value == temp->data)
		{
			q->next = temp->next;
			if(temp->next!=NULL)
			{
			temp->next->pre=q;
			}
			temp=temp->next;
			continue;	
		}

		q=temp;
		temp=temp->next;
	}

}

void ReverseList(node **head) //passing the head to get  update from the reversed list 
{
	node *a=NULL,*b;
	b= *head;

	while(b!=NULL)
	{ 
		a=b->pre;
		b->pre=b->next;
		b->next=a;
		b=b->pre;
		
	}
	if(a!=NULL)
	{
		*head=a->pre;
	}
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
void FreeMemory()
{
	node *temp,*a;
	temp=head;
	while(temp!=NULL)
	{
		a=temp;
		temp=temp->next;
		free(a);
	}
}





