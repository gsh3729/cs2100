CC = gcc
OBJS = main.o dll.o

a.out : ${OBJS}
	${CC} ${OBJS}

main.o: main.c
	${CC} -c main.c

dll.o : dll.c
		${CC} -c dll.c

clean:
	\rm a.out *.o *.dot
