/*
	PROGRAMMER'S NAME : G SRIHARSHA
	PROGRAM DESCRIPTION : MERGING TWO CIRCULAR LINKED LISTS IN TO 1 CIRCULAR LINKED LIST 
	DATE=6/08/17   				*/
#include <stdio.h>
#include <stdlib.h>
typedef struct node //creating a structure node and giving alias name 'node'
{
	int data;
	struct node *next;
}node;
void CreateList(node **,int );
void PrintNodes(node **);
void MergeList(node **,node*,node*,int,int,int);
void main()
{
	node *head1 =NULL,*head2=NULL,*head3=NULL; //declaring head pointers as NULL
	int n1,n2;

	printf("\n Enter the size of first circular list:");
	scanf("%d",&n1);
	printf("\n Enter the size of second circular list:");
	scanf("%d",&n2);
	
	if ((n1-n2)>=1)
	{
		printf("\n Enter details of first circular list \n");
		CreateList(&head1,n1); //creating linked list 1
		printf("\n Enter details of second circular list \n");
		CreateList(&head2,n2);//creating linked list 2
		printf("\n Data in first circular list ");
		PrintNodes(&head1); //printing data in linked list 1
		printf("\n Data in second circular list ");
		PrintNodes(&head2);//printing data in linked list 2
	}
	else
	{
		printf("\n sizes you entered are invalid\n");
		return ;
	}
	MergeList(&head3,head1,head2,n1,n2,n1+n2); //merging two linked linked lists by using a function
	printf("\n Data in new circular list ");
	PrintNodes(&head3);	
	printf("\n");
}
void CreateList(node **headRef,int n)
{
	int i;
	node *a,*b;
	
	for(i=0;i<n;i++)
	{
		a = ( node*)malloc(sizeof(node)); //dynamically allocating memory
		printf("\n Enter data in node %d : ",i+1);
		scanf("%d",&(a->data));
		
		if(i==0) //giving proper connections to circular linked list 
		{
			*headRef = a;
			a->next = *headRef;
			b=a;
		}
		else
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

	do 
	{
		printf("\n %d",temp->data);
		temp=temp->next;
	}while(temp!= *headRef);

}
void MergeList(node **headRef3,node *headRef1,node *headRef2,int n1,int n2,int n)
{
	int i,z=0;
	node *a,*b;
	
	for(i=0;i<n;i++)
	{
		a = ( node*)malloc(sizeof(node));
		if((i+1)%2!=0) //assigning data for new linked list 
		{
			a->data = headRef1->data;
			headRef1=headRef1->next;
		}
		else
		{
			if(z<n2)
			{
				a->data = headRef2->data;
				headRef2=headRef2->next;
				z++;
			}
			else
			{
				a->data = headRef1->data;
				headRef1=headRef1->next;
			}
		}
		if(i==0) // giving connectitions for new linked list
		{
			*headRef3 = a;
			a->next = *headRef3;
			b=a;
		}
		else
		{
			b->next=a;
			a->next = *headRef3;
			b=a;
		}
	}	
}





	
