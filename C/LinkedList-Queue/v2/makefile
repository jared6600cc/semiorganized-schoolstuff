edit : main.o queue.o
	gcc -o edit main.o queue.o -lm 
queue.o : queue.c defs.h queue.h
	gcc -c -Wall queue.c
main.o : main.c defs.h queue.h
	gcc -c -Wall main.c
clean :
	rm edit main.o queue.o




