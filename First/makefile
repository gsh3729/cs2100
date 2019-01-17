CC = gcc
OBJS = main.o queue.o readWriteBfs.o 

a.out : ${OBJS}
	${CC} ${OBJS}

main.o: main.c
	${CC} -c main.c

queue.o : queue.c
	${CC} -c queue.c

readWriteBfs.o : readWriteBfs.c
	${CC} -c readWriteBfs.c

clean:
	\rm a.out *.o *.dot
