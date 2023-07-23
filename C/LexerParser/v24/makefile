CC = gcc
CFLAGS = -g -Wall
TARGET = main

default: p1

p1: main.o lexer.o parser.o
	$(CC) $(CFLAGS) -o p1 main.o lexer.o parser.o
	
lexer.o: lexer.c lexer.h
	$(CC) $(CFLAGS) -c lexer.c
	
parser.o: parser.c parser.h
	$(CC) $(CFLAGS) -c parser.c

main.o: main.c
	$(CC) $(CFLAGS) -c main.c
	
clean:
	$(RM) p1 *.o