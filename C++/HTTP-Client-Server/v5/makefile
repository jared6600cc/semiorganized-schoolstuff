CC = g++
CFLAGS = -g -Wall
TARGET = main

default: meow

meow: main.o
	$(CC) $(CFLAGS) -o meow main.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

clean:
	$(RM) meow *.o