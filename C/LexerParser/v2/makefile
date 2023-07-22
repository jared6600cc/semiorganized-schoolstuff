CC = gcc
CFLAGS = -g -Wall
TARGET = main

default: p3

p3: main.o lexer.o parser.o
	$(CC) $(CFLAGS) -o p3 main.o lexer.o parser.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

lexer.o: lexer.c lexer.h
	$(CC) $(CFLAGS) -c lexer.c

parser.o: parser.c parser.h
	$(CC) $(CFLAGS) -c parser.c

clean:
	$(RM) p3 *.o