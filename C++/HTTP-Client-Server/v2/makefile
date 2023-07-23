CC = g++
CFLAGS = -g -Wall
TARGET = main

default: meow

meow: main.o Server.o Socket.o
	$(CC) $(CFLAGS) -o meow main.o Server.o Socket.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

Server.o: Server.cpp
	$(CC) $(CFLAGS) -c Server.cpp

Socket.o: Socket.cpp
	$(CC) $(CFLAGS) -c Socket.cpp

clean:
	$(RM) meow *.o