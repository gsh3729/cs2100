//declaring the important structure
	struct Graph
	{
		int vc;
		int **a;
		int graphName[100];
	};


//declaring the important functions
	int readGraph (char filename[] , struct Graph * graph);

//this function prints the graph with the given subgramh cycle in red color
void makeGraph (struct Graph *graph , FILE *file ,int n ,int cycle[][n]);
	




