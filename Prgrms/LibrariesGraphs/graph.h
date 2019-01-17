//declaring the important structure
	struct Graph
	{
		int vc;
		int **a;
		char graphName[100];
	};


//declaring the important functions
	int readGraph (char filename[] , struct Graph * graph);
	//reads the graph with the given file name and put all the information in the graph

	void makeSimpleGraph (struct Graph *graph , FILE *file);
	//makes the dot of the given graph


int * DFS_previous (struct Graph * graph ,  int start  );
//this function implements the DFS search starting from the start node

void DFSrecursive (struct Graph *graph , int vertex , int *visited , int *order , int *counter);
//this function do DFS in recursive fashion

int * DFS_order (struct Graph *graph , int start , int *counter);
//this function applies DFS search and returns the order in which they are visited
//input it takes is the graph ; start node ; and counter initialised at zero

	
				int inside (int *array , int x , int distance);
				//this function is intermediate ;
				//this function tells wether x is in the shortest array or not
				//if it is there then it returns the index where it is in the array

	void makeGraph_RED_PATH (struct Graph *graph , FILE *file , int *path , int distance);
	//takes the Graph ; file pointer ; asks for the name of the file on its own;
	//takes the path in the form of array ; and the length of the path or distance between the vertices between which the path is drawn
	//makes the graph_with the given path as red

				char* chooseColor (int components);
				//this function returns character name of the color depending on the integer that is the representative of the color

	void color_graph (struct Graph *graph , FILE *file , int *colors);
	//This function takes the graph , name of the file , and the array of the color
	//it produces the dot file in which all the nodes are colored depending on the color array

	
				int allAreVisited (int * visited , int n);
				//this function returns 1 if all are visited

				//intermediate functions
				int minVertexSet (int * wTree , int *visited , int n);
				//returns vertex that is unvisited and have the min distance

	int * shortest_in_weighted_graph (struct Graph *graph , int start , int goal , int * path , int *distance);
	//this function takes the graph ; start point ; goal vertex ; and returns the shortest path in the weighted graph ; with the distance between them  as length of the path
	//it return the shortest distance of each vertex from the start point i.e. the weighted Tree with respect to the start point
	//if the wTree[goal] ; that means there is no path in between the start and the end vertex


void makeGraph_withSubGraph (struct Graph *graph , FILE *file ,int n ,int cycle[][n]);
//This function takes the output file open it and make the dot file of the graph and also proper colors the edges that are there in the subGraph

int * BFS (struct Graph *graph , int start , int goal , int*distance);
//this function takes the graph , root value and the goal to see wether both are connected or not and returns a path if connected and updates the value of the
//this function is a basic BFS ; it can be used to find out vertex that are visited ; their levels ; and there previous values
//this can also be used to find the path in the unweighted graph