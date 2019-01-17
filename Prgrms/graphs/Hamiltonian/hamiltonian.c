/*

Name - Arpit Singh
Roll number - 111601031
program - This program finds the Hamiltonian cycle in a hamiltonian Graph . Note it assumes that the graph have the hamiltonian cycle
*/




//including all the libraries
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

//including all the necesarry header files
#include "graph.h"
#include "DoublelinkList.h"


struct node * maximalPath (struct Graph *graph ,  struct node **head , int *visited)
//this function takes the head of the link list and returns the tale of the link list containing the maximal path
{
	//taking the starting point as node zero
	int n = graph -> vc;
	int start = 0;

	//declaring the tale
	struct node *tale = (struct node*)malloc (sizeof(struct node));

	//setting the data of the head to be equal to the start and making it the tale as well
	(*head)->data = start;
	tale -> data = start;

	//making it just the singal node
	(*head) -> next = NULL;
	(*head) -> previous = NULL;

	tale = (*head);

	//making the array that contains points that are visited
	
	for (int i =0 ; i < n ; i ++)
		visited[i] = 0;

	visited[start] = 1;
	int current = start; 	

	//start to extend the start in one direction
	while (1)
	{
		
		int flag = 0;
		for (int i = 0 ; i < n ; i ++)
			if (graph -> a[current][i] == 1 && visited[i] == 0)	//if i is adjacent to current vertex and it is adjacent to the vertex i
			{	
			  	flag = 1; 										//indicating such value is found
				current = i;									//updating the value of the current
			}

		if (flag == 0)
			break;

		else
		{
			addNodeForward (&tale , current);
			visited[current] = 1;
		}

	}



	//start to extend the path in the opposite direction
	current = start;
	while (1)
	{
		int flag = 0;
		for (int i = 0 ; i < n ; i ++)
			if (graph -> a[current][i] == 1 && visited[i] == 0)	//if i is adjacent to current vertex and it is adjacent to the vertex i
			{	
			  	flag = 1; 										//indicating such value is found
				current = i;									//updating the value of the current
			}

		if (flag == 0)
			break;

		else
		{
			addNodeBack (&(*head) , current);
			visited[current] = 1;
		}
	}

	//returning the tale of the  double link list
	return tale;

}

void findAndMakeCylce (struct Graph * graph , struct node **head , struct node** tale)
//this function finds the cycle and make it into circular link list
{
	//finding and making the cycle

		int start = (*head) -> data;
		int end = (*tale) -> data;
	//finding the closed cycle
		struct node* current = (struct node*)malloc (sizeof(struct node));
		current = (*head);
			
		//for storing the value of the break where the point of forming cycle is found
		int cycle = -1;									//the point where the cycle is attached to the starting point 


		while (current  != NULL)
		{

			int temp = current -> data;
			current = current -> next;
			int tempNext = current -> data;

			if (graph->a[start][tempNext] == 1 && graph->a[end][temp] == 1)	//cycle is found ; note cycle is always found
			{
				cycle = temp;
				break;
			}
	
		}
		
		

		//this before correspond to the cycle point in the double link list
		struct node *before = current -> previous;
		struct node *after = current;

	

	//current corresponds to temp next ; or next to cycle	
	//making a double list a circular link list
				
				//reversing the directions of all the next
				current = (*head)->next ;
				
				

				struct node* tempBefore = (*head);
				struct node* tempAfter = current;
				
		
				while (current != after)
				{
					tempAfter = current -> next;
					current -> next = tempBefore;
					tempBefore = current;
					current = tempAfter; 
				}
		
		//reversing the direction of the previous pointers
			//reversing the direction of all the previous

				current = before->previous;
				tempBefore = before;
				tempAfter = current;
				while(current != (*head))
				{
					tempAfter = current -> previous;
					current -> previous = tempBefore;
					tempBefore = current;
					current = tempAfter;
				}


	//connecting the head to the current
		(*head)->previous = (*head)->next;
		(*head) -> next = after;
		after -> previous = (*head);

	//connecting the tale to the point before the current
		(*tale) -> next = before;
		before -> previous = (*tale);




		
}

int lenOfCycle (struct node * head)
//this function returns the len of cycle
{
	struct node *current = head;
	int counter = 1;

	while (current -> next != head)
	{
		counter++;
		current = current -> next;
	} 

	return counter;
}


//code for the main function
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
	int visited[n];

	//finding the maximal path in graph G
		struct node *head = (struct node *)malloc (sizeof(struct node));
		struct node * tale = maximalPath (&graph , &head , visited);


		

	//finding and making a cycle
		findAndMakeCylce (&graph , &head , &tale);
		
		while (lenOfCycle(head) != n)
		{
			//printf("hiii\n");
			struct node *current = head;
			int x;
			while (1)
			{
				int flag = 0;
				x = current -> data;
				for (int i =0 ; i < n ; i++)
					if (graph.a[i][x] == 1 && visited[i] == 0)
					{
						flag = 1;
						break;
					}

				if (flag == 1)
					break;

				current = current -> next;
		} 

		//now we have the point in the cycle that have this protrution
		//so find another maximal path

		int currentData = x;
		tale = current;
		struct node* after = current -> next;

		//start to extend the start in one direction
		while (1)
		{
			
			int flag = 0;
			for (int i = 0 ; i < n ; i ++)
				if (graph.a[currentData][i] == 1 && visited[i] == 0)	//if i is adjacent to current vertex and it is adjacent to the vertex i
				{	
				  	flag = 1; 										//indicating such value is found
					currentData = i;									//updating the value of the current
				}

			if (flag == 0)
				break;

			else
			{
				addNodeForward (&tale , currentData);
				visited[currentData] = 1;
			}

		}

	head = after;
	head -> previous = NULL;

	findAndMakeCylce (&graph , &head , &tale);

	}

	//now we have the hamiltonian in the double link list we just have to put that in the graph
	int a[n][n];
	for (int i =0 ; i< n ; i++)
		for (int j = 0 ; j < n ; j++)
			a[i][j] = 0;

	struct node *current = head;
	while (current -> next != head )
	{

		int x = current -> data;
		current = current -> next;
		int y = current -> data;
		a[x][y] = 1;
		a[y][x] = 1;

	}


		
	int x = head -> data;
	current = head -> previous;
	int y = current -> data;
	a[x][y] = 1;
	a[y][x] = 1;

	//now making the graph
	//making the final graph
		FILE *file;
		makeGraph (&graph , file , n , a);

}