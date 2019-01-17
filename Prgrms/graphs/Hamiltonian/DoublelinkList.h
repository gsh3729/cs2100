//Defining the struct node
	struct node 
	{
		int data ;
		struct node *next;
		struct node *previous;
	};

void printListHead(struct node* head);
void printListTale(struct node* tale);
void addNodeForward (struct node ** tale , int x );
void addNodeBack (struct node ** head , int x );