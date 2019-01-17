/*
	PROGRAMMER'S NAME : G SRIHARSHA
	PROGRAM DESCRIPTION : LINKED LIST
	DATE=5/08/17   				*/

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

node *head=NULL; //declaring global pointer variable

void main()
{
	int n,value;
	
	printf("\n Enter number of nodes required:");
	scanf("%d",&n); 

	CreateNodes(n); //creating the nodes and taking input data from the user
	
	printf("\n Data in the list is"); 
	PrintNodes(); // printing the data in the linked list
	
	printf("\n\n Enter the value:");
	scanf("%d",&value); // Enter the value to insert node after node containing that value
	
	InsertNode(value); // Inserting the node
	printf("\n Data in the list after inserting a  node is");
	PrintNodes();
	
	DeleteNode(value); //Deleting the node 
	printf("\n Data in the list after deleting a  node is");
	PrintNodes();
	
	ReverseList(&head); //Reversing the linked list
	printf("\n Data in the list after reversing the list is");
	PrintNodes();

	printf("\n");
	
}
void CreateNodes(int n)
{
	node *b,*a;
	int i;

	for(i=0;i<n;i++)
	{
		a = (node *)malloc(sizeof(node)); //Dynamically allocating memory to the node

		printf("\n Enter the data of node %d :",n-i);
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
void InsertNode(int value)
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
	
void DeleteNode(int value)
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
/*static void reverse(struct Node** head_ref)
{
    struct Node* prev   = NULL;
    struct Node* current = *head_ref;
    struct Node* next;
    while (current != NULL)
    {
        next  = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    *head_ref = prev;
}*/
