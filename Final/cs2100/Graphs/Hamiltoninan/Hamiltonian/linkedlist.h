

typedef struct node //creating a structure node and giving alias name 'node'
{
	int data;
	struct node *next;
	struct node *pre;
}node;



void printCircular(node **head);

void doublelinkedlist(node **head,int i);

node* goToLastVertex(node **head);

void printDLL(node **head);

