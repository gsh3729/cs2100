CC = gcc
OBJS = hamiltonian.o graph.o DoublelinkList.o

a.out : ${OBJS}
	${CC} ${OBJS}

main.o: main.c
	${CC} -c hamiltonian.c

graph.o : graph.c
	${CC} -c graph.c

DoublelinkList.o : DoublelinkList.c
	${CC} -c DoublelinkList.c

clean:
	\rm a.out *.o *.dot