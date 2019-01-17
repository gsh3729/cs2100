//declaring the important structure
	struct Graph
	{
		int vc;
		int **a;
		char graphName[100];
	};


//declaring the important functions
	int readGraph (char filename[] , struct Graph * graph);
	void makeSimpleGraph (struct Graph *graph , FILE *file);

/*
int * DFS_previous (struct Graph * graph ,  int start  );
//this function implements the DFS search starting from the start node

void DFSrecursive (struct Graph *graph , int vertex , int *visited , int *order , int *counter)
//this function do DFS in recursive fashion

int * DFS_order (struct Graph *graph , int start , int *counter);
//this function applies DFS search and returns the order in which they are visited
//input it takes is the graph ; start node ; and counter initialised at zero
*/



	
