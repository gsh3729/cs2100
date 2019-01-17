#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node;
void CreateList(node **,int );
void PrintNodes(node **);
void MergeList();
void main()
{
	node *head1 =NULL,*head2=NULL,*head3=NULL;
	int n1,n2;

	printf("\n Enter the size of first circular list:");
	scanf("%d",&n1);
	printf("\n Enter the size of second circular list:");
	scanf("%d",&n2);
	
	if ((n1-n2)==1)
	{
		printf("\n Enter details of first circular list \n");
		CreateList(&head1,n1);
		printf("\n Enter details of second circular list \n");
		CreateList(&head2,n2);
		printf("\n Data in first circular list ");
		PrintNodes(&head1);
		printf("\n Data in second circular list ");
		PrintNodes(&head2);
	}
	else
	{
		printf("\n sizes you entered must differ by only 1\n");
	}
	MergeList(&head3,&head1,&head2,n1+n2);
	printf("\n Data in new circular list ");
	PrintNodes(&head3);	
}
void CreateList(node **headRef,int n)
{
	int i;
	node *a,*b;
	
	for(i=0;i<n;i++)
	{
		a = ( node*)malloc(sizeof(node));
		printf("\n Enter data in node %d : ",i+1);
		scanf("%d",&(a->data));
		
		if(i==0)
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
void MergeList(node **headRef3,node **headRef1,node **headRef2,int n)
{
	int i;
	node *a,*b;
	
	for(i=0;i<n;i++)
	{
		a = ( node*)malloc(sizeof(node));
		
		
		if(i==0)
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







	
