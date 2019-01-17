//declaring the important structure
	struct Graph
	{
		int vc;
		int **a;
		int graphName[100];
	};


//declaring the important functions
	int readGraph (char filename[] , struct Graph * graph);
	

int readGraph (char filename[] , struct Graph *graph)
//This function takes the filename as the input and then returns wether file is there or not
{
	//asking for the name of the input file and opening it
		FILE *file ;
		file = fopen (filename , "r");

		if (file == 0)
		{
			printf("Error in opening the file \n");
			return 0;
		}

	//scanning the initial details
		char temp[1000];
		int success ;
		success = fscanf(file , "%s" , temp);
		success = fscanf(file , "%s" , temp);

		success = fscanf(file, "%d" , &graph -> vc);
		int n = graph -> vc;

	//declaration of the matrix using malloc
		graph ->a = (int **)malloc (n * sizeof (int *));
		for (int i =0 ; i<n ; i++)
		{
			graph->a[i] = (int*)malloc (n * sizeof(int));
		}

	//reading the file
		for (int i =0 ; i< n ; i++)
		{
			success = fscanf(file , "%s" , temp);

			for (int j =0 ; j < n ; j++)
			{
				graph ->a[i][j] = temp[j] - '0';
			}
		}

	//closing the file
	fclose (file);
	return 1;
}

