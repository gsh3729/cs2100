CC = gcc
OBJS = main.o graph.o queue.o stack.o DoublelinkList.o

a.out : ${OBJS}
	${CC} ${OBJS} -g

main.o: main.c
	${CC} -c main.c -g

graph.o : graph.c
	${CC} -c graph.c -g

queue.o : queue.c
	${CC} -c queue.c -g

stack.o : stack.c
	${CC} -c stack.c -g

DoublelinkList.o : DoublelinkList.c
	${CC} -c DoublelinkList.c -g

clean:
	\rm a.out *.o *.dot
