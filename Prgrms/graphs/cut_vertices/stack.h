
typedef struct stack* stack;

//Main struct

	struct stack
	{
		int data;
		stack next;
	};
//declaring all the functions

	stack newStack ();
	int stackIsEmpty (stack stk);
	void stackPush (stack* stk , int x);
	int stackPop (stack* stk);
	int  stackTop (stack stk);
