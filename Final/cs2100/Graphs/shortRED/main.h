/*
	PROGRAMMER'S NAME : G SRIHARSHA
	ROLLNO:111601005
	PROGRAM DESCRIPTION :program, which given a graph and two nodes in that graph tests whether these two nodes are connected and also prints out one of the shortest paths between them (as a sequence of vertices) and reports the distance between the two given nodes.
	PROGRAM NAME : path2nodes.c
	DATE : 3/10/17
	*/


void BreadthFirstSearch(char a[100][100],int n,int n1,int n2,int parent[100]);
void printpath(char a[100][100],int parent[], int j,int *distance,int *red);
int path(int parent[],int i,int j,int n2);
