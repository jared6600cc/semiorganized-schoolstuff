CC = g++
CFLAGS = -g -Wall
TARGET = main

default: P1

P1: main.o
	$(CC) $(CFLAGS) -o P1 main.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

clean:
	$(RM) P1 *.o