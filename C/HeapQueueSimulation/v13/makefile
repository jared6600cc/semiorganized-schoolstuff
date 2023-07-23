proj2 : main.o queue.o simulation.o
	gcc -o proj2 main.o queue.o simulation.o -lm
queue.o : queue.c queue.h
	gcc -c -Wall queue.c
simulation.o : simulation.c simulation.h
	gcc -c -Wall simulation.c
main.o : main.c
	gcc -c -Wall main.c
clean :
	rm proj2 main.o queue.o simulation.o