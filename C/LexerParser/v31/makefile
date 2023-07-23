CC = gcc
CFLAGS = -g -Wall
TARGET = main

default: p1

p1: main.o
	$(CC) $(CFLAGS) -o p1 main.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	$(RM) p1 *.o