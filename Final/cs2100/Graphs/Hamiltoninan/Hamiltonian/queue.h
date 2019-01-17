


typedef struct queue //structure declaration
{
	char data;
	struct queue *next;
}queue;


void enQueue(queue **front,queue **rear,int value);//declaring function prototypes
int deQueue(queue **front,queue **rear);
int isEmpty(queue **front);
