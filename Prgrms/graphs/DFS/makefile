CC = gcc
OBJS = main.o graph.o queue.o stack.o

a.out : ${OBJS}
	${CC} ${OBJS} -g

main.o: DFS_recursion.c
	${CC} -c DFS_recursion.c -g

graph.o : graph.c
	${CC} -c graph.c -g

queue.o : queue.c
	${CC} -c queue.c -g

stack.o : stack.c
	${CC} -c stack.c -g

clean:
	\rm a.out *.o *.dot
