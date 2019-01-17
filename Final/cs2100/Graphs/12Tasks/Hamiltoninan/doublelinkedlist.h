typedef struct node //creating a structure node and giving alias name 'node'
{
	int data;
	struct node *next;
	struct node *pre;
}node;

void createNodes(node **head,int value);
void printNodes(node **head);
