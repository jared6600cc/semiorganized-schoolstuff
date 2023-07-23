CC = gcc
CFLAGS = -g -Wall
TARGET = main

default: lex

lex: main.o lexer.o
	$(CC) $(CFLAGS) -o lex main.o lexer.o
	
lexer.o: lexer.c lexer.h
	$(CC) $(CFLAGS) -c lexer.c
	
main.o: main.c
	$(CC) $(CFLAGS) -c main.c
	
clean:
	$(RM) lex *.o