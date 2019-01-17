#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// A linked list (LL) node to store a queue entry
struct QNode
{
    int key;
    struct QNode *next;
};
 
// The queue, front stores the front node of LL and rear stores ths
// last node of LL
struct Queue
{
    struct QNode *front, *rear;
};
 
// A utility function to create a new linked list node.
struct QNode* newNode(int k)
{
    struct QNode *temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->key = k;
    temp->next = NULL;
    return temp; 
}
 
// A utility function to create an empty queue
struct Queue *createQueue()
{
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}
 
// The function to add a key k to q
void enQueue(struct Queue *q, int k)
{
    // Create a new LL node
    struct QNode *temp = newNode(k);
 
    // If queue is empty, then new node is front and rear both
    if (q->rear == NULL)
    {
       q->front = q->rear = temp;
       return;
    }
 
    // Add the new node at the end of queue and change rear
    q->rear->next = temp;
    q->rear = temp;
}
 
// Function to remove a key from given queue q
struct QNode *deQueue(struct Queue *q)
{
    // If queue is empty, return NULL.
    if (q->front == NULL)
       return NULL;
 
    // Store previous front and move front one node ahead
    struct QNode *temp = q->front;
    q->front = q->front->next;
 
    // If front becomes NULL, then change rear also as NULL
    if (q->front == NULL)
       q->rear = NULL;
    return temp;
}
struct Node
{
    int data;
    struct Node *next;
};
 
struct Node *addToEmpty(struct Node *last, int data)
{
    // This function is only for empty list
    if (last != NULL)
      return last;
 
    // Creating a node dynamically.
    struct Node *temp = 
           (struct Node*)malloc(sizeof(struct Node));
 
    // Assigning the data.
    temp -> data = data;
    last = temp;
 
    // Creating the link.
    last -> next = last;
 
    return last;
}
 
struct Node *addBegin(struct Node *last, int data)
{
    if (last == NULL)
        return addToEmpty(last, data);
 
    struct Node *temp = 
            (struct Node *)malloc(sizeof(struct Node));
 
    temp -> data = data;
    temp -> next = last -> next;
    last -> next = temp;
 
    return last;
}
 
struct Node *addEnd(struct Node *last, int data)
{
    if (last == NULL)
        return addToEmpty(last, data);
     
    struct Node *temp = 
        (struct Node *)malloc(sizeof(struct Node));
 
    temp -> data = data;
    temp -> next = last -> next;
    last -> next = temp;
    last = temp;
 
    return last;
}
 
struct Node *addAfter(struct Node *last, int data, int item)
{
    if (last == NULL)
        return NULL;
 
    struct Node *temp, *p;
    p = last -> next;
    do
    {
        if (p ->data == item)
        {
            temp = (struct Node *)malloc(sizeof(struct Node));
            temp -> data = data;
            temp -> next = p -> next;
            p -> next = temp;
 
            if (p == last)
                last = temp;
            return last;
        }
        p = p -> next;
    }  while(p != last -> next);
	printf("%d not present in the list.\n",item);
    return last;
 
}
 
void traverse(struct Node *last)
{
    struct Node *p;
 
    // If list is empty, return.
    if (last == NULL)
    {
		printf("List is empty.\n");
        return;
    }
 
    // Pointing to first Node of the list.
    p = last -> next;
 
    // Traversing the list.
    do
    {
        printf("%d ",p->data);
        p = p -> next;
 
    }
    while(p != last->next);
 
}
 void printll(struct Node *p)
 {
	 struct Node *a = p;
	 do
	 {
		 printf("%d--",p->data);
		 p = p -> next;
  
	 }
	 while(p != a);
	 
 }

int BFS(char adjmat[][20],int start,int end,int vertice) /*Funtion to perform Breadth First
Search and create the output.dot file */
{
	
	int visit[15];  //To keep track of the visited vertices
	int i,j;
	for(i = 0;i < vertice;i++)
	{
		visit[i] = 0;
	}

	struct Queue *q = createQueue();   //Creating the queue which contains vertices to be explored
	enQueue(q,start);      //Adding starting vertex to be explored
	struct QNode *temp;   //temp stores the dequeued node 
	for(temp = deQueue(q);temp != NULL;temp = deQueue(q)) /* the queue is dequeued everytime
	and that dequeued vertice is explored */ 
	{
		for(j = 0;j < vertice;j++)   
		{
			if((visit[j]==0)&&(adjmat[temp->key][j]=='1'))  //Discovering vertices connected to the currently explored vertex
			{

				if(j == end)         //We've found the end node
				{
					return 1;
				}
				visit[j] = 1;   //Visited elements in the array are marked
				enQueue(q,j);   //Should explore them later,so enqueue

			}
		}
	}
    return 0;
	
}
void assigngraph(char adjmat[][20],char graphtxt[30],char *name,char *type,int *vertice)      //This fuction reads a .txt file and stores values into a matrix
{
	char junk;													//To store \n
	FILE *fptr;
	if ((fptr = fopen(graphtxt, "r")) == NULL)  //Opening  in read mode.
    {
        printf("Error! opening file");
        // Program exits if file pointer returns NULL.
        exit(1);         
    }
	fscanf(fptr,"%s",name);	
	fscanf(fptr,"%s",type);
	fscanf(fptr,"%d",vertice);
	junk = getc(fptr);
	int i=0,j=0;
	for(i = 0;i < *vertice;i++)
	{
		for(j = 0;j < *vertice;j++)
		{	
			adjmat[i][j] = getc(fptr);		//Here,adjmat stores the graph matrix
		}
		junk = getc(fptr);		//To store '\n' 
	}
	fclose(fptr);
}
int check_zero(char arr[],int size)
{
	int i;
	for(i = 0;i < size ;i++)
	{
		if(arr[i] != '0')
		return 0;
	}
	return 1;
}
int check_even(char arr[],int size)
{
	int degree = 0;
	int i;
	for(i = 0;i < size;i++)
	{
		if(arr[i] == '1')
		degree++;
	}	
	if(degree%2 == 0)
	return 1;
	else
	return 0;

}
int check_eularian(char adjmat[][20],int vertice)  //checks if the given graph has an eulerian 
//circuit or not.
{
	int i,j,visit[15],visit_dupli[15];  //storing the visited vertices
	int connect = 0;     //storing the number of connected components in the graph
	int p,k;
	for(i = 0;i < vertice;i++)    //initialising the visited array to 0
	{
		visit[i] = 0;
		visit_dupli[i] = 0;      //just a copy of visited
	}
	for(i = 0;i < vertice;i++)  //checking for isolated vertices and marking them as visited
	//to avoid confusion
	{
		p = check_zero(adjmat[i],vertice);
		if(p == 1)
		{
			visit[i] = 1;
			visit_dupli[i] = 1;
		}
	}
	int bfsval;
    for(i = 0;i < vertice;i++)
    {
		if(visit[i] == 0)
		{
			connect++;
			visit[i] = 1;
		
        for(j = 0;j < vertice;j++)
        {
			bfsval = BFS(adjmat,i,j,vertice);
            if(bfsval == 1 && visit[j] == 0)
            {
                visit[j] = 1;
            }
        }
	    }
    }
	if(connect > 1)
	{
		return 0;
	}
	else
	{
		for(i = 0;i < vertice;i++)
		{
			if(visit_dupli[i] == 0)
			{
				k = check_even(adjmat[i],vertice);
				if(k == 0)
				return 0;
			}
		}	
	}
	return 1;
}
struct Node *euler;
void print_Eularian(char adjmat[][20],int vertice,int start,struct Node *last)//last contains
//the last value of the circular linked list
{

	if(last == NULL)   //base condition-storing the first vertex
	{
		last = addToEmpty(last,start); 
		euler = last;
	}

	int i = start,j;
	do     //storing the first cycle
	{
		for(j = 0;j < vertice;j++)
		{
			if(adjmat[i][j] == '1')  //Checking for edges,adding and then removing them
			{
				last = addEnd(last,j);
				adjmat[i][j] = '0';
				adjmat[j][i] = '0';
				i = j;              //Going to the adjacent vertex
				break;
			}
		}
	}
	while(i != start);    //Condition for completion of one cycle
	int temp;
	struct Node *a;
	a = last;
	do{                       //Go around the cycle and check for remaining edges
		last = last->next;
		temp = check_zero(adjmat[last->data],vertice);   //Checking for remaining edges
		if(temp == 0)
		print_Eularian(adjmat,vertice,last->data,last);		//recursively insert the remaining
		//edges in  the appropriate position in the eulerian circuit
	}while(last != a);  //Condition for completion of one cycle

}
void main()
{
	char adjmat[20][20]; //The graph matrix
	int vertice,start;	//Number of vertices in the graph
	char graphtxt[30],graphname[30],type[5],out[30];		
	printf("Enter the name of the graph text file:\n");
	scanf("%s",graphtxt);  //graphtxt takes the name of the text file containing the graph
	assigngraph(adjmat,graphtxt,graphname,type,&vertice);  //Gets the adjacancy matrix
	struct Node *euler_path=NULL;   	//this will store the vertices in the Eulerian circuit in a 
	//circular linked list
	int t =check_eularian(adjmat,vertice);//checking if the given matrix is Eulerian

	if(t == 1)
	{
		printf("The graph is Eularian\n");
		printf("Enter the start of the Eulerian path:\n");
		scanf("%d",&start);
		print_Eularian(adjmat,vertice,start,euler_path);	//stores the vertices in the circuit in the
		//linked list
		printll(euler);  //prints the linked list

	}
	else
	{
		printf("The graph is not Eularian\n");
	}
}
