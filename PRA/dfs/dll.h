
//Header file for dll.c

struct s_int
{
  int data;
  struct s_int *next;
};

struct q_int
{
    struct s_int *head; // NULL if empty, points to first-in node o/w
    //struct s_int *tail; // NULL if empty, points to last-in node o/e
    int length;
};

struct q_int* create_q();

void push(struct q_int *q , int value);

int pop(struct q_int *q );

int top(struct q_int *q );

void print_q(struct q_int *queue);

struct graph{                           //structure to store info for graph
    char a[50][50];
    char name[50],type[20];
    int n,path[50],parent[50];
    char input_graph[40],output_dot[40];
};
typedef struct graph Graph;

void readAdj( Graph *g);				//function to read a graph file and store the adjacency matrix in array a

void makeDot( Graph *g);					//function to make the dot file

//int BFS( Graph *g , int x , int y);          //breadth first search function to check if x and y are connected

void DFS(Graph *g,int x,struct q_int *stack,int *visited);

int min(Graph *g,int *w,int x,int *vis);
