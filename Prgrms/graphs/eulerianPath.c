/*

Name - Arpit Singh
Roll number - 111601031
program - This program finds the eulerian cicuit in the graph if exists
*/




//including all the libraries
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

//including all the necesarry header files
#include "graph.h"
#include "queue.h"

//struct for the link list
struct node 
{
	int data;
	struct node* next;
};




void printLinkList (struct node* head)
//given the head this prints the given link list
{
	struct node * current = (struct node*)malloc(sizeof(struct node));
	current = head; // initialising the current
	while (current -> next != head )
	{

		printf("%d  ",current->data);
		current = current -> next; //updating the current
	}

        printf("%d ",head->data);
	printf("\n");
}


int * BFS (struct Graph *graph )
//this function takes the graph , root value and the goal to see wether both are connected or not
{

	int n = graph -> vc;
	Queue Q = newQueue ();
	int *visited = (int *)malloc(n * sizeof(int));
        int start;

        //making all the nodes unvisited
	for (int i =0 ; i < n ; i++)
		visited[i] = 0;

        //checkig for the isolated vertices
        int flag;
        for (int i =0 ; i < n ; i++)
        {
                flag = 0;

                for (int j =0 ; j < n ; j++)
                        if (graph->a[i][j] != 0)
                        {
                                flag = 1;
                                start = i;      //marking not an isolated vertices
                        }

                if (flag == 0)
                        visited[i] = 1;
        }

        enQueue (&Q , start);
	visited[start] = 1;

	while (QueueisEmpty (Q) == 0)
	{
		int vertex = deQueue (&Q);

		//checking all the neighbours
		for (int i =0 ; i < n ; i++)
		{
			if (graph -> a[vertex][i] != 0)
			{
				//if i is not visited
				if (visited[i] != 1)
				{

					visited[i] = 1;
					enQueue(&Q , i);
				}

			}
		}
	}

	return visited;
}

int isEulerian (struct Graph *graph)
//it takes graph as the input and see wether the graph has a eulerian circuit or not
//if it has the eulerian circuit it returns 1 else 0
{
	int n = graph -> vc;
	//this is suppose to store the degree of the vertices
	int *degrees = (int *)malloc(n * sizeof(int));

	for (int i =0 ; i < n ; i++)
		degrees[i] = 0;

	//assigning the degrees of the vertices
	for (int i =0 ; i < n ; i++)
	{
		for (int j =0 ; j < n ; j++)
		{
			if (graph ->a[i][j] == 1)
				degrees[i]++;
		}
	}

	//checking all the vertices are even or not
	for (int i =0 ; i < n ; i++)
		if (degrees[i] % 2 != 0) 		//any vertices with odd degree
			return 0;


	int *visited; 		//to see which of the vertices (note isolated vertices are visited  )
	visited = BFS (graph);

	//checking all the nodes are visited or not //that the graph is connected // not considering into account the isolated vertices
	for (int i =0 ; i < n ; i++)
		if (visited[i] == 0 )
			return 0;

	//if both the conditions are satisfied ; that is there is a eulerian path in the graph
	return 1;
		
}


int graphIsTravelled (struct Graph *graph )
//returns 0 if the graph is not visited else returns 1
{
        int n = graph->vc;
        for (int i =0 ; i < n ; i++)
        {
                for (int j =0 ; j <n ; j++)
                {

                        if (graph->a[i][j] == 1)
                                return 0;
                }

        }

        return 1;
}

int isInlinkList (struct node *head , int intermediate)
//sees if the intermediate value is in the node or not //returns 1 if it is in the node
{
        struct node * current = head;
        while (current != NULL)
        {
                if (current->data == intermediate)
                        return 1;
                
                current = current->next;
        }

        return 0;


}

struct node* findEulerian (struct Graph * graph , int start , struct node ** head)
//this function finds the eulerian path in the cicuit and return it in the form of link list
{

        int n = graph ->vc;
        //declaring the head for the cicular link list

        struct node *c = NULL;
        c = *head;

        
        int current = start; //for keeping track of the vertices

        do
        {

                
                //finding the if all the edges are travelled if not then travelling through it
                for (int j =0 ; j < n ; j++)
                {

                        if (graph -> a[current][j] == 1)
                        {

                                graph->a[current][j] = 0;
                                graph->a[j][current] = 0;
                                current = j;
                                break;          //updating the value of the current indicating that the edge is travelled
                        }

                }

                //updating the value in the link list

                struct node* temp = (struct node *)malloc (sizeof (struct node));
                temp -> data = current;
                c -> next = temp;
                c = temp;

                

        }while (graphIsTravelled(graph) == 0 && start != current); //condition if all the edges are travelled or starting point is different from the current point
        

        c -> next = NULL;       //first setting c to NULL


        //The point is on the starting point and whole graph is not travelled
        //when graph still have some unconnected components
        if (graphIsTravelled (graph) == 0)
        {
                int flag = 0;
                
                //finding the value of the vertice that still have unvisited edge
                int intermediate = -1;
                for (int i = 0 ; i < n ; i++)
                {
                        for (int j = 0; j < n ; j++)
                                if (graph->a[i][j] == 1)
                                {
                                        if (isInlinkList(*head , i  ) == 1)   //if value is in the link list
                                        {        
                                                intermediate = i;
                                                flag = 1;
                                                break;
                                        }
                                }

                        if (flag == 1)
                                break;
                }
                
                
                

                //finding the pointer corresponding to the intermemdiate value in the link list developed so far
                struct node * pointer = NULL;
                struct node * after = NULL;

                pointer = (*head) ;
               
                while (pointer != NULL)
                {
                        if (pointer -> data == intermediate)
                        {      
                                if (pointer -> next != NULL) 
                                after =  pointer -> next;        //for the value after the pointer value to link the list 
                                break;
                        }

                        pointer = pointer -> next;

                }
                
                //applying Eulerian search in the component
                struct node * tale2 = findEulerian(graph , intermediate , &pointer);
                
                //connecting the part to the remaining link list 
                tale2 -> next  = after;

        }

        //returning the tail
        return c;

}

int main ()
{
	//asking for the name of the file
	char filename[1000];
	printf("Enter the name of the file \n");
	scanf("%s",filename);

	//declaring and initialising the graph
	struct Graph graph;
	int check = readGraph (filename , &graph);

	//checking if the filename is incorrect or not
	if (check == 0)
		return 0;

	int n = graph.vc;

	if (isEulerian (&graph) == 0)
	{
		printf("The graph do not have the eulerian path\n");
		return 0;
	}
	 //asking for the value of the starting point
        int start ;
        printf("Enter the point from where you want the Eulerian circuit to start\n");
        scanf("%d",&start);

        //checking if the value of the starting point is greater than the vertex
        if (start >= n)
        {
                printf("vertex does not exist\n");
                return 0;
        }

        //checking if the degree of starting point is zero then terminating
        int degree=0;
        for (int j= 0 ; j< n ; j++)
                if (graph.a[start][j] != 0)
                {
                        degree++;
                        break;
                }



        if (degree == 0)        //if the starting point is isolated then
        {
                printf("The given starting point is isolated so from here you cannot have a Eulerian path\n");
                return 0;
        }

        //counting the number of edges and printing it

        int edges = 0;
        for (int i =0 ; i< n ; i++)
        {
                 for (int j =i ; j< n ; j++)
                {
                        if (graph.a[i][j] == 1)
                                edges++;
                }
                
        }
        printf("the number of edges are %d\n",edges);

        //if the starting point is not isolated then printing the Eulerian circuit
        struct node * head = (struct node * )malloc (sizeof(struct node));
        
        head -> data = start;           //feeding the value of the start in the head data
        struct node *tale = findEulerian (&graph , start , &head);

        //making the link list circular
        tale -> next = head;
        
        //printing the link list
        printf("So the Eulerian path is :  \n");
        printLinkList(head);

	/*
		struct node *current = (struct node *)malloc (sizeof (struct node));
		current = head;
		while (current != tale)
		{
			int x = current -> data;
			current = current -> next;
			int y = current -> data;
			
			 a[x][y] = 1;
			 a[y][x] = 1;
		}
	*/
        return 0;

}

