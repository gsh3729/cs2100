CC = gcc
OBJS = main.o readWrite.o 

a.out : ${OBJS}
	${CC} ${OBJS}

main.o: main.c
	${CC} -c main.c

readWrite.o : readWrite.c
	${CC} -c readWrite.c

clean:
	\rm a.out *.o *.dot
