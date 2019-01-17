CC = gcc
OBJS = main.o graph.o queue.o

a.out : ${OBJS}
	${CC} ${OBJS}

main.o: main.c
	${CC} -c main.c

graph.o : graph.c
	${CC} -c graph.c

queue.o : queue.c
	${CC} -c queue.c

clean:
	\rm a.out *.o *.dot
