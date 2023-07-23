CC = gcc
CFLAGS = -g -Wall
TARGET = main

default: p1

p1: main.o lexer.o parser.o symbolTable.o
	$(CC) $(CFLAGS) -o p1 main.o lexer.o parser.o symbolTable.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

lexer.o: lexer.c lexer.h
	$(CC) $(CFLAGS) -c lexer.c

parser.o: parser.c parser.h
	$(CC) $(CFLAGS) -c parser.c
	
symbolTable.o: symbolTable.c
	$(CC) $(CFLAGS) -c symbolTable.c

clean:
	$(RM) p1 *.o