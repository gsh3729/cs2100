//declaring the important structure
	struct Graph
	{
		int vc;
		int **a;
		int graphName[100];
	};


//declaring the important functions
	int readGraph (char filename[] , struct Graph * graph);
	void makeSimpleGraph (struct Graph *graph , FILE *file);

	
