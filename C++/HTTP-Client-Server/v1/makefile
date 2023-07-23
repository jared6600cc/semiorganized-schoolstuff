CC = g++
CFLAGS = -g -Wall
all: server client

server: HTTPServer.o
	$(CC) $(CFLAGS) -o server HTTPServer.o

HTTPServer.o: HTTPServer.cpp
	$(CC) $(CFLAGS) -c HTTPServer.cpp

client: HTTPClient.o
	$(CC) $(CFLAGS) -o client HTTPClient.o

HTTPClient.o: HTTPClient.c
	$(CC) $(CFLAGS) -c HTTPClient.c

clean:
	$(RM) P2 *.o *.exe