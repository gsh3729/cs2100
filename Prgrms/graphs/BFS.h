int BFS (struct Graph *graph , int start , int goal)
//this function takes the graph , root value and the goal to see wether both are connected or not
{
	
	int n = graph -> vc;
	Queue Q = newQueue ();
	int visited[n];

	//making all the nodes unvisited
	for (int i =0 ; i < n ; i++)
		visited[i] = 0;


	enQueue (&Q , start);
	visited[start] = 1;

	while (QueueisEmpty (Q) == 0)
	{
		int vertex = deQueue (&Q);

		//checking all the neighbours
		for (int i =0 ; i < n ; i++)
		{
			if (graph -> a[vertex][i] == 1)
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

	
	//if the return value is found then return it
	return visited[goal];

}
