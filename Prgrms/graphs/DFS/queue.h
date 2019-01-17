
//defining the queue
	struct queue
	{
		int data;
		struct queue * next;

	};



//typedefing the stack queue*
typedef struct queue* Queue;

//declaration of all the important functions
	Queue newQueue ();
	Queue rear(Queue q);
	void enQueue (Queue* q , int x);
	int deQueue (Queue *q);
	int QueueSize (Queue q);
	int QueueisEmpty (Queue q);
	int QueueFront (Queue q);
