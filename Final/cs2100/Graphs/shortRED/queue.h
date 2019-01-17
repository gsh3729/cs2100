/*
	PROGRAMMER'S NAME : G SRIHARSHA
	ROLLNO:111601005
	PROGRAM DESCRIPTION :program, which given a graph and two nodes in that graph tests whether these two nodes are connected and also prints out one of the shortest paths between them (as a sequence of vertices) and reports the distance between the two given nodes.
	PROGRAM NAME : path2nodes.c
	DATE : 3/10/17
	*/


typedef struct queue
{
	char data;
	struct queue *next;
}queue;


void enQueue(queue **front,queue **rear,int value);//declaring function prototypes
int deQueue(queue **front,queue **rear);
int isEmpty(queue **front);







